#include<stdio.h>
main()
{
  int u;
  int a[100];

  scanf("%d\n",&u);
  int j,i,t;

  for(i=0;i<u;i++)
  {
    scanf("%d\n",&t);
    a[i]=t;              
                 
                 
  }      
  for(i=0;i<u;i++)
  {
  t=1;
  
  
  
  for(j=1;j<=a[i];j++)
  {
     t=t*j;                   
                     
  }                
  printf("%d\n",t);                
  }


}    
      
      
      
      
      
