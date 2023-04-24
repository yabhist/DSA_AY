#include <bits/stdc++.h>
using namespace std;

int H[50];
int Size = -1;

int parent(int i)
{

	return (i - 1) / 2;
}

int leftChild(int i)
{

	return ((2 * i) + 1);
}

int rightChild(int i)
{

	return ((2 * i) + 2);
}

void shiftUp(int i)
{
	while (i > 0 && H[parent(i)] < H[i]) {

		swap(H[parent(i)], H[i]);
		i = parent(i);
	}
}

void shiftDown(int i)
{
	int maxIndex = i;

	int l = leftChild(i);

	if (l <= Size && H[l] > H[maxIndex]) {
		maxIndex = l;
	}

	int r = rightChild(i);

	if (r <= Size && H[r] > H[maxIndex]) {
		maxIndex = r;
	}

	if (i != maxIndex) {
		swap(H[i], H[maxIndex]);
		shiftDown(maxIndex);
	}
}

void insert(int p)
{
	Size = Size + 1;
	H[Size] = p;
	shiftUp(Size);
}

int extractMax()
{
	int result = H[0];
	H[0] = H[Size];
	Size = Size - 1;

	shiftDown(0);
	return result;
}


void changePriority(int i, int p)
{
	int oldp = H[i];
	H[i] = p;

	if (p > oldp) {
		shiftUp(i);
	}
	else {
		shiftDown(i);
	}
}

int getMax()
{

	return H[0];
}

void remove(int i)
{
	H[i] = getMax() + 1;
	shiftUp(i);
	extractMax();
}

int main()
{

	/*		 45
			/	\
		  31	 14
		 / \     / \
		13 20    7 11
		/ \
	   12 7

	45 31 14 13 20 7 11 12 7 */

	insert(45);
	insert(20);
	insert(14);
	insert(12);
	insert(31);
	insert(7);
	insert(11);
	insert(13);
	insert(7);

	int i = 0;
	cout << "Priority Queue : ";
	while (i <= Size) {
		cout << H[i] << " ";
		i++;
	}

	cout << "\n";

	cout << "Node with maximum priority : "
		<< extractMax() << "\n";

	cout << "Priority queue after "
		<< "extracting maximum : ";
	int j = 0;
	while (j <= Size) {
		cout << H[j] << " ";
		j++;
	}

	cout << "\n";

	changePriority(2, 49);
	cout << "Priority queue after "
		<< "priority change : ";
	int k = 0;
	while (k <= Size) {
		cout << H[k] << " ";
		k++;
	}

	cout << "\n";

	remove(3);
	cout << "Priority queue after "
		<< "removing the element : ";
	int l = 0;
	while (l <= Size) {
		cout << H[l] << " ";
		l++;
	}
	return 0;
}
