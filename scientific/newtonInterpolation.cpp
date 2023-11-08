#include<bits/stdc++.h>
using namespace std;

double horner(vector<double>&c,vector<double>&x, int n, double x_){
    double u=c[n];
    for(int i=n-1;i>=0;i--){
        u=u*(x_-x[i])+c[i];
    }
    return u;
}
void calc_coeff(vector<double>&c,vector<double>&x,vector<double>&y,int n){
    c[0]=y[0];
    for(int k=1;k<=n;k++){
        double d=x[k]-x[k-1];
        double u=c[k-1];
        for( int i=k-2;i>=0;i--){
            u=u*(x[k]-x[i])+c[i];
            d=d*(x[k]-x[i]);
        }
        c[k]=(y[k]-u)/d;
    }
}
void print_polynomial(vector<double>&c, vector<double>&x, int k){
    if(k==0){
        cout<<c[0]<<'\n';
        return;
    }
    cout<<c[k];
    for(int i=k-1;i>=0;i--){
        if(x[i]==0){
            cout<<'x';
            continue;
        }
        char ch=(x[i]<0)?'+':'-';
        cout<<"(x"<<ch<<abs(x[i])<<')';
    }
    cout<<" + ";
    print_polynomial(c,x,k-1);
}
int main(){
    cout<<fixed<<setprecision(10);
    int n;
    cin>>n;
    vector<double>c(n+1);
    vector<double>x(n+1);
    vector<double>y(n+1);
    for(int i=0;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    calc_coeff(c,x,y,n);
    print_polynomial(c,x,n);
    cout<<horner(c,x,n,1)<<'\n';
}