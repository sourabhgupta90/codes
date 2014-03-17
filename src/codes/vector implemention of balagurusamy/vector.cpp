#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v1; //zero length vector
    vector<int> v2(10); //10 element int vector
    vector<int> v3(v1); //creates vector v3 from v1
    vector<int> v4(5,2); // 5 element vector of 2

    for(int t = 0 ; t < v4.size() ; t++){
        cout<< v4[t]<<endl;


    }
}
