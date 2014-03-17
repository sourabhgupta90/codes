#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int array[] = {0,0,0,0,0,0,0,0,0,0};
    FILE *fp;
    fp=fopen("input","r");
    int ch = fgetc(fp);
    int len = 0;
    while(ch != EOF ){
        if( ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ){
            len++;
            ch = fgetc(fp);
        }else{
            ch = fgetc(fp);
            array[len-1] +=1 ;
            len=0;
        }
    }
    int max = 0;
    for(int t = 0  ; t  < 10 ;t++){
        cout<<array[t]<<endl;
        if(max<array[t]){
            max=array[t];
        }
    }
    cout<<max<<endl;

    for(int t = 0  ; t  < 11 ;t++){
      cout<<"___";
    }
    cout<<endl;cout<<endl;
    for(int t = max  ; t  > 0 ;t--){

        for(int c = 0  ; c  < 10 ;c++){
            if(t == array[c] ){
                    array[c] = -1;
                    cout<<"_"<<c<<"_";

            }else if(array[c] == -1){
                    cout<<"| |";
            }else{
                cout<<"   ";
            }

        }
        cout<<endl;
    }

    for(int t = 0  ; t  < 11 ;t++){
      cout<<"___";
    }
    return 0;
}
