#include<stdio.h>
#include<malloc.h>
struct node
{
       int data;
       struct node *next; 
};
struct linked
{
       struct node *pointer;
       struct linked *nextpo; 
};
struct linked * add(struct linked **headref1,struct node **head)
{
               struct linked *newnode,*temp;
               temp=*headref1;
               
               newnode=(struct linked *)malloc (sizeof(struct linked));
               newnode->pointer=*head; 
               while(temp!=NULL)                  
               {                  
               temp=temp->nextpo;                 
               }
               temp=newnode;
               temp->nextpo=NULL; 
               
               return (temp);
               
}
struct node * makeset(struct node **headref,int data1)
{
               struct node *newnode;
               newnode=(struct node *)malloc (sizeof(struct node));
               newnode->data=data1; 
               *headref=newnode;
               newnode->next=newnode;
               return (*headref);
}
struct node * return1(struct linked ** head1,int no)
{
        int i;
        struct linked *temp;
        temp=*head1;
        for(i=0;i<no-1;i++)
        {
                      temp=temp->nextpo;                              
                         
        }
              return (temp->pointer);
              
              
}
int represen(struct node **head)
{
    struct node * temp;
    temp=*head;
    while(temp->next!=temp){
    temp=temp->next;
}
    return (temp->data);
}
union1(struct node **head1,struct node **head2)
{
struct node *temp;
temp =*head2;
while(temp!=temp->next)
{              
               temp=temp->next;   
                       
}
temp->next=*head1;

}

main()
{
      
      int choice,list_no,list_ele
      choice=0;
      while(choice!=4)
      {
                  printf("choices\n");
                  printf("for makeset 1 \n");
                  printf("for represtative 2 \n");
                  printf("for union 3 \n");
                  scanf("%d",&choice);
                  if(choice==1)
                  {
                            list_no++;
                            printf("no of the listed list is %d\n",list_no);
                            printf("enter the data \n");
                            scanf("%d",&list_ele); 
                            head=makeset(&head,list_ele);
                            printf("%d\n",&head);
                            head1=add(&head1,&head);
                            head=NULL; 
                            printf("%d\n",&head1);
                  }
                  else if(choice==2)
                  {
                            
                            printf("%d\n",&head1);
                            printf("which linked list\n");
                            scanf("%d",&re);
                            k=return1(&head1,re);
                            t=represen(&k);
                            printf("%d\n",t);
                  }
                  else if(choice==3)
                  {
                            scanf("%d",&y);
                            scanf("%d",&z);
                            k=return1(&head1,y);
                            p=return1(&head1,z);
                            t=represen(&k);
                            printf("%d\n",t);

                            m=represen(&p);
                            printf("%d\n",m);

                            if(m>t)
                            {
                                    union1(&p,&k);
                            }        
                            else
                            {
                                 union1(&k,&p);
                            }        
                 }  
      }
}
