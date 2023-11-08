#include<bits/stdc++.h>
using namespace std;

//0 to infinity
double func(double x){
    return 1/(1+x*x);//e^-x * ()
}

double laguOnePt(){
    return func(1);
}
double laguTwoPt(){
    return ((2+sqrt(2))*func(2-sqrt(2))+(2-sqrt(2))*func(2+sqrt(2)))/4;
}
double laguThreePt(){
    return 0.711093*func(0.415775)+0.278518*func(2.29428)+0.0103893*func(6.28995);
}
	
	
int main(){
    cout<<fixed<<setprecision(10);
    cout<<laguOnePt()<<'\n';
    cout<<laguTwoPt()<<'\n';
    cout<<laguThreePt()<<'\n';
}