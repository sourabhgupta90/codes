#include<stdio.h>
int main()
{
    int i = 3;
    char c = 's';
    char s[] = "dse";
    char str[49] ;
    sprintf(str,"%d %s %c",i,s,c);
    printf("%s",str);
    return 0;
}
