#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;
int iter=100;

pair<double,double> system(double x, double y){
    return {y*cos(x*y)+1,sin(x*y)+x-y};
}
pair<double,double> h(double x, double y){
    
    double f1x=y*(-sin(x*y))*y;
    double f1y=cos(x*y)+y*(-sin(x*y))*x;
    double f2x=cos(x*y)*y+1;
    double f2y=cos(x*y)*x-1;

    double det=f1x*f2y-f2x*f1y;
    vector<vector<double>> jacobian_inverse={{f2y/det,-f1y/det},{-f2x/det,f1x/det}};

    pair<double,double> f=system(x,y), ans;

    ans.first=-(jacobian_inverse[0][0]*f.first+jacobian_inverse[0][1]*f.second);
    ans.second=-(jacobian_inverse[1][0]*f.first+jacobian_inverse[1][1]*f.second);

    return ans;

}
void newtonRaphsonSystem(double x , double y){
    int ct=0;
	while (iter--)
	{
        pair<double,double> val=system(x,y);
        if(abs(val.first)<=eps && abs(val.second)<=eps) break;
        pair<double,double> add=h(x,y);
        x = x + add.first;
        y = y + add.second;
        ct++;
	}
	cout << "x : " << x<< ", y : " << y<<'\n';
    cout<<"iterations : "<<ct<<'\n';
}
int main(){
    cout<<fixed<<setprecision(10);
    double x0=0.6;
    double y0=1.6;
    newtonRaphsonSystem(x0,y0);
}