#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* link;
};

Node* top=NULL;

void push(int data)
{
	Node* temp = new Node();
	if (!temp) {
		cout << "\nStack Overflow (memory)";
		exit(1);
	}
	temp->data = data;
	temp->link = top;
	top = temp;
}


int isEmpty()
{
	return top == NULL;
}

int peek()
{
	if (!isEmpty())
		return top->data;
	else
		exit(1);
}
void peek2(int index)
{
    Node *temp=top;
	for(int i=0;i<index;i++)
    {
        temp=temp->link;
    }
    cout<<temp->data<<'\n';
}
void search(int val)
{
    Node* temp=top;
    int index=0;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            cout<<index<<'\n';
            break;
        }
        index++;
        temp=temp->link;
    }
}

void pop()
{
	Node* temp;
	if (top == NULL) {
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else {
		temp = top;
		top = top->link;
		free(temp);
	}
}

void display()
{
	Node* temp;
    temp = top;
    while (temp != NULL) {

        cout << temp->data << "-> ";

        temp = temp->link;
    }
	cout<<'\n';
}

int main()
{
	push(11);
	push(22);
	push(33);
	push(44);
	display();
	cout << "Top element is " << peek() << endl;
    peek2(1);
    search(22);
	pop();
	pop();
	display();
	cout << "Top element is " << peek() << endl;
}
