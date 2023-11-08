#include<bits/stdc++.h>
using namespace std;

double a,b;
double func(double x){
    return 1/(3+x);
}
double tranformedFunc(double t){
    double x=(a+b+t*(b-a))/2;
    return (b-a)*func(x)/2;
}
double legOnePt(){
    return 2*tranformedFunc(0);
}
double legTwoPt(){
    return tranformedFunc(-1/sqrt(3))+tranformedFunc(1/sqrt(3));
}
double legThreePt(){
    return (5*tranformedFunc(-sqrt(3.0/5))+8*tranformedFunc(0)+5*tranformedFunc(sqrt(3.0/5)))/9;
}
int main(){
    cout<<fixed<<setprecision(10);
    cin>>a>>b;
    cout<<legOnePt()<<'\n';
    cout<<legTwoPt()<<'\n';
    cout<<legThreePt()<<'\n';
}