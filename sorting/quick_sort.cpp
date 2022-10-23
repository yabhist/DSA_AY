#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int low, int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quick_sort(int a[], int low, int high)
{
    if(low<high)
    {
        int par=partition(a,low,high);
        quick_sort(a,low,par-1);
        quick_sort(a,par+1,high);
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
    quick_sort(arr,0,n-1);
    cout << "sorted array: \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}