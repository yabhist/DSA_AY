#include<bits/stdc++.h>
using namespace std;

struct manacher{
    vector<int>p;
    void build(string s){
        string t="";
        for(auto i:s){
            t+=string("#")+i;
        }
        t+='#';
        int n=t.length();
        p.assign(n+2,0);//p.assign(n,1);
        t="$"+t+"^";//t=t;
        int l=1,r=1;
        for(int i=1;i<=n;i++){//1,<n
            p[i]=max(0,min(r-i,p[l+r-i]));//l+r-i>=0?p[l+r-i]:0;
            while(t[i+p[i]]==t[i-p[i]]){//i+p[i]<n && i-p[i]>=0
                p[i]++;
            }
            if(i+p[i]>r){
                l=i-p[i];
                r=i+p[i];
            }
        }
        p=vector<int>(p.begin()+1,p.end()-1);//p=p;
        return;
    }
    int get_longest(int cen, bool odd){
        int pos=2*cen+1+(!odd);
        return p[pos]-1;
    }
    bool check_palin(int l, int r){
        if((r-l+1)<=get_longest((l+r)/2,(l%2==r%2))){
            return true;
        }
        return false;
    }
};

int main(){
    manacher m;
    string s="babbabbabc";
    m.build(s);
    vector<int>lps=m.p;
    for(auto i:lps){
        cout<<i<<' ';
    }cout<<'\n';
    cout<<m.get_longest(4,1)<<'\n';
    cout<<m.check_palin(1,4)<<'\n';
}