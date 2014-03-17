#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
        string line;
        string s1,s2;

        int i;
        int p,flag;

        string inventory[2000],store[100];

        ifstream myfile ( "exp.txp" );

        if ( myfile.is_open() ) {
           while ( myfile.good() ) {
                 getline ( myfile, line );

                 if( line[0] == '/' || line[0] == ' ' ) {

                 }else{
                       s1=line[0];
                       s2=line[1];
                       s1+=s2;

                       inventory[i]=s1;
                       cout<<inventory[i]<<endl;

                  }
           }

           myfile.close();
        }else
        cout << "Unable to open file";

        p=0;

        for (int j=0 ; j<i; j++){
            flag=0;
                   for (int t=0 ; t<j ; t++){
                       if(j==0){
                                break;
                       }
                       
                       if(inventory[t] == inventory[j]){
                                       flag=1;

                        }

                   }
                   if(flag==0){

                   store[p]=inventory[j];
                   p++;
                   }
        }



        for (int j=0 ;j<p ;j++){

            cout<<store[j]<<endl;

        }

        cout << "/ the complete ID" << endl;

        system( "pause" );

        return 0;

} 
