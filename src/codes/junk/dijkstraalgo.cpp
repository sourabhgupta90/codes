//use linked list for vector 
//define infinity =1000
#include<iostream>
#include<vector>
#define size 5

using namespace std;

char mat[size][size];
int pred[size];
char colour[size];
int heapsize;

int singlesourcedis[ size ];  

void dijkstras( int startstate )
{
	singlesourcedis[ startstate ] = 0; 
	while(heapsize != 0 ){
		int min = extractmax()	
	
	}	


}

int  extractmax()
{
	if(heapsize < 1){
		cout<<"error here"<<endl;
	}
	int min = singlesourcedis[0];
	singlsourcedis	
	heapsize -= 1;
	minheapify( 0 );
	return min;
}

void minheapify(int i)
{
	int lowest;	
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if(l <= heapsize && singlesourcedis[l] < singlesourcedis[i] ){
			int lowest = l;
	}
	else{	
		lowest  = i;
	}
	if(r <= heapsize && singlesourcedis[r] < singlesourcedis[l] ){
		lowest = r;
	}	
	if(lowest != i){
		int temp ;
		temp = singlesourcedis[lowest];
		singlesourcedis[lowest] = singlesourcedis[i];
		singlesourcedis[i] = temp;
		minheapify(lowest);
	}
}

void buildmaxheap()
{
	heapsize = size;	
	for(int t  = heapsize - 1 ; t >= 0 ; t--){
		minheapify(t);
	}
}

int main()
{
	void graph();
	void initializepred();	
	void initializecolour();
	void display();		
	void dist();	
	graph();
	display();
	dist();
	buildmaxheap();	
	initializepred();
	initializecolour();
	int startstate;	
	cout<<"enter initialstate"<<endl;	
	cin>>startstate;	
	dijkstras(startstate);
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

void dist()
{
	for(int t = 0 ; t < size ; t++){
		singlesourcedis[t] = 1000 ;	

	}	
}
