#include<iostream>
#include<vector>
#include<fstream>
#include<memory>
//#include <Eigen/Core>
//#include <Eigen/Geometry>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
    std::string srcPath = "/media/gky/新加卷2/gkyhou/gky/kitti/2011_10_03/2011_10_03_drive_0027_sync/oxts/data/*.txt";
    std::vector<cv::String> file_vec;

    std::vector<vector<double>> extract_all;  //提取的所有文件的单行组成的总行

    cv::glob(srcPath, file_vec, false);
    
    for(auto file : file_vec){
        std::vector<double> extract_one;          //提取出来的单行
        //cout << file_name <<endl;
        std::ifstream ifgpsData(file, std::ifstream::in); //std::ifstream::in 以只读的方式打开
        std::string temp;
        vector<string> item; //用于存放所有行数据
        while(getline(ifgpsData, temp)){
            item.push_back(temp);
        }
        for(auto it = item.begin(); it != item.end(); ++it){
            istringstream istr(*it); //作用是将字符串分解为单词
            double str;
            int count = 0; //统计一行数据中单个数据的个数
            while(istr >> str){
                if(count < 6){           //取6列
                    extract_one.push_back(str);
                }
                count++;
            }
        }
        extract_all.push_back(extract_one);
        /*可视化作用
        for (int i = 0; i < extract_all.size(); i++) {
		    for (int j = 0; j < extract_all[i].size(); j++) {
			    cout << extract_all[i][j]<<"\t";
			    if (j == extract_all[i].size() - 1) cout << endl;
		    }
	    }
        */
    }
    /*
    vector<vector<double>> results;
    Eigen::Matrix3f rotation_matrix3;
    for(int i = 0; i < extract_all.size(); ++i){
        rotation_matrix3 = Eigen::AngleAxisd(extract_all[i][5], Eigen::Vector3d::UnitZ()) * 
        Eigen::AngleAxisd(extract_all[i][4], Eigen::Vector3d::UnitY()) * 
        Eigen::AngleAxisd(extract_all[i][3], Eigen::Vector3d::UnitX());
        cout << "rotation matrix3 =\n" << rotation_matrix3 << endl;
    }
    */
   ofstream output("/home/gky/KITTI_odometry_results/GPS00.txt", ios::app); //输出
    for(int i = 0; i < extract_all.size(); ++i){
        for(int j = 0; j < extract_all[i].size(); ++j){
            if(j == extract_all[i].size() - 1){
                output << extract_all[i][j] - extract_all[0][j]  << endl;
            }else{
                output << extract_all[i][j] - extract_all[0][j]<< " ";
            }
        }
    }
    return 0;
}
