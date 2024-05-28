#include<bits/stdc++.h>
using namespace std;
bool kmp(string needle, string haystack){
    int m=needle.size();
    int n=haystack.size();
    if(n<m){
        return false;
    }
    vector<int> lps(m);
    int prev=0;
    int i=1;
    while(i<m){
        if(needle[i]==needle[prev]){
            prev+=1;
            lps[i]=prev;
            i+=1;
        }
        else{
            if(prev==0){
                i+=1;
            }
            else{
                prev=lps[prev-1];
            }
        }
    }
    int j=0;
    i=0;
    while(j<n){
        if(haystack[j]==needle[i]){
            j+=1;
            i+=1;
            if(i==m){
                return true;
            }
        }
        else{
            if(i==0){
                j+=1;
            }
            else{
                i=lps[i-1];
            }
        }
    }
    return false;
}
/*
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
*/
int main(){
    
}