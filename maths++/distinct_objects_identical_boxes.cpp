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
    for(auto&vv : store){
        sort(vv.begin(),vv.end());
    }
    set<vector<vector<int>>>store2;
    for(auto&vv : store){
        store2.insert(vv);
    }
    for(auto&vv : store2){
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
