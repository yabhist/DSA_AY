#include<bits/stdc++.h>
using namespace std;
struct store
{
    int s;
    int e;
    int maxsum;
};
store find_cross(int a[],int l,int m, int r)
{
    int leftsum=INT_MIN;
    int sum=0;
    int lefti;
    for(int i=m;i>=l;i--)
    {
        sum+=a[i];
        if(sum > leftsum)
        {
            leftsum=sum;
            lefti=i;
        }
    }
    int rightsum=INT_MIN;
    sum=0;
    int righti;
    for(int i=m+1;i<=r;i++)
    {
        sum+=a[i];
        if(sum > rightsum)
        {
            rightsum=sum;
            righti=i;
        }
    }
    return {lefti,righti,leftsum+rightsum};
}
store find_msa(int a[],int l, int r)
{
    if(l==r)
    {
        return {l,r,a[l]};
    }
    int m=l+(r-l)/2;
    store s1=find_msa(a,l,m);
    store s2=find_msa(a,m+1,r);
    store s3=find_cross(a,l,m,r);
    if(s1.maxsum>=s2.maxsum && s1.maxsum>=s3.maxsum)
    {
        return s1;
    }
    else if(s2.maxsum>=s1.maxsum && s2.maxsum>=s3.maxsum)
    {
        return s2;
    }
    return s3;
}
int main()
{
    int a[]={1,-5,7,-4,-6,3,2,-4,6,-3,2};
    int n=sizeof(a)/sizeof(a[0]);
    store ans=find_msa(a,0,n-1);
    cout<<ans.s<<' '<<ans.e<<' '<<ans.maxsum<<'\n';
}