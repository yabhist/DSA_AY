#include<bits/stdc++.h>
using namespace std;

int n=3;
int k=3;
vector<int>a={1,2,3};
vector<vector<int>>p(k);
vector<vector<vector<int>>>store;
void recur(int ob){
    if(ob==n){
        store.push_back(p);
        return;
    }

    for(int i=0;i<k;i++){
        p[i].push_back(a[ob]);
        recur(ob+1);
        p[i].pop_back();
    }
}

int main(){
    recur(0);
    cout<<store.size()<<'\n';
    for(auto vv : store){
        for(int i=0;i<k;i++){
            if(vv[i].empty()){
                cout<<"phi,";
            }
            else{
                cout<<"[ ";
                for(auto j:vv[i]){
                    cout<<j<<' ';
                }cout<<"],";
            }
        }cout<<'\n';
    }
}
