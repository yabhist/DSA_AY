#include<bits/stdc++.h>
using namespace std;

const double pi=2*acos(0.0);
double a,b;
double func(double x){
    return 1/sqrt(1-x*x);

}
double tranformedFunc(double t){
    double x=(a+b+t*(b-a))/2;
    return sqrt(1-t*t)*(b-a)*func(x)/2;
}
double ChebyOnePt(){
    return pi*tranformedFunc(0);
}
double ChebyTwoPt(){
    return pi*(tranformedFunc(-1/sqrt(2))+tranformedFunc(1/sqrt(2)))/2;
}
double ChebyThreePt(){
    return pi*(tranformedFunc(-sqrt(3)/2)+tranformedFunc(0)+tranformedFunc(sqrt(3)/2))/3;
}
int main(){
    cout<<fixed<<setprecision(10);
    cin>>a>>b;
    cout<<ChebyOnePt()<<'\n';
    cout<<ChebyTwoPt()<<'\n';
    cout<<ChebyThreePt()<<'\n';
}