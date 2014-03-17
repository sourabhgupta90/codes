// wonderful thing abourt dfs is abort its stack ,after pop its element  reaches its present top element of stack, see that  downloaded wab pages 
//5 value for the point  goes into the stack
//just like queue element in bfs

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class algorithm
{    
      private:
              
      public:
             void dfspush (vector < vector < int > > &vm,int startele);        
      
             void bfspush (vector< vector < int > > &vm, int startele ); 
};
void algorithm::dfspush (vector < vector < int > > &vm, int startele )
{
     vector < int > v;     
     stack < int > mystack;
     mystack.push(startele);
     vm[startele][startele]=5;
     while(!mystack.empty())
     {
                            
                            for(int i=0 ; i<5 ; i++ )
                            {
                               if(i==4)
                              {
                                                     v.push_back(mystack.top());
                                                     mystack.pop();
                                                     if(!mystack.empty())
                                                     {
                                                                         startele=mystack.top();
                                                                         break;  
                                                     }
                              }
                               
                               
                              if(vm[startele][i]==1&&vm[i][i]!=5)
                              {
                                                    vm[startele][i]=2;         
                                                    vm[i][startele]=2;      
                                                    mystack.push(i);
                                                    vm[i][i]=5;                                               
                                                    startele=i;
                                                    break; 
                               }
                            }    
     }
     for(int i=0 ; i<v.size(); i++ )
                                         {            
                                                      cout<<"dfs order "<<endl;
                                                      cout<<v[i]<<endl;
                                         }
                                         v.clear();
}
void algorithm::bfspush(vector< vector < int > > &vm , int startele)
{
     
     queue <int> myqueue;
     myqueue.push(startele);
     vector < int > v;
     
     
     vm[startele][startele]=5;
     
     while(!myqueue.empty())
     {
                          for( int i=0 ; i<5; i++ )
                          {
                               if(i==4)
                               {
                                       v.push_back(myqueue.front());
                                       myqueue.pop(); 
                                       if(!myqueue.empty())
                                                     {
                                                                         startele=myqueue.front();
                                                                         break;  
                                                     }
                               } 
                               if(vm[startele][i]==1&&vm[i][i]!=5) 
                               {
                                       myqueue.push(i);
                                       vm[startele][i]=2;
                                       vm[i][startele]=2;                                                      
                                       vm[i][i]=5;
                               } 
                          
                          }
     }    
     cout<<"clear"<<endl;
     for(int i=0 ; i<v.size(); i++ )
     
                                         {            
                                                      cout<<"bfs order "<<endl;
                                                      cout<<v[i]<<endl;
                                         }
                                         v.clear();
}
int main ()
{
    algorithm d1,d2;
    vector <int> v;
    vector < vector <int> > vm;    
    int x,choice,startele;
    for(int i=0; i<4; i++)
    {
            for(int j=0; j<4; j++)
            {
                    cin>>x;
                    v.push_back(x);
            }
            vm.push_back(v);
            v.erase(v.begin(),v.end());                
    }                               
    choice=5;
    
    for( int i=0 ; i<1 ; i++)
    {
                    cout<<"enter your choice "<<endl;
                    cout<<"for dfs 1"<<endl;
                    cout<<"for bfs 2"<<endl;
                    cout<<"for close the program 3"<<endl;
                    cin>>choice;
                    switch(choice)
                    {
                                  case 1:cout<<"enter the start element"<<endl;
                                         cin>>startele;
                                         d1.dfspush(vm,startele); 
                                         cout<<"dfs complete"<<endl; 
                                         break;
                                  case 2:cout<<"enter the start element"<<endl;
                                         cin>>startele;
                                         d2.bfspush(vm,startele);
                                         cout<<"bfs complete"<<endl;
                                         break;
                                  default: 
                                           cout<<"no appropriate choice"; 
                    }
    }
   system("pause");
   return 0;
}
