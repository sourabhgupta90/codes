#include<stdio.h>
main()
{
      int i,main,div,remainder;
      
      for(i=0;i<20;i++)
      {
              scanf("%d",&main);
              scanf("%d",&div);
              remainder=main%div;                          
              printf("%d",remainder);                 
      }                
      }
