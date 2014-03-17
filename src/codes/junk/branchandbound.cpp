//specify the order of matrixsss 
#include<iostream>
#define size 11
 
using namespace std;

char mat[size][size];
int bound = 5;

char colour[size];
int pred[size];

void dfsvisit(int startstate,int cost)
{
	
	colour[startstate] = 'G';
	if(cost+1<bound){	
		for(int t = 0 ; t < size ; t++){
		
			if( mat[startstate][t] == 'G' ){
				bound = cost + 1;
				cout<<"GoalState  : "<<startstate+1 <<" LinK :" <<t+1<<" cost : "<<cost+1<<endl;			
			}
			if( mat[startstate][t] == '1' ){
			
				if(colour[t] == 'W'){
					
					cout<<"startstate : "<<startstate+1 <<" LinK :" <<t+1<<" cost : "<<cost+1<<endl;			
					pred[t] = startstate; 				
					dfsvisit(t,cost + 1);			
			
				}
			}
	
		}
	}	
	colour[startstate] = 'B';
}


void dfs(int startstate)
{
	colour[startstate] = 'W';			
	pred[startstate] = '\0';
	int cost = 0;	
	dfsvisit(startstate,cost);
	
}


int main()
{
	void graph();
	void display();	
	void initializecolour();
	void initializepred();	
	initializepred();
	initializecolour();	
	graph();
	display();
	cout<<"select initial node"<<endl;	
	int startstate;	
	cin>>startstate;
		
	dfs(startstate);	
	return 0;
}

void graph()
{	
	char x;
	for(int t = 0 ; t < size ; t++){
		for(int i = 0 ; i < size; i++){
			cin>>x;		
			mat[t][i] = x;
		}
	}
}

void display()
{
	for(int t = 0 ; t < size ; t++){
		for(int i = 0 ; i < size; i++){
					
			cout<<mat[t][i]<<" ";
		}
		cout<<endl;	
	}
}
void initializepred()
{
	for(int t = 0 ; t < size; t++){
		pred[t] = '\0'; 			
	}
}

void initializecolour()
{
	for(int t = 0 ; t < size; t++){
		colour[t] = 'W'; 			
	}
}

