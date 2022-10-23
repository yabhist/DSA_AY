#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node* next;
};
void traverse(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr =ptr->next;
    }
    printf("\n");
}
struct node* insert_begin(struct node *head, int data)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
struct node* insert_pos(struct node *head, int data, int index)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;
    int i=0;
    if(index==0)
    {
        ptr->data=data;
        ptr->next=head;
        return ptr;
    }
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct node* insert_end(struct node *head, int data)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct node* insert_after_node(struct node *head, struct node * prevnode, int data)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}
struct node* del_begin(struct node *head)
{
    struct node * ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct node* del_pos(struct node *head, int index)
{
    struct node * ptr, * p;
    int i=0;
    if(index==0)
    {
        ptr=head;
        head=head->next;
        free(ptr);
    }
    else
    {
        ptr=head;
        while(i!=index)
        {
            p=ptr;
            ptr=ptr->next;
            i++;
        }
        p->next=ptr->next;
        free(ptr);
    }
    return head;
}
struct node* del_end(struct node *head)
{
    struct node * ptr, * p;
    int i=0;
    if(head->next==NULL)
    {
        ptr=head;
        head=head->next;
        free(ptr);
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            p=ptr;
            ptr=ptr->next;
        }
        p->next=ptr->next;
        free(ptr);
    }
    return head;
}
struct node* del_value(struct node *head, int val)
{
    struct node * ptr,*p;
    if(head->data==val)
    {
        ptr=head;
        head=head->next;
        free(ptr);
    }
    else
    {
        ptr=head;
        while(ptr->data!=val && ptr->next!=NULL)
        {
            p=ptr;
            ptr=ptr->next;
        }
        if(ptr->data==val)
        {
            p->next=ptr->next;
            free(ptr);
            del_value(head,val);
        }
    }
    return head;
}
void access(struct node *head,int index)
{
    struct node * ptr=head;
    int i=0;
    while(i!=index)
    {
        ptr=ptr->next;
        i++;
    }
    printf("%d\n",ptr->data);
}
void search(struct node* head,int val)
{
    struct node * ptr;
    ptr=head;
    int i=0;
    while(ptr!=NULL)
    {
        if(ptr->data!=val)
        {
            ptr=ptr->next;
        }
        else
        {
            break;
        }
        i++;
    }
    printf("%d\n",i);
}
int main()
{
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=34;
    third->next=NULL;
    traverse(head);
    head=insert_begin(head,987);
    head=insert_pos(head,91,0);
    head=insert_pos(head,3,1);
    head=insert_pos(head,333,2);
    head=insert_pos(head,31,1);
    head=insert_pos(head,39990,4);
    head=insert_end(head,35);
    head=insert_end(head,35);
    head=insert_end(head,35);
    head=insert_end(head,35);
    head=insert_after_node(head,second,1000);
    traverse(head);
    search(head,35);
    head=del_begin(head);
    traverse(head);
    head=del_pos(head,3);
    traverse(head);
    head=del_end(head);
    traverse(head);
    head=del_value(head,35);
    traverse(head);
    access(head,3);
}
