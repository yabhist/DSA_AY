#include<bits/stdc++.h>
using namespace std;
const int n=2;
double hermite(vector<double>&x,vector<double>&y,vector<double>&z, double x_){
    double l,l_dash;
    double ans1=0,ans2=0;
    for(int i=0;i<=n;i++){
        l=1;
        l_dash=1;
        double tm=0;
        for(int j=0;j<=n;j++){
            if(i==j) continue;
            l*=(x_-x[j])/(x[i]-x[j]);
            l_dash*=1/(x[i]-x[j]);
            tm+=x_-x[j];
        }
        l_dash*=tm;
        ans1+=y[i]*l*l*(1-2*(x_-x[i])*l_dash);
        ans2+=z[i]*l*l*(x_-x[i]);
    }
    return ans1+ans2;
}
int main(){
    cout<<fixed<<setprecision(10);
    vector<double>x(n+1);
    vector<double>y(n+1);
    vector<double>z(n+1);
    for(int i=0;i<=n;i++){
        cin>>x[i]>>y[i]>>z[i];
    }
    cout<<hermite(x,y,z,0)<<'\n';
}