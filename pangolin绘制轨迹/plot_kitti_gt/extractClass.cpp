#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <Eigen/Core>
#include <Eigen/Geometry>

class ReadAndWrite
{
public:

    ReadAndWrite(std::string readPath)
        : m_readPath(readPath)
    {
        std::cout << "class build success and path is: " << readPath << std::endl;
    }

    ReadAndWrite()
    {
    }

    ~ReadAndWrite()
    {
    }

    void readPose();//读取输出的kitti形式的位姿，保存至成员变量m_allPoses

    void R_to_q();//位姿由旋转矩阵 转变为 四元数 保存旋转矩阵和四元数 m_R_all、m_q_all
    void save_xyz();//保存xyz至成员变量m_xyz
    void save_xyzq();//保存xyzq至成员变量m_xyzq   四元数

    void writePose_xyzq(const std::string& writePath);//输出xyzq至目标路径
    void writePose_xyz(const std::string& writePath);//输出xyz至目标路径

    double strTodou(std::string str);

private:

    std::string m_readPath;
    std::vector<std::vector<std::string>> m_allPoses;
    std::vector<Eigen::Matrix3d> m_R_all;
    std::vector<Eigen::Quaterniond> m_q_all;
    std::vector<std::vector<double>> m_xyz;
    std::vector<std::vector<double>> m_xyzq;
};

void ReadAndWrite::save_xyz(){
    for(int i = 0; i < m_allPoses.size(); ++i){
        std::vector<double> xyz_temp;
        for(int j = 0; j < m_allPoses[0].size(); ++ j){
            if(j == 3 || j == 7 || j == 11){
                xyz_temp.push_back(strTodou(m_allPoses[i][j]));
            }else{
                continue;
            }
        }
        m_xyz.push_back(xyz_temp);
    }
}

void ReadAndWrite::save_xyzq(){
    for(int i = 0; i < m_xyz.size(); ++i){
        std::vector<double> xyzq_temp;
        for(int j = 0; j < m_xyz[0].size(); ++j){
            xyzq_temp.push_back(m_xyz[i][j]);
        }
        xyzq_temp.push_back(m_q_all[i].x());
        xyzq_temp.push_back(m_q_all[i].y());
        xyzq_temp.push_back(m_q_all[i].z());
        xyzq_temp.push_back(m_q_all[i].w());
        m_xyzq.push_back(xyzq_temp);
    }
}

void ReadAndWrite::readPose(){
    std::ifstream file(m_readPath);
    std::string temp;
    std::vector<std::string> res;
    while(getline(file, temp)){
        std::stringstream input(temp);
        std::string out;
        while(input >> out){
            res.push_back(out);
        }
        m_allPoses.push_back(res);
        res.clear();
    }
}

void ReadAndWrite::writePose_xyz(const std::string& writePath){
    std::ofstream output(writePath, std::ios::app);
    for(int i = 0; i < m_allPoses.size(); ++i){
        for(int j = 0; j < m_allPoses[0].size(); ++j){
            if(j == m_allPoses[0].size() - 1){
                output << strTodou(m_allPoses[i][j]) << std::endl;
            }else if(j == 3 || j == 7){
                output << strTodou(m_allPoses[i][j]) << " ";
            }else{
                continue;
            }
        }
    }
}

double ReadAndWrite::strTodou(std::string str){  //将string类型转化为double类型       atof(指针)  括号内必须为指针才能使用
    char* ch = new char[0];
    double d;
    for(int i = 0; i < str.length(); ++i){
        ch[i] = str[i];
    }
    d = atof(ch);
    return d;
}

void ReadAndWrite::R_to_q(){

    for(int i = 0; i < m_allPoses.size(); ++i){
        Eigen::Matrix3d R_temp;
        Eigen::Quaterniond q_temp;
        std::vector<double> temp;
        for(int j = 0; j < m_allPoses[0].size(); ++ j){
            if(j == 3 || j == 7 || j == 11){
                continue;
            }else{
                temp.push_back(strTodou(m_allPoses[i][j]));
            }
        }
        R_temp << temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8];
        q_temp = R_temp;
        m_R_all.push_back(R_temp);
        m_q_all.push_back(q_temp);
    }
}

void ReadAndWrite::writePose_xyzq(const std::string& writePath){
    std::ofstream output(writePath, std::ios::app);
    for(int i = 0; i < m_xyzq.size(); ++i){
        for(int j = 0; j < m_xyzq[0].size(); ++j){
            if(j == m_xyzq[0].size() - 1){
                output << m_xyzq[i][j] << std::endl;
            }else{
                output << m_xyzq[i][j] << " ";
            }
        }
    }
}



int main(int argc, char** argv){

    std::string trajectory_file = "/media/gky/Elements2/data_all/kitti数据集/真值/dataset/poses/09.txt";
    std::string trajectory_xyz_file = "/media/gky/Elements2/data_all/kitti数据集/真值/dataset/poses/09_xyz.txt";
    std::string trajectory_xyzq_file = "/media/gky/Elements2/data_all/kitti数据集/真值/dataset/poses/09_xyzq.txt";

    ReadAndWrite rw(trajectory_file);
    rw.readPose();
    rw.writePose_xyz(trajectory_xyz_file);
    rw.save_xyz();
    rw.R_to_q();
    rw.save_xyzq();
    rw.writePose_xyzq(trajectory_xyzq_file);

    return 0;
}