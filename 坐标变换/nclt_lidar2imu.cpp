#include<iostream>
#include<cmath>

 #include<Eigen/Core>
 #include<Eigen/Geometry>

 using namespace std;

 int main(int argc, char** argv){

     Eigen::Matrix3d Rwl;
     Eigen::Matrix3d Rlw;
     Eigen::Matrix3d Rwb;
     Eigen::Matrix3d Rbw;
     Eigen::Matrix3d Rlb;
     Eigen::Matrix3d Rbl;
     Eigen::Vector3d twl;
     Eigen::Vector3d tlw;
     Eigen::Vector3d twb;
     Eigen::Vector3d tbw;
     Eigen::Vector3d tlb;
     Eigen::Vector3d tbl;
     
     Rwl = Eigen::AngleAxisd(-1.583066, Eigen::Vector3d::UnitZ())
            *Eigen::AngleAxisd(0.00289725, Eigen::Vector3d::UnitY())
            *Eigen::AngleAxisd(0.014085, Eigen::Vector3d::UnitX());
    
     Rwb = Eigen::Matrix3d::Identity();

     twl  << 0.002, -0.004, -0.957;
     twb << -0.11, -0.18, -0.71;

     Rlw = Rwl.inverse();
     Rlb = Rlw * Rwb;
     tlw = - Rlw * twl;
     tlb = tlw + twb;

     Rbw = Rwb.inverse();
     Rbl = Rlb.inverse();
     tbw = - Rbw * twb;
     tbl = tbw + twl;

    cout << "Rlb : " << endl << Rlb << endl;
    cout << "tlb : " << endl << tlb << endl;
    cout << "Rbl : " << endl << Rbl << endl;
    cout << "tbl : " << endl << tbl << endl;
 }
 