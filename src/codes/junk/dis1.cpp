#include<stdio.h>
#include<malloc.h>
struct node
{
       int data;
       struct node *next; 
};
struct node * makeset(struct node **headref,int data1)
{
               struct node *newnode;
               newnode=(struct node *)malloc (sizeof(struct node));
               newnode->data=data1; 
               *headref=newnode;
               newnode->next=newnode;
               return (*headref);
}
int representive(struct node **head)
{
    struct node * temp;
    temp=*head;
    while(temp->next!=temp){
    temp=temp->next;
}
    return (temp->data);
}

main()
{
      
      int choice,list_ele;
      choice=0;
      while(choice!=4)
      {
                  printf("choices\n");
                  printf("for makeset 1 \n");
                  printf("for represtative 2 \n");
                  
                  scanf("%d",&choice);
                  if(choice==1)
                  {
                            printf("enter the data \n");
                            scanf("%d",&list_ele); 
                            head=makeset(&head,list_ele);
                            printf("%d\n",&head);
                            
                  }
                  else if(choice==2)
                  {
                            
                            printf("enter first linked list\n");
                            scanf("%d",&re);
                            k=return1(&head1,re);
                            t=represen(&k);
                            printf("%d\n",t);
                  }
     }
}
