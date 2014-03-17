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
#define I int
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
        //char i = 49;
        int i = putchar ('A');
        cout<<i<<endl;



}
