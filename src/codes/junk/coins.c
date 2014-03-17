#include<stdio.h>
int calculate(int a)
{
   int p,q,r,g;
   p=0;q=0;r=0;
   if(a%12==0)    
   {
               p=calculate(a/2); 
               q=calculate(a/3);
               r=calculate(a/4);
   
 

               g=p+r+q;
}



 else
 {
 g=a;    
 }
printf("%d\n",g);
               return (g); 
}
main()
{
 int x,i,y,d,z[10];
 scanf("%d",&x);
 for(i=0;i<x;i++)
 {
 scanf("%d",&y);
 z[i]=y;;
 }
 for(i=0;i<x;i++)
 {
                 z[i]=calculate(z[i]);
                 printf("%d\n",z[i]);
 }
 
  scanf("%d",&d);
}
