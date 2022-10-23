#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[],int n)
{
    int min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                min=j;
            }
        }
        swap(a[i],a[min]);
    }
}
void selection_sort1(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
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
    selection_sort(arr, n);
    cout << "sorted array: \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    
}