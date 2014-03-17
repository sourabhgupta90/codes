#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;   

};
struct node *head;
build(struct node *head1,int data1)
{
               struct node *newnode;                            
               newnode=(struct node*)malloc(sizeof(struct node));
               newnode->data=data1;
               if(head==NULL)
               {
               newnode->next=NULL;             
               newnode->prev=NULL;               
               head1=newnode;
               }
               else
               {
                 struct node *temp;   
                 temp=head1;
                 while(temp->next!=NULL)
                 {
                                  temp=temp->next;
                 } 
                temp->next=newnode;
                newnode->next=NULL;
                newnode->prev=temp;
               }
}
display(struct node *head2,int data3)
{
             int i,p;
             p=data3;       
             printf(" %d\n",p);
             for(i=1;i<p;i++)
             {
              
              head2=head2->next;                    
             }
             printf("the node %d\n",head2->data);
}
main()
{
      struct node *head;      
      int i,da,d;
      for(i=0;i<5;i++)
       {
                      scanf("%d\n",&da);
            
                      build(head,da);
       }
       printf("display node\n");
       scanf("%d",&d);
       display(head,d);   
        printf("system pause\n");
        scanf("%d",&d);
}
