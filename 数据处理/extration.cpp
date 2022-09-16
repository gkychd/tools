//C++ 读txt文件
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include<climits>
#include<memory>
using namespace std;

//提取txt中的数据并按列融合
void extractAndmerge(const string filePath, const string timePath, vector<vector<string>>& result)
{
	ifstream myfile(filePath);
    ifstream timefile(timePath);
	string temp;
    string tempTime;
	vector<string> res;
	while (getline(myfile, temp) && getline(timefile, tempTime)) //temp为文件中整一行字符串
	{
        res.push_back(tempTime);//vector<string>的第一个数据为时间戳信息
		stringstream input(temp); //表示要从temp中读取数据
		string out; //读取的数据为字符串类型，即每行的单个字符（本例每行共12个字符）
		while (input >> out) {
			res.push_back(out);
		}
		result.push_back(res);
		res.clear();
	}
    /*
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j]<<"\t";
			if (j == result[i].size() - 1) cout << endl;
		}
	}
    */
	return ;
}


double strTodou(string str){  //将string类型转化为double类型       atof(指针)  括号内必须为指针才能使用
    char* ch = new char[0];
    double d;
    for(int i = 0; i < str.length(); ++i){
        ch[i] = str[i];
    }
    d = atof(ch);
    return d;
}

int main()
{
    string gtFilepath = "/home/gky/KITTI_odometry_results/00.txt";
    string gtTimepath = "/home/gky/KITTI_odometry_results/times.txt";
    string keyFramepath = "/home/gky/KITTI_odometry_results/noloop.txt";
    string keyFrametimepath = "/home/gky/KITTI_odometry_results/noloopT.txt";
    string gtkeyFramepath = "/home/gky/KITTI_odometry_results/00_1505.txt";

    vector<vector<string>> gtPoses;
    vector<vector<string>> keyframePoses;

    extractAndmerge(gtFilepath, gtTimepath, gtPoses);
    extractAndmerge(keyFramepath, keyFrametimepath, keyframePoses);
    /*可视化 编写的过程中调试用
    for (int i = 0; i < gtPoses.size(); i++) {
		for (int j = 0; j < gtPoses[i].size(); j++) {
			cout << gtPoses[i][j]<<"\t";
			if (j == gtPoses[i].size() - 1) cout << endl;
		}
	}
    
    for (int i = 0; i < keyframePoses.size(); i++) {
		for (int j = 0; j < keyframePoses[i].size(); j++) {
			cout << keyframePoses[i][j]<<"\t";
			if (j == keyframePoses[i].size() - 1) cout << endl;
		}
	}
    */
   vector<vector<string>> result;
   for(int i = 0; i < keyframePoses.size(); ++i){
       double delta = 0;
       for(int j = 0; j < gtPoses.size(); ++j){
           delta = strTodou(keyframePoses[i][0]) - strTodou(gtPoses[j][0]);  //计算当前关键帧时刻与gt的时刻的差值，一旦差值小于0说明找到了距离keyframe时刻最近的时间戳
           if(j > 0 && delta <= 0.0){   //这里还需要比较已经找到的时间戳正负变化的临界点前后的差值，取差值小的为gt中的keyframe时间戳
               if(abs(strTodou(keyframePoses[i][0]) - strTodou(gtPoses[j][0])) < abs(strTodou(keyframePoses[i][0]) - strTodou(gtPoses[j - 1][0]))){
                   result.push_back(gtPoses[j]);
               }else{
                   result.push_back(gtPoses[j - 1]);
               }
               break;
           }
       }
   }
   /*可视化 编程的过程中调试用
    for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j]<<"\t";
			if (j == result[i].size() - 1) cout << endl;
		}
	}
    */
    ofstream output(gtkeyFramepath, ios::app); //输出
    for(int i = 0; i < result.size(); ++i){
        for(int j = 1; j < result[i].size(); ++j){
            if(j == result[i].size() - 1){
                output << strTodou(result[i][j])  << endl;
            }else{
                output << strTodou(result[i][j]) << " ";
            }
        }
    }
    return 0;
}
