#include<stdio.h>
#include<stdlib.h>
struct node{
        struct node * next;
        struct node *prev; 
        int data;
};
struct node * push(struct node * head , int data)
{
        struct node * newnode = (struct node *)malloc(sizeof (struct node) );
        newnode->data = data;
        if(!head){
                head=newnode;
                newnode->next=NULL;
                newnode->prev = NULL;
        }else{
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
                newnode->prev = NULL;
        }
        return head;
}
void display(struct node **head)
{
        while(*head){
                
                printf("%d\n",(*head)->data);
                (*head)=(*head)->next;
        }
}
void reversedisplay(struct node *head)
{
        while(head->next){
                //printf("%d\n",head->data);
                head=head->next;
        }
        while(head->prev){
                printf("%d\n",head->data);
                head=head->prev;
        }
        printf("%d\n",head->data);
}
int main()
{
        int choose=1;int data;
        struct node * head = 0;
        printf("enter 1 for push \nenter 2 for display\nenter 3 reverse display \n");
        while(choose){
                
        
                scanf("%d",&choose);        
                switch(choose){
                        case 1: printf("enter the element\n");scanf("%d",&data);
                                head = push(head,data);break;
                        case 2: display(&head);break;
                        case 3: reversedisplay(head);break;
                                        
                }
                printf("enter 1 for push \nenter 2 for display\nenter 3 for reverse display \n");       
        }
}
