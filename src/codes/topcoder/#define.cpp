#include<stdio.c>
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
#include<stdlib> // for calloc and malloc
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
struct node{
	int data;
	struct node * next; 

};
graph()
{
    char  a;
    struct node * head = NULL;
    while( scanf("%c", &a) && a != '0'  ){
	     if(head == NULL){
                struct node * newnode = (struct node * )malloc(sizeof(struct node ));
                newnode->data = a - '0';
	        newnode->next = NULL;
		head  =  newnode;
	     }else{
              	struct node * newnode = (struct node * )malloc(sizeof(struct node ));
                newnode->data = a - '0';
		newnode->next = head;
                head  = newnode;
            }
    }
    struct node *temp = head;
    
    while(temp  != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
    
    temp = head;	
    int *ptr = (int *)calloc(10, sizeof(int));
    
    
    temp  =  head;
    while(temp != NULL){
        ptr[temp->data] +=  1;    
		temp = temp->next;
    } 		
    int i = 0;
    while( i  != 10 ){
	printf(" %d \n ",ptr[i] );
        i++;
	 		
    }
}
linkedlist
using namespace std;
int main()
{
  //stringstream ss (stringstream::in | stringstream::out);


}




