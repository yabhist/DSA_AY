#include<bits/stdc++.h>
using namespace std;

double func(double x){
    return 1/(1+x*x);
}
int main(){
    cout<<fixed<<setprecision(10);
    double lower,upper,subinterval;
    cin>>lower>>upper>>subinterval;
    double integral=0;
    double stepsize=(upper-lower)/subinterval;
    integral=func(upper)+func(lower);
    for(int i=1;i<=subinterval-1;i++){
        double k=lower+i*stepsize;
        integral+=2*func(k);
    }
    integral*=stepsize/2;
    cout<<integral<<'\n';
}