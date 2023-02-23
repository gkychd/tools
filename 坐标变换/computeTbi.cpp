#include<iostream>
#include<cmath>
using namespace std;

#include<Eigen/Core>
#include<Eigen/Geometry>

int main(int argc, char **argv){
    //for 2011_09_30
    Eigen::Matrix3d Rcl;
    Eigen::Matrix3d Rlc;
    Eigen::Matrix3d Rli;
    Eigen::Matrix3d Rci;
    Eigen::Matrix3d Ric;

    Eigen::Vector3d tcl;
    Eigen::Vector3d tlc;
    Eigen::Vector3d tli;
    Eigen::Vector3d tci;
    Eigen::Vector3d tic;

    //for 2011_10_30
    Eigen::Matrix3d Rc2l;
    Eigen::Matrix3d Rlc2;
    Eigen::Matrix3d Rc2i;
    Eigen::Matrix3d Ric2;

    Eigen::Vector3d tc2l;
    Eigen::Vector3d tlc2;
    Eigen::Vector3d tc2i;
    Eigen::Vector3d tic2;
    Eigen::Vector3d til;

    tc2l << -1.377769e-02, -5.542117e-02, -2.918589e-01;
    Rc2l << 7.967514e-03, -9.999679e-01, -8.462264e-04,
                    -2.771053e-03, 8.241710e-04, -9.999958e-01,
                    9.999644e-01, 7.969825e-03, -2.764397e-03;

    tcl << -7.137748e-03, -7.482656e-02, -3.336324e-01;
    tli << -8.086759e-1, 3.195559e-1, -7.997231e-1;
    //Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    Rcl << 7.027555e-03, -9.999753e-01, 2.599616e-05,
                -2.254837e-03, -4.184312e-05, -9.999975e-01,
                9.999728e-01, 7.027479e-03, -2.255075e-03;
                
    Rli << 9.999976e-01, 7.553071e-04, -2.035826e-03, 
            -7.854027e-04, 9.998898e-01, -1.482298e-02, 
            2.024406e-03, 1.482454e-02, 9.998881e-01;

    //for 2011_09_30
    Rci = Rcl * Rli;
    tci = tcl + Rcl * tli;
    Ric = Rci.inverse();
    tic = - Ric * tci;
    Rlc = Rcl.inverse();
    tlc = - Rlc * tcl;

    //for 2011_10_30
    Rlc2 = Rc2l.inverse();
    Ric2 = Rli.inverse() * Rc2l.inverse();
    til = - Rli.inverse() * tli;
    tlc2 = - Rlc2 * tc2l;
    tic2 = til + Rli.inverse() * tlc2;

    //for 2011_09_30
    Eigen::Vector3d Rci_rpy = Rci.eulerAngles(2, 1, 0);
    Eigen::Vector3d Rcl_rpy = Rcl.eulerAngles(2, 1, 0);
    Eigen::Vector3d Rli_rpy = Rli.eulerAngles(2, 1, 0);
    Eigen::Vector3d Rlc_rpy = Rlc.eulerAngles(2, 1, 0);

    //for 2011_10_30
    Eigen::Vector3d Rc2l_rpy = Rlc.eulerAngles(2, 1, 0);
    //for 2011_09_30
    cout << "Rci : " << endl << Rci << endl;
    cout << "tci : " << endl << tci << endl;
    cout << "Ric : " << endl << Ric << endl;
    cout << "tic : " << endl << tic << endl;
    cout << "tlc : " << endl << tlc << endl;
    //for 2011_10_30
    cout << "Ric2 : " << endl << Ric2 << endl;
    cout << "tic2 : " << endl << tic2 << endl;
    cout << "tc2l : " << endl << tc2l << endl;
    //for 2011_09_30
    cout << "Rci_rpy -> yaw、pitch、roll：" << Rci_rpy.transpose() << endl;
    cout << "Rcl_rpy -> yaw、pitch、roll：" << Rcl_rpy.transpose() << endl;
    cout << "Rli_rpy -> yaw、pitch、roll：" << Rli_rpy.transpose() << endl;
    cout << "Rlc_rpy -> yaw、pitch、roll：" << Rlc_rpy.transpose() << endl;
    //for 2011_10_30
    cout << "Rc2l_rpy -> yaw、pitch、roll：" << Rc2l_rpy.transpose() << endl;

}