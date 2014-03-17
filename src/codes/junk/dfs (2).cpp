//specify order of matrix
#include<iostream>
#define size 10

using namespace std;

char mat[size][size];
int time1 = 0;
char colour[size];
int pred[size];
int dis[size];//discoverytime
int f[size];//finishedtime

void dfsvisit(int startstate)
{
		
	colour[startstate] = 'G';
	dis[startstate] = ++time1;	 
	
	for(int t = 0 ; t < size; t++){
		if(mat[startstate][t] == '1'){			
			

			if(colour[t] == 'W'){
				cout<<"startstate : "<<startstate+1 <<" LinK :" <<t+1<<endl;			
							
				pred[t] = startstate;				
				dfsvisit(t);							
			}		
		}	
	}
	
	colour[startstate] = 'B'; //vertex finished
	f[startstate] = ++time1;

}
void dfs(int startstate)
{
	colour[startstate] = 'W';
	pred[startstate] = '\0';
	dfsvisit(startstate);
	
}
int main()
{
	void initializepred();
	void initializecolour();
	void display();
	void graph();
	
	graph();
	initializepred();
	initializecolour();
	display();	
	cout<<"select initial node"<<endl;
	int initialnode;
	cin >> initialnode;
	cout<<"intinal node"<<initialnode<<endl;
	dfs(initialnode);
	return 0;
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
void display()
{
	for(int t = 0 ; t < size ; t++){
		for(int i = 0 ; i < size; i++){
				/*				
				if(mat[t][i] == '1'){
					cout<<"ads"<<endl;				
				}*/
										
				cout<<mat[t][i]<<" ";
		}
		cout<<endl;	
	}
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
