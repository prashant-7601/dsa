#include<bits/stdc++.h>
using namespace std;
#define int long long

// memoization
map<int, bool> memo;

bool canSum(int n, vector<int> arr){
    if(n==0) return true;
    if(memo.find(n)!=memo.end())
        return memo[n];
    for(auto num: arr){
        if(num == n){
            memo[n] = true;
            return true;
        }
        else if(num < n){
            memo[n] = false;
            memo[n] = canSum(n-num, arr);
            if(memo[n]) return true;
        }
    }
    return memo[n];
}

int32_t main(){
    int n = 7;
    vector<int> arr = {2, 4};
    //cout<<canSum(n, arr);
    bool dp[n+1]={false};
    dp[0] = true;
    for(int i=0; i<=n; i++){
        if(dp[i]){
            for(auto weight: arr){
                if(i+weight<=n) dp[i+weight] = true;
            }
        }
    }
    cout<<dp[n];
}
