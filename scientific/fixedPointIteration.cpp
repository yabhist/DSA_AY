#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;
int iter=1000;

double func(double x){
    return x*x*x-5*x*x+4*x-3;
}
double phi1(double x){
    return pow(5*x*x-4*x+3,1.0/3);
}
double phi2(double x){
    return 5-4/x+3/(x*x);
}

void fixedPointIteration1(double x){
    int ct=0;
    iter=1000;
    while(iter--){
        if(abs(func(x))<=eps) break;
        x=phi1(x);
        ct++;
    }
    cout<<"root : "<<x<<'\n';
    cout<<"iterations : "<<ct<<'\n';
}
void fixedPointIteration2(double x){
    int ct=0;
    iter=1000;
    while(iter--){
        if(abs(func(x))<=eps) break;
        x=phi2(x);
        ct++;
    }
    cout<<"root : "<<x<<'\n';
    cout<<"iterations : "<<ct<<'\n';
}

int main(){
    cout<<fixed<<setprecision(10);
    double x0=7;
    fixedPointIteration1(x0);
    fixedPointIteration2(x0);
}