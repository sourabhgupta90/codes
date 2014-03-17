#include<iostream>
using namespace std;
int main ()
{
   int nowdividedent,num,minprice,maxprice,secondremainder,numnine,price,remainder;
   cout<<"min price "; 
   cin>>minprice;
   cout<<endl;
   cout<<"max price ";
   cin>>maxprice;
   cout<<endl;

   numnine=0;
   price=maxprice;
   for(int no=minprice; no<=maxprice ; no++ )
   {
            num=0;
            remainder=no%10;
            nowdividedent=no;
            if(remainder==9)
            {
              cout<<no<<endl;
              num++;
              nowdividedent=nowdividedent/10;
              secondremainder=nowdividedent%10;
              
              while(secondremainder==9)
              {
                    num++; 
                    nowdividedent=nowdividedent/10;
                    secondremainder=nowdividedent%10;             
                    
              }            
              cout<<"secondremainder"<<secondremainder<<endl; 
              if(num>=numnine && num!=0)
              {
                             numnine=num;                  
                             price=no; 
              }             
            }
   }        
   cout<<"price"<<price<<endl;        
   system("pause");        
   return 0;        
}        
