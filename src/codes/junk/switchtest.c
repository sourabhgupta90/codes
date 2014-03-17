#include<stdio.h>
int main()
{
    int a = 3;
    double fn(int ,int);
    fn(a,a++);

}
double fn(int t ,int p)
{
    printf("%d /t %d",t,p);
}


