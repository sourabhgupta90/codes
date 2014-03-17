#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
int main()
{
    char  a;
    struct node * head = NULL;
    while(scanf("%c", &a)){

            int t = a ;
            printf("a :%c \n",t );
            printf(" t :%d \n",t );
             if(head == NULL){
                struct node * newnode = (struct node * )malloc(sizeof(struct node *));
                head =  newnode;
                newnode->data = a;
             }else{
                struct node * newnode = (struct node * )malloc(sizeof(struct node *));
                newnode->next = head;
                head  = newnode;
                newnode->data = a;
            }
    }
    struct node *temp = head;
    while(temp->next != NULL){
        //printf("%c",temp->data);
        temp = temp->next;
    }
	/*	
	struct node *temp = head;	
	
	int *ptr = (int *)calloc(10, sizeof(int));
	while(temp->next != NULL){
        
    	ptr[temp-data] += 1;    
		temp = temp->next;
    } 		
	*/

        


	return 0;
}
