#include <bits/stdc++.h>
using namespace std;

struct QNode {
	int data;
	QNode* next;
	QNode(int d)
	{
		data = d;
		next = NULL;
	}
};

struct Queue {
	QNode *front, *rear;
	Queue() { front = rear = NULL; }

	void enQueue(int x)
	{
		QNode* temp = new QNode(x);
		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}

	void deQueue()
	{
		if (front == NULL)
			return;
		QNode* temp = front;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		delete (temp);
	}

	void search(int val)
	{
		int index=0;
		for(auto it=front;it!=NULL;it=it->next)
		{
			if(it->data==val)
			{
				cout<<index<<'\n';
				break;
			}
			index++;
		}
	}

	void access(int index)
	{
		QNode* temp=front;
		for(int i=0;i<index;i++)
		{
			temp=temp->next;
		}
		cout<<temp->data<<'\n';
	}

	void display()
	{
		QNode* temp;
		temp = front;
		while (temp != NULL) {

			cout << temp->data << "-> ";

			temp = temp->next;
		}
		cout<<'\n';
	}
};

int main()
{
	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.enQueue(15);
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.display();
	q.access(2);
	q.search(30);
	q.deQueue();
	q.deQueue();
	q.display();
	cout << "Queue Front : " << (q.front)->data << endl;
	cout << "Queue Rear : " << (q.rear)->data;
}

