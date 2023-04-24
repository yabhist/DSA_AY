#include <bits/stdc++.h>
using namespace std;

struct item {
	int value;
	int priority;
};

item pr[100000];

int Size = -1;

void enqueue(int value, int priority)
{
	Size++;

	pr[Size].value = value;
	pr[Size].priority = priority;
}

int peek()
{
	int highestPriority = INT_MIN;
	int ind = -1;

	for (int i = 0; i <= Size; i++) {

		if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value) {
			highestPriority = pr[i].priority;
			ind = i;
		}
		else if (highestPriority < pr[i].priority) {
			highestPriority = pr[i].priority;
			ind = i;
		}
	}

	return ind;
}

void dequeue()
{
	int ind = peek();

	for (int i = ind; i < Size; i++) {
		pr[i] = pr[i + 1];
	}

	Size--;
}

int main()
{
	enqueue(10, 2);
	enqueue(14, 4);
	enqueue(16, 4);
	enqueue(12, 3);

	int ind = peek();

	cout << pr[ind].value << endl;

	dequeue();

	ind = peek();
	cout << pr[ind].value << endl;

	dequeue();

	ind = peek();
	cout << pr[ind].value << endl;

	return 0;
}
