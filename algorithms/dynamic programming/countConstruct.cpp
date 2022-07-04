#include<bits/stdc++.h>
using namespace std;
#define int long long

// memoization
map<string, int> memo;

int countConstruct(string str, vector<string> arr){
    if(memo.find(str)!=memo.end())
        return memo[str];
    int count=0;
    for(auto s: arr){
        if(s == str)
            count = 1;
        else if(s.length() < str.length() && str.substr(0, s.length())==s){
            string temp = str.substr(s.length(), str.length());
            count += countConstruct(temp, arr);
        }
    }
    memo[str] = count;
    return memo[str];
}

int32_t main(){
    string str = "aba";
    vector<string> arr = {"acca","bbbb","caca"};
    //cout<<countConstruct(str, arr);
    int n = str.length();
    pair<bool, int> dp[n+1];
    dp[0] = make_pair(true, 1);
    for(int i=1; i<=n; i++) dp[i] = make_pair(false, 0);
    for(int i=0; i<=n; i++){
        if(dp[i].first){
            for(auto word: arr){
                if(i+word.length()<=n && str.substr(i, word.length())==word){
                    dp[i+word.length()].first = true;
                    dp[i+word.length()].second += dp[i].second;
                }
            }
        }
    }
    cout<<dp[n].second;
}


