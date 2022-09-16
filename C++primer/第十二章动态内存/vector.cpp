#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<string> v1;
   // cout << "before action: v1 = " << v1 << endl;
    
        {
            vector<string> v2 = {"a", "an"};
            v1 = v2;
        }       //cout << "v2 = " << v2 << endl;
    
    cout << v1 << endl;
    //cout << "v2 = " << v2 << endl;
    return 0;
}