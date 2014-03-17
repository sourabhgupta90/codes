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
#include <sstream> //for string stream

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
const double pi = acos(-1.0);
const double eps = 1e-11;

template<class T> T sqr(T x) {return x*x;}

#define MP(A,B) make_pair(A,B)
#define VI vector<int>
#define f(i,a,b) for( i = a ; i < b ; i++)

int N;
char str[100010];
vector< PII > temp1, temp2, ans1, ans2;
int ans0;
int num[10];
int maxS;

using namespace std;
int main()
{
  //stringstream ss (stringstream::in | stringstream::out);
  int n,a,b;
  cin>>n;
  cin>>a;
  cin>>b;
   
  if(n < a+b || (a == n - 1 && a != 0 )  ){
	cout<<-1;	
        return 0;
  }
  VI v;
  //cout<<"A"<<a<<endl;
  v.push_back(2);
	
  int sum = 0;  
  for(int t = 0 ;  t < v.size() ; t++){
       sum = sum + v[t] ;
  }
  if( b == 0 && a != 0  ){
    v.push_back(2);
  } 
  while(b > 0){
       v.push_back(sum + 1);			
       sum = sum + v[v.size() -1];        
       b -= 1;
   
  }
  int max = v[v.size() -1];
  while(a > 0){
	
   	for(int t = 0 ;  t < v.size() ; t++){
		
                if(max < v[t]){
			max = v[t];		
		}
	}
 	v.push_back(max + 1);	        
        a -= 1;
   
  }
  
  while (n > v.size() ){
      v.push_back(2);
  }
  
  for(int t = 0 ;  t < v.size() ; t++){
      cout<< v[t]<<endl; ;
  } 	
  return 0;	
}
