#include<stdio.h>
main()
{
      int a[100],d,j,i,s,div,integer,x,y,str,end,remain;
      printf("no. of integer range\n");
      scanf("%d",&integer);
      printf("\n");
      for( i=0;i<2*(integer);i++)
      { 
                         printf("start\n");
                         scanf("%d",&x);
                         printf("end\n");
                         a[i]=x;
                         scanf("%d",&y);
                         a[++i]=y;
       }
       i=0;
       j=0;
       while(j!=2*integer)
       {
                         str=a[j];
                         end=a[j+1];
                         ++j;
                         ++j;
                         if(str<0)
                         {
                            str=-str;      
                         }
                         if(end<0)
                         {
                         end=-end;         
                         }
                         
                         printf("\n");
                         for( i=str;i<=end;i++)
                         {
                                 
                                 if(i==2)
                                 {
                                 printf("  ");
                                 ++i;
                                 }
                               
                               
                               
                               
                                 for(div=2;div<i;div++)
                                 {
                                                 
                                         
                                         remain=i%div;
                                       
                                         if(remain==0)
                                         {
                                         break;             
                                         }
                                      
                                 
                                 
                                
                                 }
                                 if(remain!=0 )
                                         {
                                                printf("  ");          
                                                printf(" %d",i);                                         
                                          }   
                                 
                                 
                                 
                         }
       }
scanf("%d",d);
}               
