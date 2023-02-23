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
    delete[] ch;//之前没有加delete 导致出错 大坑
    return d;
}

int main()
{
    string gtFilepath = "/home/gky/slam_results/kitti/是否添加地面约束对比/loop/0.15间隔/patchwork/09/09.txt";//数量较多的位姿
    string gtTimepath = "/home/gky/slam_results/kitti/是否添加地面约束对比/loop/0.15间隔/patchwork/09/times.txt";
    string keyFramepath = "/home/gky/slam_results/kitti/是否添加地面约束对比/loop/0.15间隔/patchwork/09/add_ground_poses.txt";//数量较少的位姿
    string keyFrametimepath = "/home/gky/slam_results/kitti/是否添加地面约束对比/loop/0.15间隔/patchwork/09/add_ground_times.txt";
    string gtkeyFramepath = "/home/gky/slam_results/kitti/是否添加地面约束对比/loop/0.15间隔/patchwork/09/09_791.txt";

    vector<vector<string>> gtPoses;
    vector<vector<string>> keyframePoses;

    extractAndmerge(gtFilepath, gtTimepath, gtPoses);
    extractAndmerge(keyFramepath, keyFrametimepath, keyframePoses);

    /*
    //可视化 编写的过程中调试用
    for (int i = 0; i < gtPoses.size(); i++) {
		for (int j = 0; j < gtPoses[i].size(); j++) {
			cout << gtPoses[i][j]<<"\t";
			if (j == gtPoses[i].size() - 1) cout << endl;
		}
	}
    */
    /*
    for (int i = 0; i < keyframePoses.size(); i++) {
		for (int j = 0; j < keyframePoses[i].size(); j++) {
			cout << keyframePoses[i][j]<<"\t";
			if (j == keyframePoses[i].size() - 1) cout << endl;
		}
	}
    */
   //用以下方法时，当数据量较少的那组的最后一个数据的时间戳大于  数据量较多那组的最后一个数据的时间戳时，最终得到的组的位姿数量会少一个
   //也就是数据较少的那组的最后一组数据没有在数据量较大组中找到对应的数据。要进行比较的话，数据数量得相同，因此将数据较少组的最后一个数据剔除
   //举个例子就是  A组：503个数据，B组：502个数据，通过该程序得到C组：501个数据，这时在进行BC比较时，剔除B组的最后一个数据进行比较。
   vector<vector<string>> result;
   for(int i = 0; i < keyframePoses.size(); ++i){
       double delta = 0;
       for(int j = 0; j < gtPoses.size(); ++j){
           delta = strTodou(keyframePoses[i][0]) - strTodou(gtPoses[j][0]);  //计算当前关键帧时刻与gt的时刻的差值，一旦差值小于0说明找到了距离keyframe时刻最近的时间戳
           /*
            if(i == 8){
               std::cout << "strTodou(keyframePoses[i][0]) - strTodou(gtPoses[j][0]) = " << strTodou(keyframePoses[i][0]) << " - " << strTodou(gtPoses[j][0]) << std::endl;
               std::cout << "delta: " << delta << ", " << "j: " << j << std::endl;
           }
           */

           /*
           if(i == 9){
               std::cout << "strTodou(keyframePoses[i][0]) - strTodou(gtPoses[j][0]) = " << strTodou(keyframePoses[i][0]) << " - " << strTodou(gtPoses[j][0]) << std::endl;
               std::cout << "delta: " << delta << ", " << "j: " << j << std::endl;
           }
           */
            /*
            if(i == 13){
               std::cout << "strTodou(keyframePoses[i][0]) - strTodou(gtPoses[j][0]) = " << strTodou(keyframePoses[i][0]) << " - " << strTodou(gtPoses[j][0]) << std::endl;
               std::cout << "delta: " << delta << ", " << "j: " << j << std::endl;
           }
           */

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
   /*
   //可视化 编程的过程中调试用
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

/*
    ofstream output2("/home/gky/slam_results/kitti/是否添加地面约束对比/loop/0.09间隔/no_gps/add_ground2.csv", ios::app);
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            if(j == result[i].size() - 1){
                output2 << strTodou(result[i][j])  << endl;
            }else{
                output2 << strTodou(result[i][j]) << ",";
            }
        }
    }

    ofstream output3("/home/gky/slam_results/kitti/是否添加地面约束对比/loop/0.09间隔/no_gps/add_ground.csv", ios::app);
    for(int i = 0; i < gtPoses.size(); ++i){
        for(int j = 0; j < gtPoses[i].size(); ++j){
            if(j == gtPoses[i].size() - 1){
                output3 << strTodou(gtPoses[i][j])  << endl;
            }else{
                output3 << strTodou(gtPoses[i][j]) << ",";
            }
        }
    }
*/
    return 0;
}
