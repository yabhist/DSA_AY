#include<bits/stdc++.h>
using namespace std;

double divided_difference_method(vector<double>&d,vector<double>&x, int n, double x_){
    double u=d[n];
    for(int i=n-1;i>=0;i--){
        u=u*(x_-x[i])+d[i];
    }
    return u;
}
void calc_cij(vector<vector<double>>&c,vector<double>&x,int n){
    for(int j=1;j<=n;j++){
        for( int i=0;i<=n-j;i++){
            c[i][j]=(c[i+1][j-1]-c[i][j-1])/(x[i+j]-x[i]);
        }
    }
}
void calc_di(vector<double>&d,vector<double>&x, int n){
    for(int j=1;j<=n;j++){
        double tm=d[j-1];
        for( int i=j;i<=n;i++){
            double tm2=tm;
            tm=d[i];
            d[i]=(d[i]-tm2)/(x[i]-x[i-j]);
        }
    }
}
int main(){
    cout<<fixed<<setprecision(10);
    int n;
    cin>>n;
    vector<vector<double>>c(n+1,vector<double>(n+1));
    vector<double>d(n+1);
    vector<double>x(n+1);
    vector<double>y(n+1);
    for(int i=0;i<=n;i++){
        cin>>x[i]>>y[i];
        c[i][0]=y[i];
        d[i]=y[i];
    }
    calc_cij(c,x,n);
    calc_di(d,x,n);
    cout<<(c[0]==d)<<'\n';
    bool is=1;
    for(int i=0;i<=n;i++){
        int tm=c[0][i]*10000+0.5;
        int tm2=d[i]*10000+0.5;
        if((double)tm/10000!=(double)tm2/10000){
            is=0;
            break;
        }
    }
    cout<<is<<'\n';
    cout<<divided_difference_method(d,x,n,1);
}