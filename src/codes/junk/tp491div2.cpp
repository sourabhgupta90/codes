#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node {
    int data;
    struct node * next;
};

void check(struct node ** temp)
{

    //struct node * temp1 = *temp;
    struct node * ptr ;

    int s;


    while (*temp != NULL){
        ptr = *temp;
        temp++;
        cout<<temp<<endl;
        while( ptr != NULL ){
            cout<<" hre "<<endl;
            cout<< ptr -> data<<endl;
            ptr =  ptr -> next;
        }
    }
}
int count (int N ,int K)
{
    if(N<6){
        return 0;
    }
    int i = 1 ;
    int temp = 1;
    while(i + temp < K){
        if(i == N){
            temp += 1;
        }else{
            i += 1;
        }
    }
    cout<<"TEMP : "<<temp<<" : i : "<<i<<endl;

    struct node * llist = ( struct node * ) calloc (N - temp + 1 ,sizeof(struct node ));
    struct node * temp1 = NULL;
    struct node * head = NULL;
    int s,k;
    int testflag = 0;
    int ll=0;int pair =0;
    for( k = 1  ; k <= N; k++){
        for( s = k+1 ; s <= N ; s++ ){

                if( s + k >= K ){
                    pair+=1;
                    //testflag += 1;
                    cout<<" here TEMP : "<<k<<" : i : "<<s<<endl;
                    if(head == NULL){

                        struct node * newnode = (struct node * ) malloc( sizeof(struct node ));
                        newnode->data = s;
                        newnode->next = NULL;
                        head = newnode;

                    }else{

                        struct node * ptr = head;
                        while( ptr->next != NULL ){
                            //cout<<" hre "<<endl;
                            ptr = ptr -> next;
                        }
                        struct node * newnode = (struct node * ) malloc( sizeof(struct node ));
                        newnode->data = s;
                        ptr->next = newnode;
                        newnode->next = NULL;
                    }
                    /*
                    if(testflag == 17){
                        cout<<"TEMP : "<<k<<" : i : "<<s<<endl;
                        check( llist );
                        return 0;
                    }
                    */
                    if( s == N ){
                        llist [ll] = head;
                        ll++;
                        for(int t = 0 ; t < ll; t++){
                            cout<<"llist"<<llist[t]<<endl;
                            cout<<"head"<<head<<endl;
                        }
                        head = NULL;
                    }

                }
        }
    }
    cout<<pair<<endl;
    return 0;
}

int main()
{
    int N , K;
    cin>>N;
    cin>>K;
    int co = count(N,K);
    return 0;
}
