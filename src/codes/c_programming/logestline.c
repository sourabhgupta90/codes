#include<stdio.h>
#define MAXLINE 100
main()
{
    int len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];
        
    while( (len = getline1(line  ,MAXLINE)) ){
        if(max<len){
            
            max = len;
            printf(" max %d  \n" ,max);
            copy(longest,line);
        }
    }
    if(max){
        printf("%s\n", longest);
    }
}
copy(char longest[],char line[])
{
    int index = 0;
    while( ( longest[index] = line[index] ) != '\0'){
        printf("%c",longest[index]);
        index++;
    }
}
int getline1(char temp[] ,int lim )
{
          
    int len = 0;char c;
    while( (c=getchar()) != EOF && c != '\n' && len < lim - 1 ){
        temp[len++] = c;
        //printf("%c \n",c);
    }

    if(c == '\n'){
        temp[len++]='\n';
    }
    temp[len]='\0';
    printf("%d\n",len);
    return len;
}
