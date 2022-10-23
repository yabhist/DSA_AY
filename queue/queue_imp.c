#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isfull(struct queue* q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}
int isempty(struct queue* q)
{
    if(q->r==q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue* q, int val)
{
    if(isfull(q))
    {
        printf("full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;
    }
}
void dequeue(struct queue* q)
{
    if(isempty(q))
    {
        printf("not possible\n");
    }
    else
    {
        q->f++;
    }
}
void search(struct queue* q,int val)
{
    for(int i=q->f+1;i<=q->r;i++)
    {
        if(q->arr[i]==val)
        {
            printf("%d\n",i-q->f-1);
            break;
        }
    }
}
void access(struct queue* q, int i)
{
    printf("%d\n",q->arr[q->f+i+1]);
}
int main()
{
    struct queue q;
    q.size=100;
    q.f=-1,q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    printf("%d %d\n",isempty(&q),isfull(&q));
    enqueue(&q,12);
    enqueue(&q,23);
    enqueue(&q,3);
    enqueue(&q,923);
    enqueue(&q,4323);
    dequeue(&q);
    dequeue(&q);
    printf("%d %d\n",isempty(&q),isfull(&q));
    for(int i=q.f+1;i<=q.r;i++)
    {
        printf("%d ",q.arr[i]);
    }
    printf("\n");
    access(&q,1);
    search(&q,3);
}
