#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
struct node *back=NULL;
struct node * push_ele(struct node * head)
{
    int idata;
    printf("enter the data\n");
    scanf("%d" , &idata);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = idata;

    if(head == NULL){
        newnode->next = NULL;
        head = newnode;
        head->prev = NULL;
        back = newnode;
    }else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
        head->prev = NULL;
        
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
    struct node  *a1=head, *a2=head;
    int stin = st;
    int midin = mid;

    printf("merge function st %d mid %d end %d\n",st,mid,end);

    while(stin--){
            a1 = a1->next;
            printf("a1 :%d\n",a1->data);
    }
    while(midin--){
            a2 = a2->next;printf("a2 :%d\n",a2->data);
    }
    printf("current a1 :%d\n",a1->data);
    printf("current a2 :%d\n",a2->data);
    stin = st;midin = mid;
    for(stin = st,midin = mid;stin < midin||midin < end;stin++,midin++ ){
        if( a1->data > a2->data){

            printf("swap data %d\n",a1->data);
            int temp = a1->data;
            a1->data=a2->data;
            a2->data = temp;
            if(stin < midin)
                a1 = a1->next;

        }else if(a1->data < a2->data){
            if(stin < midin)
                a1 = a1->next;

        }else {
            if(stin < midin)
                a1 = a1->next;
            a2 = a2->next;
        }

    }

    //printf("a1 :%d\n",a1->data);
    //printf("a2 :%d\n",a2->data);
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

    while( head != '\0'){
            ele++;
            head = head->next;
    }
    return ele-1;
}
int main()
{
    printf("choose the option \n");
    long choose;
    printf("enter 1 push\nenter 2 for display\nenter 3 for mergesort\n");
    scanf("%ld",&choose);

    struct node *head = NULL;
    struct node *lastpointer(struct node *);
    
    void traverse(struct node *);
    int end;
    while(choose != -1){

        switch(choose){
            case 1 :head = push_ele(head);
                    break;

            case 2 :display(head);break;

            case 3 :
                    end = count(head);
                    printf("end : %d\n",end);
                    mergesort(head,0,end);
                    break;
            case 4 :
                    traverse(back);break;
            default :printf("wrong input\n") ;break;
        }
        printf("enter 1 push\nenter 2 for display\nenter 3 for mergesort\nenter 4 for reverse printout\n");
        scanf("%ld",&choose);
    }
    return 0;
}

void traverse(struct node * head)
{
   printf("treansfer\n");
   while( head != NULL){
            
            printf("%d\n",head->data);head=head->prev;
   }
}
