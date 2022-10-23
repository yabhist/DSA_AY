#include<bits/stdc++.h>
using namespace std;
#define NMAX 200010

int segtree[4*NMAX];
void build_segtree(int a[],int low, int high, int pos)
{
    if(low==high)
    {
        segtree[pos]=a[low];
    }
    else
    {
        int mid=(low+high)/2;
        build_segtree(a,low,mid,2*pos+1);
        build_segtree(a,mid+1,high,2*pos+2);
        segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
    }
}
int query(int ql, int qr, int low, int high, int pos)
{
    if(ql>high || qr<low)
    {
        return INT_MAX;
    }
    if(low>=ql && high<=qr)
    {
        return segtree[pos];
    }
    int mid=(low+high)/2;
    return min(query(ql,qr,low,mid,2*pos+1),query(ql,qr,mid+1,high,2*pos+2));
}
void update(int a[],int i, int val, int low, int high, int pos)
{
    if(low==high)
    {
        a[i]=val;
        segtree[pos]=val;
    }
    else
    {
        int mid=(low+high)/2;
        if(i<=mid)
        {
            update(a,i,val,low,mid,2*pos+1);
        }
        else
        {
            update(a,i,val,mid+1,high,2*pos+2);
        }
        segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
    }
}
int main()
{
    int arr[] = {1, 3, 2, -7, 9, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    build_segtree(arr,0,n-1,0);
    cout<<query(2,4,0,n-1,0)<<'\n';
    update(arr,3,17,0,n-1,0);
    cout<<query(2,4,0,n-1,0)<<'\n';
}