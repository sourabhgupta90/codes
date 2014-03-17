#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
int count;
int cr = -1 ; 
int cc = 0 ;
int face = 1;
int steps = 0;
vector< vector<char> > vov;
int check(){
	count = 0;
	for(int t = 0; t < vov.size(); t++){
				for(int k = 0 ; k < vov[t].size(); k++){
				if(vov[t][k]=='G'){count++;};				
		}
	}	
	return count;
}

int pos(int row , int column,int face,int type)
{
	int k ,t;  
	if(type == 1){
			if(face == 1){	
				for( t = vov[row+1].size() - 1 ; t >= 0; t++){
						if(vov[row+1][t]=='G'){break;}
				}
				return t+1;	
			}else{
				for( k = 0 ; k < vov[row+1].size(); k--){
						if(vov[row+1][k]=='G'){break;}				
				}
				return k+1;	
			}
	}else{
			if(face == 1){	
				for( t = vov[row+1].size() - 1 ; t >= 0; t++){
						if(vov[row][t]=='G'){break;}
				}
				return t+1;	
			}else{
				for( k = 0 ; k < vov[row+1].size(); k--){
						if(vov[row][k]=='G'){break;}				
				}
				return k+1;	
			}
	}
	return 0;
}

void changepos(int row,int column,int face)
{
		int temp = pos( row , column, face,0);		
		if(face == 1 && temp){
			face = !face;			
			cr = row + 1;
			cc = temp-1 ;			
			steps +=  (1 + abs(temp - column));
			vov[cr][cc] ='W';			
			while( pos( row ,  column, face,1)){			
								
				steps +=  ( cc - pos( row ,  column, face,1)   );		
				cc = pos( row ,  column, face,1);
				vov[cr][cc] ='W';			
			}
		}else if ( temp) {
			cr = row+1;		
			face = !face;			
			steps +=  (1 + abs(column -temp));			
			cc =  temp - 1;			
			vov[cr][cc] ='W';			
			while(pos( row ,  column, face,1)){		
				steps +=  ( -cc + pos( row ,  column, face,1) );		
				cc = pos( row ,  column, face,1);
				vov[cr][cc] ='W';	
			}		
		}				
}
int main()
{
	int row;
	int column;
	char c;	 
	cin>>row;
	cin>>column;
	
	for(int t = 0; t < row; t++){
		vector<char> temp;		
		for(int k = 0 ; k < column; k++){
			cin>>c;				
			temp.push_back(c);					
		}
		vov.push_back(temp);	
		//temp.clear();
	}
	for(int t = 0; t < row; t++){
		for(int k = 0 ; k < column; k++){
			cout<<vov[t][k]<<"  ";		
		}
		cout<<endl;	
	}
	cout<<"here";  	
	count = check();
	while(count){
		changepos(cr,cc,face);
		count--;
	}	
	return 0;
}
