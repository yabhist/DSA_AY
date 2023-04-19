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
int main(){
    
}