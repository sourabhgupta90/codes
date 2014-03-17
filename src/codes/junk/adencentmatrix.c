#include<stdio.c>
#include<stdlib> // for calloc and malloc
struct node{
	int data;
	struct node * next; 

};
graph()
{
    char  a;
    struct node * head = NULL;
    while( scanf("%c", &a) && a != '0'  ){
	     if(head == NULL){
                struct node * newnode = (struct node * )malloc(sizeof(struct node ));
                newnode->data = a - '0';
	        newnode->next = NULL;
		head  =  newnode;
	     }else{
              	struct node * newnode = (struct node * )malloc(sizeof(struct node ));
                newnode->data = a - '0';
		newnode->next = head;
                head  = newnode;
            }
    }
    struct node *temp = head;
    
    while(temp  != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
    
    temp = head;	
    int *ptr = (int *)calloc(10, sizeof(int));
    
    
    temp  =  head;
    while(temp != NULL){
        ptr[temp->data] +=  1;    
		temp = temp->next;
    } 		
    int i = 0;
    while( i  != 10 ){
	printf(" %d \n ",ptr[i] );
        i++;
	 		
    }
}


int main()
{
	graph();
	return 0;
}
