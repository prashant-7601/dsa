#include<bits/stdc++.h>
using namespace std;
#define int long long

// memoization
map<int, vector<int>> memo;

vector<int> howSum(int n, vector<int> arr){
    if(n<0) return {};
    if(memo.find(n)!=memo.end())
        return memo[n];
    for(auto num: arr){
        if(n==num){
            memo[n] = {num};
            return memo[n];
        }
        vector<int> res = howSum(n-num, arr);
        if(res.size()!=0){
            res.push_back(num);
            memo[n] = res;
            return memo[n];
        }
    }
    return memo[n];
}

int32_t main(){
    int n = 6;
    vector<int> arr = {2, 4};
    //vector<int> res = howSum(n, arr);
    //for(auto num: res) cout<<num<<" ";
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++) dp[i] = -1;
    for(int i=0; i<=n; i++){
        if(dp[i]!=-1){
            for(auto weight: arr){
                if(i+weight<=n) {
                    dp[i+weight] = i;
                }
            }
        }
    }
    while(n!=0){
        cout<<n - dp[n]<<" ";
        n = dp[n];
    }
}

