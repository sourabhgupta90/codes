#include<stdio.h>
int * warshallalgorithm(int *t)
{
   int i,j,h,maina[2][2],m,p,co,g,tempa[2][2];
   for(i=0;i<2;i++){
                    for(j=0;j<2;j++){
                                     maina[i][j]=*t;
                                     t++;
                                     }
                   }
   for(i=0;i<2;i++){
                    for(j=0;j<2;j++){
                                     tempa[i][j]=maina[i][j];
                                     }
                   }
   co=0;   
   while(co!=1){
                for(i=0;i<2;i++){
                                 for(j=0;j<2;j++){
                                                  for(h=0;h<2;h++){
                                                                   if(tempa[i][j]==tempa[j][m]){
                                                                                                tempa[i][m]=tempa[i][j];
                                                                                               }    
                                                                  }
                                                  }
                                }
                g=0;   
                while(p!=1){
                            for(i=0;i<2;i++){
                                             for(j=0;j<2;j++){
                                                              if(maina[i][j]!=tempa[i][j]){
                                                                                           p=1;
                                                                                           g=1; 
                                                                                           }
                                                               }
                                            }
                            if(i==2){
                                     p=1; 
                                     }
                g=co;
                for(i=0;i<2;i++){
                                 for(j=0;j<2;j++){
                                                  maina[i][j]=tempa[i][j];
                                                  }
                                 }
                        }
            }
}
main()
{
       int maina[2][2],i,j,x,ch,*p;
       ch=0;
       while(ch!=3){
       scanf("%d",&ch);
       if(ch==1){
       for(i=0;i<2;i++){
                        for(j=0;j<2;j++){
                                         scanf("%d",&x);
                                          maina[i][j]=x;
                                         }
                        }     
                }
       else if(ch==2){
                      p=warshallalgorithm(&maina[0][0]); 
                      for(i=0;i<2;i++){
                                       for(j=0;j<2;j++){
                                                        maina[i][j]=*(p++);                                
                                                        }               
                                       }
                     }
}