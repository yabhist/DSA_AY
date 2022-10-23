#include<stdio.h>
#include<stdlib.h>
void access(int a[], int * index)
{
    printf("%d\n",a[*index]) ;
}
void access(int a[], int index)
{
    printf("%d\n",a[index]) ;
}
int main()
{
    int a[100]={1,3,7,3,9,8};
    int index =4;
    access(a,&index);
    access(a,index);
    access(a,4);
}