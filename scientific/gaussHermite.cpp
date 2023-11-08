#include<bits/stdc++.h>
using namespace std;

const double pi=2*acos(0.0);
//-infinity to infinity
double func(double x){
    return 1/(1+x*x);//e^(-x^2) * ()
}

double hermOnePt(){
    return sqrt(pi)*func(0);
}
double hermTwoPt(){
    return sqrt(pi)*(func(-1/sqrt(2))+func(1/sqrt(2)))/2;
}
double hermThreePt(){
    return sqrt(pi)*(func(sqrt(3.0/2))+4*func(0)+func(sqrt(3.0/2)))/6;
}
	
	
int main(){
    cout<<fixed<<setprecision(10);
    cout<<hermOnePt()<<'\n';
    cout<<hermTwoPt()<<'\n';
    cout<<hermThreePt()<<'\n';
}