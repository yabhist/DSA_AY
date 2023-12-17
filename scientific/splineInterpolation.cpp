#include<bits/stdc++.h>
using namespace std;

int gauss(vector < vector<double> > a, vector<double> & ans) {
    const double eps = 1e-9;
    const int INF = 2;
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> lead (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < eps)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        lead[col] = row;

        for (int i=row+1; i<n; ++i)
            if (abs(a[i][col])>eps) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }
    
    for (int i=m-1; i>=0; i--){
        if (lead[i] != -1){
            double sum=0;
            for(int j=m-1;j>i;j--){
                sum+=ans[j+1]*a[lead[i]][j];
            }
            ans[i+1]=(a[lead[i]][m]-sum)/a[lead[i]][i];
        }
    }
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j+1] * a[i][j];
        if (abs (sum - a[i][m]) > eps)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (lead[i] == -1)
            return INF;
    return 1;
}
void cubic_spline(int n,vector<double>&x,vector<double>&y,vector<double>&M){
    vector<vector<double>>a(n-1,vector<double>(n));
    for(int i=1;i<=n-1;i++){
        int j=i-1;
        if(j-1>=0){
            a[i-1][j-1]=(x[i]-x[i-1])/6;
        }
        j=i;
        a[i-1][j-1]=(x[i+1]-x[i-1])/3;
        j=i+1;
        if(j-1<=n-2){
            a[i-1][j-1]=(x[i+1]-x[i])/6;
        }

        a[i-1][n-1]=(y[i+1]-y[i])/(x[i+1]-x[i]) - (y[i]-y[i-1])/(x[i]-x[i-1]);
    }



}
int main(){
    int n;
    cin>>n;
    vector<double>x(n+1);
    vector<double>y(n+1);
    vector<double>M(n+1);
    for(int i=0;i<=n;i++){
        cin>>x[i]>>y[i];
    }
}