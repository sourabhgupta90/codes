//65 for A 48 for 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int value(char a)
{
    if(a < 60 )
        return a-48;
    else
        return a-55;
}
int main()
{
    string st;cin>>st;
    int stb = 2;
    vector<int>store;

    int posp =st.find("+"),pose=st.find("=");
    string a = st.substr(0,posp),b = st.substr(posp+1,pose-posp-1),c = st.substr(pose+1, st.size() - pose-1);
    cout<<a<<":"<<b<<":"<<c<<endl;
    if(a.size()<b.size())
        swap(a,b);
    cout<<"a"<<a<<"b"<<b<<endl;
    int flag=1;
    int carry = 0;
    for(int x = stb ; x < 20 ; x++){
        for(int t = stb ; t < a.size() ;t++){
                int sum = value(a[a.size()-1-t])+value(b[b.size()-1-t])+carry; ;
                if(sum >= stb ){
                    if( value(c[a.size()-1-t])  == sum%stb ){
                        store.push_back(stb);
                        carry = sum/10;
                    }
                }else{
                    if( value(c[a.size()-1-t]) ==  sum ) store.push_back(stb);
                    else flag=1;
                }
        }
        if (flag == 1){
            break;
        }
    }
    for(int t = 0 ; t < store.size() ; t++)
        cout<<store[t]<<endl;
    return 0;
}
