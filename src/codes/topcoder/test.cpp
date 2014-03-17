//65 for A 48 for 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{

    for(int t = 0; t < 5 ;t++){

        for(int x = t ; x < 20 ; x++){
                if(x==10) break;
                cout<<" "<<x;
        }
        cout<<endl;
    }
    return 0;
}
