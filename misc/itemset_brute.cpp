#include<bits/stdc++.h>
using namespace std;

class freq{
    vector<vector<int>> v;
    int n;
    int m;
    int mn;
    int compute_support(int val){
        int sup=0;
        for(int i=0;i<n;i++){
            bool is=1;
            for(int j=0;j<m;j++){
                if((val&(1<<j)) && v[i][j]==0){
                    is=0;
                    break;
                }
            }
            if(is){
                sup++;
            }
        }
        return sup;
    }
public:
    freq(vector<vector<int>>& input, int mn){
        v=input;
        n=v.size();
        m=v[0].size();
        this->mn=mn;
    }
    void brute(){
        vector<pair<int,int>>f;
        for(int i=0;i<(1<<m);i++){
            int sup=compute_support(i);
            if(sup>=mn){
                f.push_back({i,sup});
            }
        }
        for(auto i:f){
            cout<<i.first<<' '<<i.second<<'\n';
        }
    }
};
int main(){
    vector<vector<int>> v={{1,1,0,1,1},{0,1,1,0,1},{1,1,0,1,1},{1,1,1,0,1},{1,1,1,1,1},{0,1,1,1,0}};
    freq F(v,3);
    F.brute();
}