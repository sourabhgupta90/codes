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
#include<stdio.h>
#include<stdlib.h>
#include <sstream> //for string stream
#define MP(A,B) make_pair(A,B)
#define VI vector<int>
#define f(i,a,b) for( i = a ; i < b ; i++)
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
template<class T> T sqr(T x) {return x*x;}
struct node{
	char nd; //node // first node is the repersentative of list
	int wt;  //node weight with another node  
	
};
int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
const double pi = acos(-1.0);
const double eps = 1e-11;
int N;
char str[100010];
vector< PII > temp1, temp2, ans1, ans2;
int ans0;
int num[10];
int maxS;

void graph(int nfr,int nfc);
vector < vector <struct node> > v;
void makenode(int weight, int se,char rf,char rt);

int main()
{
  int nfc,nfr;
  char citynode;
  cin>> nfc;
  cin >>nfr;
  cin>>citynode;	
  graph(nfr,nfc);
  int missile_range;
  cin>>missile_range;
  return 0;	
    		
}
int search(char rt)
{
	int t;	
	for( t = 0 ; t < v.size() && v[t][0].nd != rt; t++)
	;				
	return t;
	
}

void makenode(int weight, int se,char rf,char rt)
{
    node a;
    if(se == 0 || se == v.size()){		
	a.nd = rf;
	a.wt = 0; 
	vector<struct node> temp;             
	temp.push_back(a);
   	a.nd = rt;
	a.wt = weight; 
    	temp.push_back(a);
        v.push_back(temp);
    }else{
	a.nd = rt;
	a.wt = 0; 
	v[se].push_back(a);
    }
}




