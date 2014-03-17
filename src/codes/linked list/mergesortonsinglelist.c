#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
   
};
struct node * push_ele(struct node * head,int idata )
{
    
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = idata;
    if(head == NULL){
        newnode->next = NULL;
        head = newnode;
    }else{
        newnode->next = head;
        head = newnode;
    }
    return head;
}
struct node * push_end(struct node * head,int idata )
{
    
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = idata;
    if(head == NULL){
        newnode->next = NULL;
        head = newnode;
    }else{
        struct node * temp=head;
        while(temp->next != NULL){
                
                temp=temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
    return head;
}
display(struct node * temp)
{
    while(temp != '\0'){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}


merge(struct node * head,int st,int mid,int end)
{
    
    printf("merge function st %d mid %d end %d\n",st,mid,end);
    int t,n1 = mid - st + 1;
    int n2 = end - mid ;
    struct node * l1=NULL;
    struct node * r1=NULL;
    struct node  *temp=head;
    for( t = 0 ; t < n1 ; t++){
        l1 = push_end(l1,temp->data);        
        temp=temp->next;
    }
    l1 = push_end(l1,3242332);
    printf("l1\n");
    display(l1);
    
    for( t = 0 ; t < n2 ; t++){
        r1 = push_end(r1,temp->data);        
        temp=temp->next;
    }
    r1 = push_end(r1,3242332);
    printf("r1\n");
    display(r1);
    temp=head;
    
    
    for(t = st ; t <= end ;t++){
        
        
        if(l1->data <= r1->data){
                temp->data=l1->data;
                l1=l1->next;
                //printf("dadas\n");
    
        }else{
                temp->data=r1->data;
                r1=r1->next;
                //printf("fggfg\n");
        }
        temp=temp->next;
        
    }
    
    
}

mergesort(struct node * head,int st ,int end)
{
    int mid;
    if(st < end){
        mid = (st+end)/2;

    printf("st %d mid %d end %d\n",st,mid,end);
    mergesort(head,st,mid);
    mergesort(head,mid+1,end);
    merge(head,st,mid,end);
    }
}

int count(struct node * head)
{
    int ele = 0;

    while( head ){
            ele++;
            head = head->next;
    }
    return ele-1;
}
int main()
{
    printf("choose the option \n");
    long choose;int idata;
    printf("enter 1 push\nenter 2 pushend\nenter 3 for display\nenter 4 for mergesort\n");
    scanf("%ld",&choose);

    struct node *head = NULL;

    int end;
    while(choose != -1){

        switch(choose){
            case 1 :printf("enter the data\n");
                    
                    scanf("%d" , &idata);
                    head = push_ele(head,idata);
                    break;
            case 2 :
                    printf("enter the data\n");
                    scanf("%d" , &idata);
                    head = push_end(head,idata);
                    break;    
            case 3 :display(head);break;

            case 4 :
                    end = count(head);
                    printf("end : %d\n",end);
                    mergesort(head,0,end);
                    break;
                
            default :printf("wrong input\n") ;break;
        }
        printf("enter 1 push\nenter 2 pushend\nenter 3 for display\nenter 4 for mergesort\n");
        scanf("%ld",&choose);
    }
    return 0;
}
