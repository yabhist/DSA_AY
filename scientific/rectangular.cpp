#include<bits/stdc++.h>
using namespace std;

double func(double x){
    return 1;
}
int main(){
    cout<<fixed<<setprecision(10);
    double lower,upper,subinterval;
    cin>>lower>>upper>>subinterval;
    double integral=0;
    double stepsize=(upper-lower)/subinterval;
    for(int i=0;i<subinterval;i++){
        double k=lower+i*stepsize;
        integral+=func(k);
    }
    integral*=stepsize;
    cout<<integral<<'\n';
}