#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    return 0;
}
int isfull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack * ptr, int val)
{
    if(isfull(ptr))
    {
        printf("stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
void pop(struct stack * ptr)
{
    if(isempty(ptr))
    {
        printf("stack underflow\n");
    }
    else
    {
        ptr->top--;
    }
}
int peek(struct stack * ptr, int i)
{
    return ptr->arr[ptr->top-i];
}
int search(struct stack * ptr, int val)
{
    int i=ptr->top;
    while(i>=0)
    {
        if(ptr->arr[i]==val)
        {
            return i;
        }
        i--;
    }
    return -1;
}
int main()
{
    struct stack * s=(struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int*) malloc(s->size * sizeof(int));
    // s->arr[0]=9;
    // s->top++;
    // s->arr[1]=8;
    // s->top++;
    printf("%d\n",isempty(s));
    push(s,56);
    push(s,6);
    push(s,556);
    push(s,536);
    push(s,526);
    push(s,456);
    push(s,5346);
    push(s,560);
    pop(s);
    printf("%d\n",isempty(s));
    for(int j=0;j<s->top+1;j++)
    {
        printf("%d ",peek(s,j));
    }
    printf("\n");
    printf("%d %d\n",s->arr[s->top],s->arr[0]);// stack top , stack bottom
    printf("%d",search(s,536));
}
