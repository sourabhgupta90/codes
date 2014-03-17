#include <stdio.h>
#include <malloc.h>
struct node
{
       int data;
       struct node *next; 
};

struct store
{
       struct store *snext;
       struct node *list; 
};



struct node *head;
struct store *shead;

push(  int data1 )
{
               int flag;
               flag=0;
               if( head == NULL ) { 
                       flag = 1;
               }
              
              
               struct node *newnode;
               newnode = ( struct node * ) malloc (sizeof ( struct node ) );
               newnode->data = data1; 
               
               newnode->next = head;
               
               head = newnode;
               if( flag == 1 ){
                
                head->next = head;  
               
               }
               
               
}

spush()
{
               struct store *newnode ,*temp;
               newnode = ( struct store * ) malloc (sizeof ( struct store ) );
               newnode->list = head; 
               
               newnode->snext = shead;
               shead = newnode;
               
}

display()
{
         struct store *temp;
         temp = shead;
         while ( temp != NULL ) {
                 do {
                              if(temp->list->next != temp->list){
                                                  printf( "%d " , temp->list->data );                 
                                                  temp->list = temp->list->next;
                              }
                              else if ( temp->list->next == temp->list ) {     
                                                  printf( "%d " , temp->list->next->data );
                                                  printf( "  ");
                              }
                              printf( "   ");
                 } while ( temp->list->next != temp->list ); 
                          
                 printf( "new   \n");
                 temp = temp->snext;
         }         
}

merge( int big, int small )
{
         int i;
         struct store *temp, *pre3,*pre1,*pre2;
         temp = shead;
         int flag1,count;
         struct node *blist;
         struct node *slist;
         
         flag1=0;
         count=0;
         while ( temp != NULL ) {
                      do  {
                                if( temp->list->next == temp->list ) {     
                                                     if( small == temp->list->next->data ) { 
                                                               printf( " small\n ");
                                                               slist = temp->list; 
                                                               while ( slist->next != slist ) {
                                                                       slist = slist->next;
                                                               }
                                                               slist = slist->next; 
                                                               count++;
                                                     }
                                                     if ( big == temp->list->next->data   ) {
                                                               flag1 = 1;
                                                               blist = temp->list;
                                                               count++;         
                                                       
                                                     }
                                temp->list = temp->list->next;
                                                
                         } while ( temp->list->next != temp->list && count==2 );
                         
                         if(flag1 == 1){
                                  pre1 = temp;        
                                  pre3 = pre2;                                          
                         }
                         pre2=temp;
                         temp = temp->snext;
                          
         }
           
         slist->next = pre1->list;
         pre3->list=pre1->list;
         free(pre1);
}

int find( int n )
{
        struct node * temp;
        temp = head;
        while (temp->next != temp) {
                temp = temp->next;
        }
        
        return ( temp->data );

}

main()
{
        
        int choice, ele, re1, re2, temp;
        
        head=NULL;
        choice=0;
        while(choice != 4) {
                printf( "choice \n");
                scanf( "%d", &choice ); 
                if( choice == 1) {
                    scanf( "%d", &ele );
                    
                    push( ele );
                    spush( );
                    
                    head = NULL;
                } else if ( choice == 2 ) {
                       printf( " \n");
                       
                       display();
                } else if ( choice == 3 ) {                                
                       printf( " \n");
                       scanf( "%d", &re1 );
                       printf( " \n");
                       scanf( "%d", &re2 );       
                       if( re1 < re2 )
                       {
                                  temp=re1;
                                  re1=re2;
                                  re2=temp;
                       }
                       merge( re1, re2);
                }        
        }
        
        system ( "pause" );     

}
