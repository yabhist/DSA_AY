#include<bits/stdc++.h>
using namespace std;
class Mat {
    using ll=long long;

    ll row, col;
    vector<vector<ll>>v;


public:
    Mat(ll r=0, ll c=0) {
        row = r, col = c;
        v.assign(r,vector<ll>(c,0));
    }

    Mat operator * (const Mat &p) const {
        assert(col == p.row);

        Mat ret(row, p.col);
        for(ll i=0; i<ret.row; ++i) {
            for(ll j=0; j<ret.col; ++j) {
                ll& sum = ret.v[i][j];
                for(ll k=0; k<col; ++k) {
                    sum += v[i][k] * p.v[k][j];
                }
            }
        }

        return ret;
    }

    Mat power (ll p) {
        assert(row == col);

        Mat base = *this;
        Mat ret(row, col);
        for(ll i=0; i<row; ++i) ret.v[i][i] = 1;

        while(p > 0) {
            if(p & 1) ret =ret* base;
            base = base * base;
            p >>= 1;
        }

        return ret;
    }
};
signed main(){
    
}