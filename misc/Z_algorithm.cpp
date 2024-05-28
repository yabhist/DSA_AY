#include<bits/stdc++.h>
using namespace std;
void getZarr(string str, vector<int>&z);
void search(string text, string pattern){
    string concat=pattern;
    concat.append("$");
    concat.append(text);
    int n=concat.length();
    vector<int>z(n);
    getZarr(concat,z);
    for(int i=0;i<n;i++){
        if (z[i] == pattern.length()){
            cout<<"Pattern found at index "<<i - pattern.length() -1<<'\n';
        }
    }
}
void getZarr(string str, vector<int>&z){
    int n=str.length();
    int l,k,r;
    l=r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && str[r-l]==str[r]){
                r++;
            }
            z[i]=r-l;
            r--;
        }
        else{
            k=i-l;
            if(z[k]<r-i+1){
                z[i]=z[k];
            }
            else{
                l=i;
                while(r<n && str[r-l]==str[r]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
        }
    }
}
/*
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
*/
int main()
{
    string text = "abcdexxkiabcniabdlaiabc";
    string pattern = "abc";
    search(text, pattern);
    return 0;
}