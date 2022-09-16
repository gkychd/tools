#include<iostream>
#include<cmath>
using namespace std;

#include<Eigen/Core>
#include<Eigen/Geometry>

int main(int argc, char **argv){
    Eigen::Matrix3d R;
    Eigen::Matrix3d Rbw;
    Eigen::Matrix3d Rbc1;
    Eigen::Matrix3d Rbc2;
    Eigen::Matrix3d Rwc_true;
    Eigen::Vector3d tbw;
    Eigen::Vector3d twb;
    Eigen::Vector3d twc1;
    Eigen::Vector3d twc2;
    Eigen::Vector3d tbc1;
    Eigen::Vector3d tbc2;
    tbc1 << -0.04555446, 0.00593308, -0.01595266;
    tbc2 << 0.074, 0.0061, -0.016;
    tbw << 0.015, 0.039, 0.2017;
    //Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    R << 0,0, 1,
            -1, 0, 0,
            0, -1, 0;
    Rbc1 << 0.99997637,  0.0041976, 0.00544467,
           0.00419222, -0.99999071,  0.00099798,
           0.00544881, -0.00097513, -0.99998468;
    Rbw << 0, -1, 0,  
                     -0.7071, 0, 0.7071, 
                      -0.7071, 0, -0.7071;
    Rbc2 << 0.99998763,  0.00385844, -0.00313859,
          0.00384364, -0.99998153, -0.00470773,
         -0.0031567,   0.0046956,  -0.99998399;
    Eigen::Matrix3d R_inv = R.transpose();
    Eigen::Matrix3d Rwb = Rbw.transpose();
    Eigen::Matrix3d Rwc1 = Rwb * Rbc1;
    Eigen::Matrix3d Rwc2 = Rwb * Rbc2;
    twb = - Rwb * tbw;
    twc2 = twb + Rwb * tbc2;
    twc1 = twb + Rwb * tbc1;
    cout << "twc1: " << twc1 << endl;
    cout << "twc2: " << twc2 << endl;
    cout << "R: " << endl << R << endl;
    cout << "R_inv: " << endl << R_inv << endl;
    cout << "Rwb: " << endl << Rwb << endl;
    cout << "Rbc2: " << endl << Rbc2 << endl;
    cout << "Rwc2:" << endl << Rwc2 << endl;
    cout << "Rbw: " << endl << Rbw << endl;
    Eigen::Vector3d euler_angles0 = R.eulerAngles(0, 1, 2);//其中R的组成为RxRyRz 表示w系先绕x轴旋转roll，再绕y轴旋转pitch，最后绕z轴旋转yaw得到b系
    Eigen::Vector3d euler_angles00 = R_inv.eulerAngles(2, 1, 0);
    Eigen::Vector3d euler_angles1 = Rwb.eulerAngles(2, 1, 0);//ZYX：表示w系先绕z轴旋转yaw，再绕y轴旋转pitch，最后绕x轴旋转roll得到b系 
    Eigen::Vector3d euler_angles2 = Rbc2.eulerAngles(2, 1, 0);
    Eigen::Vector3d euler_angles3 = Rwc2.eulerAngles(2, 1, 0);
    Eigen::Vector3d euler_angles4 = Rbw.eulerAngles(2, 1, 0);
    cout << "R -> roll、pitch、yaw：" << euler_angles0.transpose() << endl;//transpose()表示输出行向量
    cout << "R_inv -> yaw、pitch、roll：" << euler_angles00.transpose() << endl;
    cout << "Rwb -> yaw、pitch、roll：" << euler_angles1.transpose() << endl;
    cout << "Rbc2 -> yaw、pitch、roll：" << euler_angles2.transpose() << endl;
    cout << "Rwc -> yaw、pitch、roll：" << euler_angles3.transpose() << endl;
    cout << "Rbw -> yaw、pitch、roll：" << euler_angles4.transpose() << endl;
}