#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[low + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0; 
    j = 0; 
	k = low; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[], int low, int high)
{
	if (low < high) {
		int mid = low + (high - low) / 2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "original array: \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    merge_sort(arr, 0,n-1);
    cout << "sorted array: \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}
