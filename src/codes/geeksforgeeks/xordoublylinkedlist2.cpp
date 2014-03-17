#include<stdio.h>
#include<stdlib.h>
struct node{
        struct node * npx;
        int data;
};
struct node * last;
struct node * push(struct node * head , int data)
{
        struct node * newnode = (struct node *)malloc(sizeof (struct node) );
        newnode->data = data;
        if(!head){
                head=newnode;
                newnode->npx=NULL;
                last = newnode;
        }else if (!head->npx){
                head->npx = newnode;
                newnode->npx = head;
                head = newnode;
                
        }else{
                newnode->npx = head;
                head = newnode;
                head->npx->npx = (struct node *)((long)head->npx->npx ^ (long)newnode);
        }
        return head;
}

void display(struct node *head)
{
        if(head){
                printf("%d\n",head->data);
                if(head->npx){
                    printf("%d\n",head->npx->data);
                    struct node * prev1 = head;
                    struct node * prev2 = head->npx;
                    head=head->npx->npx;
                    while( head != prev1 ){
                        struct node * temp = (struct node *) ( (long)head ^ (long) prev1 ); 
                        printf("%d\n",temp->data);
                        prev1 = prev2;
                        prev2 = temp;
                        head = temp->npx;
                    }    
                 }                         
        
       }else
                printf("list is empty\n");
}



struct node *  delete1(struct node * head,int dat)
{
       struct node * initialhead = head;
       if(!head){
                return 0;
       }
       if(head->data == dat || head == NULL || head->npx == NULL){
                if(head->npx != NULL){
                        
                        struct node * temp = head;
                        head = head->npx;
                        head->npx = (struct node *)((long)head->npx ^ (long)temp);
                        free(temp);
                        return head;
                 }else{
                        
                        struct node * temp = head;
                        free(temp);
                        head = NULL;
                        return head;
                 } 
        }else{
            struct node * pre1 = head;
            struct node * pre2 = head->npx;
            head = head -> npx;
            while(head->data != dat){
                head = (struct node * )((long)pre1 ^ (long)head->npx);
                pre1 = pre2;
                pre2 = head;
            }
            if(head->npx != pre1){        
                    struct node * nextnode = (struct node *)((long)pre1 ^ (long)head->npx);
                    struct node * matchpreprenode = (struct node *)((long)pre1->npx ^(long)pre2);
                    nextnode->npx = (struct node *)((long) nextnode ->npx ^(long) pre2);
                    nextnode->npx = (struct node *)((long) nextnode ->npx ^(long) pre1);
                    pre1->npx = (struct node *)((long) nextnode  ^(long) matchpreprenode);
                    free(head);
                    return initialhead;
            }else{
                    if(pre1 == last){
                        free(head);
                        last->npx = NULL;
                        return pre1;
                    }else{
                        pre1->npx = (struct node *) ((long)pre1->npx ^(long) pre2);
                        free(head);
                        return initialhead;
                    
                    }        
             }
        }
        
        
}
int main()
{
        printf("%ld\n",sizeof(struct node*));
        int choose=1;int data;
        struct node * head = 0;
        printf("enter 1 for push \nenter 2 for display\nenter 3 for delete \n");
        while(choose){
                
        
                scanf("%d",&choose);        
                switch(choose){
                        case 1: printf("enter the element\n");scanf("%d",&data);
                                head = push(head,data);break;
                        case 2: display(head);break;
                                                                       
                        case 3:printf("enter delete  element\n");
                               scanf("%d",&data);
                               head = delete1(head,data);
                               break;
                }
                printf("enter 1 for push \nenter 2 for display\nenter 3 for delete \n");       
        }
}
