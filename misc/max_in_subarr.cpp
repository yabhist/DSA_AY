#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    vector<ll>v={45,32,15,32,32,23,55,45};
    ll n=v.size();
    vector<pair<ll,ll>>res(n,{-1,n});
    stack<ll>st;
    for( ll i=0;i<n;i++)
    {
        while(!st.empty() && v[st.top()]<v[i])
        {
            res[st.top()].second=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop();
    }
    for( ll i=n-1;i>=0;i--)
    {
        while(!st.empty() && v[st.top()]<v[i])
        {
            res[st.top()].first=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop();
    }
    for(auto i:res)
    {
        cout<<i.first+1<<' '<<i.second-1<<'\n';
    }
}