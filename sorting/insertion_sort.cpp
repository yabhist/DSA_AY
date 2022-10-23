#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>a[key])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
void insertion_sort1(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>a[key])
        {
            swap(a[j+1],a[j]);
            j--;
        }
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
    insertion_sort(arr, n);
    cout << "sorted array: \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    
}