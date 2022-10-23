#include<stdio.h>
#include<stdlib.h>
void search(int a[],int val,int used_size)
{
    int is=0;
    for(int i=0;i<used_size;i++)
    {
        if(val==a[i])
        {
            printf("%d\n",i);
            break;
        }
    }
    return;
}
int main()
{
    int a[100]={1,3,7,3,9,8};
    search(a,9,6);
    search(a,3,6);
}