#include<bits/stdc++.h>
using namespace std;
void swp(char &a, char &b){
    char tmp=a;
    a=b;
    b=tmp;
}
void  rev(string&s){
    for(int i=0;i<s.size()/2;i++){
        swp(s[i],s[s.size()-i-1]);
    }
}
string toString(int k){
    string s="";
    if(k==0){
        return "0";
    }
    bool is=false;
    if(k<0){
        is=true;
        k*=-1;
    }
    while(k>0){
        s+=(k%10)+'0';
        k/=10;
    }
    if(is){
        s+='-';
    }
    rev(s);
    return s;
}

int stri(string s){
    int k=0;
    if(s[0]=='-'){
        for(int i=1;i<s.size();i++){
            k=k*10+s[i]-'0';
        }
        k*=-1;
    }
    else{
        for(int i=0;i<s.size();i++){
            k=k*10+s[i]-'0';
        }
    }
    return k;
}

int main(){
    int k=987;
    string s=toString(k);
    cout<<s<<' '<<s[0]<<'\n';
    k=-987;
    s=toString(k);
    cout<<s<<' '<<s[1]<<'\n';

    s="987";
    k=stri(s);
    cout<<k<<' '<<k-978<<'\n';
    s="-987";
    k=stri(s);
    cout<<k<<' '<<k+996<<'\n';
}