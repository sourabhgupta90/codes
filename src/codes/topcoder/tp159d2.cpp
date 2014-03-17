#include<string>
#include<iostream>
using namespace std;
vector <int> Sets::inter(vector<int> a,vector <int> b ){
    int bi=0,ai = 0;
	vector<int> store;
    while(ai !=  a.size() && bi != b.size()){
        if(b[bi]<a[ai]){
                //store.push(b[bi]);
                bi++;
        }else if(b[bi]>a[ai]){
                //store.push(a[ai]);
                ai++;
        }else{
                store.push_back(b[bi]);
                bi++;ai++;
        }
    }


    return store;
}
vector <int> Sets::unio(vector<int> a,vector <int> b ){
    int bi=0,ai = 0;
	vector<int> store;
    while(ai !=  a.size() && bi != b.size()){
        if(b[bi]<a[ai]){
                store.push_back(b[bi]);
                bi++;
        }else if(b[bi]>a[ai]){
                store.push_back(a[ai]);
                ai++;
        }else{
                store.push_back(b[bi]);
                bi++;ai++;
        }
    }
    if(ai != a.size()){
        while(ai < a.size() ){
            store.push_back(a[ai]);
            ai++;
        }
    }else if (bi != b.size()){
        while(bi < b.size() ){
            store.push_back(b[bi]);
            bi++;
        }
    }
    return store;
}

vector <int> Sets::differ(vector<int> a,vector <int> b ){
    vector<int> store;
    int bi=0,ai = 0;
    while(ai !=  a.size() && bi != b.size()){
        if(b[bi]<a[ai]){
                store.push_back(b[bi]);
                bi++;
        }else if(b[bi]>a[ai]){
                store.push_back(a[ai]);
                ai++;
        }else{
                //store.push(b[bi]);
                bi++;ai++;
        }
    }
    if(ai != a.size()){
        while(ai < a.size() ){
            store.push_backa[ai]);
            ai++;
        }
    }else if (bi != b.size()){
        while(bi < b.size() ){
            store.push_back(b[bi]);
            bi++;
        }
    }
    return store;
}


vector <int> Sets::operate(vector <int> a, vector <int> b, string op) {


    vector<int> si;
    vector<int> su;
    vector<int> sd;

    sort(a.begin(),a.end());
    sort(a.begin(),b.end());
    if(op[0]=='I'){
            si=inter(a,b);return si;
    }else if(op[0]=='U'){
            su=unio(a,b);return su;
    }else{
            sd = differ(a,b);
            return sd;
    }
}
