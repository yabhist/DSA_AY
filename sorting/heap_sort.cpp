#include<bits/stdc++.h>
using namespace std;


void heapify(int arr[], int n, int i);
void build_heap(int arr[],int n);
void heap_sort(int arr[], int n);
void print_array(int arr[],int n);


int main()
{
    int a[10]={-1,23,1,33,45,21,99,65,3,56};//1-based indexing
    print_array(a,9);
    build_heap(a,9);
    print_array(a,9);
    heap_sort(a,9);
    print_array(a,9);
}

void heap_sort(int arr[], int n)
{
    int size=n;
    while(size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
void build_heap(int arr[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        heapify(arr,n,i);
    }
}
void heapify(int arr[], int n, int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[largest]<arr[left])
    {
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void print_array(int arr[],int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<' ';
    }cout<<'\n';
}
