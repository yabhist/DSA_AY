#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number

int gaussJordan (vector < vector<double> > a, vector<double> & ans) {
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

        for (int i=0; i<n; ++i)
            if (i != row && abs(a[i][col])>eps) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (lead[i] != -1)
            ans[i] = a[lead[i]][m] / a[lead[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > eps)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (lead[i] == -1)
            return INF;
    return 1;
}

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

    ans.assign (m, 0);
    
    for (int i=m-1; i>=0; i--){
        if (lead[i] != -1){
            double sum=0;
            for(int j=m-1;j>i;j--){
                sum+=ans[j]*a[lead[i]][j];
            }
            ans[i]=(a[lead[i]][m]-sum)/a[lead[i]][i];
        }
    }
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > eps)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (lead[i] == -1)
            return INF;
    return 1;
}