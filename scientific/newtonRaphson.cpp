#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;
int iter=1000;

double func(double x)
{
	return x*x*x - x*x + 2;
}

double derivFunc(double x)
{
	return 3*x*x - 2*x;
}

void newtonRaphson(double x)
{
    int ct=0;
    double h=0;
	while (iter--)
	{
        if(abs(func(x))<=eps) break;
		h = func(x)/derivFunc(x);
		x = x - h;
        ct++;
	}
    
	cout << "root : " << x<<'\n';
    cout<<"iterations : "<<ct<<'\n';
}

int main()
{
    cout<<fixed<<setprecision(10);
	double x0 = 20;
	newtonRaphson(x0);

	return 0;
}
