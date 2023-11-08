#include<bits/stdc++.h>
using namespace std;
double lagrange(vector<double>&x,vector<double>&y,int n, double x_){
    vector<double>l(n+1);
    double ans=0;
    for(int i=0;i<=n;i++){
        l[i]=1;
        for(int j=0;j<=n;j++){
            if(i==j) continue;
            l[i]*=(x_-x[j])/(x[i]-x[j]);
        }
        ans+=l[i]*y[i];
    }
    return ans;
}
int main(){
    cout<<fixed<<setprecision(10);
    int n;
    cin>>n;
    vector<double>x(n+1);
    vector<double>y(n+1);
    for(int i=0;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    cout<<lagrange(x,y,n,1)<<'\n';
}