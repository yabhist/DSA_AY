#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;
int iter=10000;

double func(double x){
    return x*exp(1-x)-1;
}
double derivFunc(double x){
	return exp(1-x)*(1-x);
}
double doubleDerivFunc(double x){
    return -2*exp(1-x)+x*exp(1-x);
}

void newtonRaphson(double x)
{
    int ct=0;
    double h=0;
    time_t start,end;
    time(&start);
	while (iter--)
	{
        if(abs(func(x))<=eps) break;
		h = func(x)/derivFunc(x);
		x = x - h;
        cout<<x<<'\n';
        ct++;
	}
    time(&end);
	cout << "root : " << x<<'\n';
    cout<<"iterations : "<<ct<<'\n';
    cout<<"time : "<<double(end-start)<<" sec\n";
}
void modifiedNewtonRaphson(double x)
{
    int ct=0;
    double h=0;
    time_t start,end;
    time(&start);
	while (iter--)
	{
        if(abs(func(x))<=eps) break;
        double zero=func(x);
        double one=derivFunc(x);
        double two=doubleDerivFunc(x);
		h = (zero*one)/(one*one-zero*two);
		x = x - h;
        cout<<x<<'\n';
        ct++;
	}
    time(&end);
	cout << "root : " << x<<'\n';
    cout<<"iterations : "<<ct<<'\n';
    cout<<"time : "<<double(end-start)<<" sec\n";
}
int main(){
    cout<<fixed<<setprecision(10);
	double x0 = 9;
	newtonRaphson(x0);
    modifiedNewtonRaphson(x0);
}



