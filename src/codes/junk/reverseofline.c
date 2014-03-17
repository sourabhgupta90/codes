#include<stdio.h>
main()
{
      char *a,*p;
      a=NULL;
      int i,r;
      for(i=0;i<10;i++)
      {
      scanf("%c",a);                 
      a++;
      }
      
      p=a;
      while(*p!='\0')      
      {
       printf("%d",p);                    
      p++;
      }

scanf("%d",&r);
}
