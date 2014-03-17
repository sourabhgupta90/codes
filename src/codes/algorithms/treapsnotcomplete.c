#include<stdio.h> 
#include<malloc.h>
struct node 
{
  int key;
  int priority;
  struct node *right;
  struct node *left;
  struct node *pred;     
     
};

struct node *build(struct node * point,int k,struct node * tpre)
{
   	struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
        point = newnode;
        newnode->key = k;   
        point->priority = 1;
        point->right=NULL;
        point->left=NULL;
        point->pred=tpre;
        return point;
}

struct node * bininsert(struct node *p,int k)
{
   struct node * point = p;
   struct node * tpre =NULL;
   if(!point){
        p = build(NULL,k,NULL);
        return p;
   }else{
       while(point){
            tpre = point;
            if(point -> key > k){
                point = point -> left;
            }else
                point = point -> right;
       }
       if(tpre -> key > k){
           point =  build(tpre->left,k,tpre);
           tpre->left = point;
	}else{
           point =  build(tpre->right,k,tpre);
           tpre->right = point;
	}
	return p;
   }
} 

inorder(struct node *head )
{
   // printf("%d",head->key);
   // printf("%d",head->left->key);
   if(head){
       inorder(head->left);
       printf("%d\n",head->key);
       inorder(head->right);
    }
  
  
}
maxheap(){



}
main()
{
    int choose,ele;
    struct node *head = NULL;

    int count=0;
    printf("enter 1 for insert\nenter 2 for show\n");
    scanf("%d",&choose);
    while(choose != -3){
    count++;	
    switch(choose){
        case 1 :printf("enter ele \n");
                scanf("%d",&ele);
                head = bininsert(head,ele);
                minheap(count,head);
		break;

        case 2 :inorder(head);break;

        default :printf("wrong input\n") ;break;
    }
    printf("enter 1 for insert\nenter 2 for show\n");
    scanf("%d",&choose);
    }
      
      
}
