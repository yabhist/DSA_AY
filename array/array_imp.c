#include<stdio.h>
#include<stdlib.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void create_array(struct myarray *a, int tsize, int usize)
{
    // (*a).total_size=tsize;
    // (*a).used_size=usize;
    // (*a).ptr =(int *) malloc(tsize*sizeof(int));
    a->total_size=tsize;
    a->used_size=usize;
    a->ptr =(int *) malloc(tsize*sizeof(int));
}
void show(struct myarray *a)
{
    for(int i=0; i<a->used_size ;i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}
void set(struct myarray *a)
{
    int n;
    for(int i=0; i<a->used_size ;i++)
    {
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}
int main()
{
    struct myarray marks;
    //printf("%d",marks.total_size);
    create_array(&marks,100,20);
    set(&marks);
    show(&marks);
    
}

