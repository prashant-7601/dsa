#include<bits/stdc++.h>
using namespace std;
#define int long long

// memoization
map<string, bool> memo;

bool canConstruct(string str, vector<string> arr){
    if(memo.find(str)!=memo.end())
        return memo[str];
    for(auto s: arr){
        if(s == str){
            memo[s] = true;
            return true;
        }
        else if(s.length() < str.length() && str.substr(0, s.length())==s){
            string temp = str.substr(s.length(), str.length());
            memo[str] = canConstruct(temp, arr);
            if(memo[str])
                return true;
        }
    }
    return false;
}

int32_t main(){
    string str = "prashant";
    vector<string> arr = {"pr", "ash", "nt", "pra", "ant", "t"};
    //cout<<canConstruct(str, arr);
    int n = str.length();
    bool dp[n+1] = {false};
    dp[0] = true;
    for(int i=0; i<=n; i++){
        if(dp[i]){
            for(auto word: arr){
                if(i+word.length()<=n && str.substr(i, word.length())==word){
                    dp[i+word.length()] = true;
                }
            }
        }
    }
    cout<<dp[n];
}

