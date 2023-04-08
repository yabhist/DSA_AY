#include <stdio.h>
#include <stdlib.h>
int i = 0;


typedef struct node {
	int key;
	struct node* prev;
	struct node* next;

} node;


node* head = NULL;
node* tail = NULL;


void traverse()
{
	
	node* ptr = head;

	while (ptr != NULL) {
		printf("%d ", ptr->key);
		ptr = ptr->next;
	}

	printf("\n");
}

void insertatbegin(int k)
{
	node* ptr= (node*)malloc(sizeof(node));

	ptr->key = k;
	ptr->next = NULL;
	ptr->prev = NULL;

	
	if (head == NULL) {
		head = ptr;
		tail = head;
	}
	else {
		ptr->next = head;
		head->prev = ptr;
		head = ptr;
	}
}

void insertatend(int k)
{

	node* ptr= (node*)malloc(sizeof(node));

	ptr->key = k;
	ptr->next = NULL;
	ptr->prev = NULL;

	if (head == NULL) {
		head = ptr;
		tail = head;
	}
	else {
		ptr->prev = tail;
		tail->next = ptr;
		tail = ptr;
	}
}

void insertatpos(int k, int pos)
{
	if (pos == 0) {
		insertatbegin(k);
	}
	else {
		node* tmp = head;
		while (pos--) {
			tmp = tmp->next;
		}
        if(!tmp){
            insertatend(k);
        }
        else{
            node* ptr= (node*)malloc(sizeof(node));

            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->key = k;

            ptr->next = tmp;
            ptr->prev = tmp->prev;
            tmp->prev->next = ptr;
            tmp->prev = ptr;
        }
		
	}
}

void delatbegin()
{
    node* tmp=head;
	head = head->next;
    if(head) head->prev=NULL;
    free(tmp);
}

void delatend()
{
    node* tmp=tail;
	tail = tail->prev;
	if(tail) tail->next = NULL;
    free(tmp);
}

void delatpos(int pos)
{
	if (pos == 0) {
		delatbegin();
	}
	else {
		node* tmp = head;
		while (pos--) {
			tmp = tmp->next;
		}
        if(!tmp->next){
            delatend();
        }
        else{
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
        }
	}
}

void delval(int k){
    while(head && head->key==k){
        node* tmp=head;
        head = head->next;
        if(head) head->prev=NULL;
        free(tmp);
    }
    node* ptr=head;
    while(ptr){
        node* tmp=ptr;
        ptr=ptr->next;
        if(tmp->key==k){
            if(!tmp->next){
                tail = tail->prev;
                if(tail) tail->next = NULL;
                free(tmp);
                break;
            }
            else{
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                free(tmp);
            }
        }
    }
}

void search(int k){
    node* ptr=head;
    while(ptr){
        if(ptr->key==k){
            printf("found\n");
            return;
        }
        ptr=ptr->next;
    }
    printf("not found\n");
}
int main()
{
	insertatbegin(2);
	insertatbegin(3);
	insertatbegin(5);
    traverse();

    insertatend(2);
    insertatend(3);
    insertatend(5);
    traverse();

    delatbegin();
    traverse();

    delatend();
    traverse();

    insertatpos(7,2);
    insertatpos(56,0);
    insertatpos(56,6);
    traverse();

    search(3);
    search(700);

    delatpos(3);
    delatpos(0);
    delatpos(4);
    traverse();

    delval(3);
    traverse();
    delval(2);
    traverse();
}
