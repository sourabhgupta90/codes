#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> v;
string ht ;
int count = 0;;
int dp(string s)
{
    ht = s;
    for( int i = 0 ; i < ht.size() - 1 ; i++){
        j = 0;            
        string temp =  ht.substr(i,1) + ht.substr(i+1,1);    
        cout<<"ele: "<<temp<<endl;
        for( int j = 0 ; j < v.size() ; j++){
                if(temp == v[j]){
                    if(){
                            ht = ht.substr(0,i) + ht.substr( i+1,s.size()-i);                 
                            cout<<"HT"<<ht<<endl;
                            i-=1;count++;
                    }
                    break;
                }
        }               
    }
    
}
int main()
{
    
    int np;
    getline(cin,ht);
    cin>>np;
    for(int i = 0 ; i < np ; i++){
        string temp;
        cin>>temp;
        v.push_back(temp);
        temp =  temp.substr(1,1) + temp.substr(0,1);  
 		v.push_back(temp);
    }
    dp(ht);
    cout<<"count: "<<count<<endl;
    return 0;
}
