#include<stdio.h>
char s[90];
char * expand(char a[])
{
        int t = 0;
        
        int index = 0; 
        while(a[t]!= '\0'){
                if(a[t]=='-'  && t>0 && a[t+10] != '\0' && a[t-1]<a[t+1] ){
                        printf("%d \n",t);
                        char z ;
                        for(z = a[t-1]+1; z < a[t+1] ; z++){
                                s[index++] = z;        
                        }
                        
                }else{
                        s[index++] = a[t];
                }
                t++;
        }
        s[index]='\0';
        
        for(t=0; s[t] != '\0' ; t++){
                printf("%c \n",s[t]);
        
        }
        
        return s;
}
main()
{
        char a[] = "adfasdzzzza-zasd";  
        char *aa = expand(a);
        for(; *aa != '\0' ; aa++){
                printf("here :%c \n",*aa);
        }
}
