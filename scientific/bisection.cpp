#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;
int iter=100;

double func(double x)
{
    return x*x*x - x*x + 2;
}
 
void bisection(double a, double b)
{
    double c = a;
    int ct=0;
    while (iter--)
    {
        c = (a+b)/2;
        if (abs(func(c)) <= eps) break;
        else if (func(c)*func(a) < 0) b = c;
        else a = c;
        ct++;
    }
    cout<<"root : "<<c<<'\n';
    cout<<"iterations : "<<ct<<'\n';
}
int main(){
    cout<<fixed<<setprecision(10);
    double a =-200, b = 300;
    bisection(a, b);
    return 0;
}