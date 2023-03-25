#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    vector<ll>v={45,32,15,77,32,23,55,45};
    ll n=v.size();
    vector<pair<ll,ll>>res(n,{n,-1});
    stack<ll>st;
    for( ll i=0;i<n;i++)
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
    for( ll i=n-1;i>=0;i--)
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
    for(auto i:res)
    {
        cout<<i.second+1<<' '<<i.first-1<<'\n';
    }
}