#include<stdio.h> 
#include<malloc.h>
struct node 
{
  int data;
  struct node *next;     
};
struct node *head;
push(struct node ** headref,int putdata)
{
   struct node *newnode;
   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=putdata;
   newnode->next=NULL;
   *headref= newnode;    
           
}

struct node *builddummy(struct node *p)
{
   int i;
   struct node *dummy;
   dummy=p;
   struct node *tail=dummy;
          
   for(i=0;i<5;i++)
   {
     push(&(tail),i);              
     tail=tail->next;             
   }
   tail=NULL;
   return (dummy ->next);
} 
show(struct node *head1 )
{
   if(head1!=NULL)
  { while(head1!=NULL)
                    {
                        printf("%d",head1->data);
 		                   head1=head1->next;
                    }
  }
  else
  {
  printf("no element");
  }
  

}
main()
{
      int i;

      head=NULL;
      struct node *t=builddummy(head);
      show(t);
      scanf("%d",&i);            
}
