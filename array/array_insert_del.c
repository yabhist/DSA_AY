#include<stdio.h>
#include<stdlib.h>

int insert(int a[], int *size, int e, int capacity,int i)
{
    if(i>=capacity)
    {
        return -1;
    }
    for(int ind=*size-1;ind>=i;ind--)
    {
        a[ind+1]=a[ind];
    }
    a[i]=e;
    *size+=1; 
    return 1;
}
int del(int a[], int *size, int e, int capacity,int i)
{
    for(int ind=i;ind<*size-1;ind++)
    {
        a[ind]=a[ind+1];
    }
    *size-=1;
    return 1;
}
int main()
{
    int a[100]={7,18,12,27,88};
    int size1=5, e=78, i=2;
    int * size=&size1;
    insert(a,size,e,100,2);
    for(int ind=0;ind<*size;ind++){
        printf("%d ",a[ind]);
    }
    printf("\n");
    int j=0;
    del(a,size,e,100,j);
    for(int ind=0;ind<*size;ind++){
        printf("%d ",a[ind]);
    }
}