#include<bits/stdc++.h>
using namespace std;
void mxsbarsm(int a[], int n)
{
    int max_end=0, max_now=INT_MIN;
    int start=0,end=0,s=0;
    for(int i=0;i<n;i++)
    {
        max_end+=a[i];
        if(max_now < max_end)
        {
            max_now=max_end;
            start=s;
            end=i;
        }
        if(max_end<0)
        {
            max_end=0;
            s=i+1;
        }
    }
    cout<<start<<' '<<end<<' '<<max_now<<'\n';
}
int main()
{
    int a[]={1,-5,7,-4,-6,3,2,-4,6,-3,2};
    int n=sizeof(a)/sizeof(a[0]);
    mxsbarsm(a,n);
}