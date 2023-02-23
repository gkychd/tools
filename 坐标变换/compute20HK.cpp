#include<iostream>
#include<cmath>
using namespace std;

#include<Eigen/Core>
#include<Eigen/Geometry>

int main(int argc, char **argv){

    Eigen::Matrix3d Rcl;
    Eigen::Matrix3d Rlc;
    Eigen::Matrix3d Rli;
    Eigen::Matrix3d Ril;
    Eigen::Matrix3d Rci;
    Eigen::Matrix3d Ric;

    Eigen::Vector3d tcl;
    Eigen::Vector3d tlc;
    Eigen::Vector3d tli;
    Eigen::Vector3d til;
    Eigen::Vector3d tci;
    Eigen::Vector3d tic;

    Ric <<  9.9934608718980233e-01, -1.5715484428488590e-02,-3.2564114721728155e-02,
           3.2359037356803094e-02, -1.3131917124154624e-02,9.9939003669937865e-01,
           -1.6133527815482926e-02, -9.9979026615676858e-01,-1.2614792047622947e-02;
        
    tic << -1.7434527332030676e-02, 1.7171139776467173e-01, -4.5251036141047592e-02;

    Ril << 1, 0, 0,
                0, 1, 0,
                0, 0, 1;

    til << 0, 0, 0;

    Rci = Ric.inverse();
    Rcl = Rci * Ril;
    tci =  - Rci * tic;
    tcl = tci + Rci * til;

    Eigen::Vector3d Rcl_rpy = Rcl.eulerAngles(2, 1, 0);


    cout << "tcl : " << endl << tcl << endl;

    cout << "Rcl_rpy -> yaw、pitch、roll：" << Rcl_rpy.transpose() << endl;

}