#include<iostream>
#include<new>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream> //for string stream
#define MP(A,B) make_pair(A,B)
#define VI vector<int>
#define f(i,a,b) for( i = a ; i < b ; i++)

using namespace std;

typedef pair<int,int> PI;

vector< PI > temp1;
vector<vector<int> > v;

bool check(string ringroad, char temp  )
{
        int i;
        f(i,0,ringroad.size()){
                if( ringroad[i] == temp){
                        return true;
                }
        }
        return false;
}

bool stop = false;
string ringroadis;
int flag = 0;
void dfs(string ringroad,int cities)
{
		
				
		//cout<<": st :"<<ringroad<<endl;
		
		if(!stop){
    	  
      for(int t = 0;t < temp1.size() ; t++){
    		   
        if(temp1[t].first == int(ringroad[ringroad.size()-1]) - 48 && ( ringroad.size() == 1 || temp1[t].second != int(ringroad[ringroad.size()-2]) -48 )){
										                   
										//cout<<"temp :"<<temp1[t].first<<endl;										
										//cout<<"ringroad :"<<ringroad<<endl;
										if(check(ringroad,'0' + temp1[t].second) == false){
                        
												char temp = '0'+ temp1[t].second ;
                        dfs(ringroad + temp,cities);
                    }else{
												                        
												stop = true;
                        ringroadis = ringroad;
                    		return ;
										}

        }
        else if(temp1[t].second == int(ringroad[ringroad.size()-1]) - 48 && ( ringroad.size()==1 || temp1[t].first !=int( ringroad[ringroad.size()-2])-48) ){
                //cout<<"here"<<endl;; 
                if(check(ringroad,'0' +temp1[t].first) == false){
                    char temp = '0' + temp1[t].first ;
                    dfs(ringroad + temp,cities);
                }else{
										                    
										stop = true;
                    ringroadis = ringroad;
										return ;                
							}
        }else if(ringroad.size() == cities) {
					
																				
										stop = true;
                    ringroadis = ringroad;
										return ;				
				}

      }
    }
}

void dfssearch(int cities )
{
    string ringroad = "";
    int t = 1 ;
    f(t,1,cities+1){
        ringroad = "";
	      char temp =  t + 48 ;
        ringroad += temp;
	if(stop == false)        
		dfs(ringroad,cities);
    }
}

bool checkdis(vector <int > dis)
{
    int t;
    f(t,0,dis.size())
      if(dis[t] == -1)
            return true;
    return false;
}
vector<int> dis(cities,-1);
/*
void ringroaddis(int cities){
     
		 int t ;    	 
		 
		 
     f(t,0,ringroadis.size()){
          int temp = ringroadis[t] - '0';
          dis[temp-1] = 0;
     }
     f(t,0,cities){
		     cout<<dis[t]<<endl;
     }
		 f(t,0,dis.size()){					
					if(!checkdis(dis))					
							return;					
					if( dis[t] != 0 ){
							f(t,0,dis.size()){							
							if( temp[t]!  )																		
					

					}
		}
		



}
/*/
int cities;
int main()
{
    
    cin>>cities;
    int t,x,y;
		    
		f(t,0,cities){
        cin>>x;
        cin>>y;
        PI pa;
        pa = MP(x,y);
        temp1.push_back(pa);
    }
    dfssearch(cities);
		cout<<ringroadis<<endl;    
		ringroaddis(cities);
		    
		return 0;
}
