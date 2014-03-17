#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main()
{
    list < vector < int > > store_matrix;
    vector < int > vector_1_inside_matrix;
    vector < int > vector_2_inside_matrix;
    
    int input;
    
    cout<<"enter the odd number"<<endl;
    
    for(int i =0; i<20; i++ ) {
           
            if(i==10){
                      
                      cout<<"now enter the even number "<<endl;           
            }
           
            if(i<10){                                               // for storeing odd number
                     
                     cin >> input;
                     vector_1_inside_matrix.push_back(input);                                                             
            }
            
            else{                                                    // for storeing odd number
                 cin >> input;   
                 vector_2_inside_matrix.push_back(input); 
            
            }
            
    }    
    
    store_matrix.push_back(vector_1_inside_matrix);
    store_matrix.push_back(vector_2_inside_matrix);      
    
     cout<<" the  numbers"<<endl;
    
    
    list < vector < int > >::iterator ListValues; 
    
    for ( ListValues = store_matrix.begin(); ListValues != store_matrix.end(); ++ListValues ){
        
        vector< int >& v = *ListValues;
        
        for(int i =0; i<10; i++ ) {
                
                int sum;
                sum=v[i];
                cout<<sum<<endl;
        }
        cout<<endl;
        v.clear();
        
    }
     
    system("pause");
    
    return 0;
    
}
