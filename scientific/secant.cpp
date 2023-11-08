#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;
int iter=100;

double func(double x){
    return exp(-x)*(x*x+5*x+2)+1;
}
void secant(double x1, double x2){
    int ct=0;
    double x;
    while(iter--){
        x=x2-func(x2)*(x2-x1)/(func(x2)-func(x1));
        if(abs(func(x))<=eps) break;
        x1=x2;
        x2=x;
        ct++;
    }
    cout<<"root : "<<x<<'\n';
    cout<<"iterations : "<<ct<<'\n';
}
int main(){
    cout<<fixed<<setprecision(10);
    double x1=-64,x2=-50;
    secant(x1,x2);
    x1=-3,x2=-2;
    secant(x1,x2);
}