#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p,*q;
    int a=8;
    p=&a;
    *q=5;
    //p[1]=9;// no
    printf("%d %d ",p[0], *q);
}