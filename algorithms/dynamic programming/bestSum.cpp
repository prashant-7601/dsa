#include<bits/stdc++.h>
using namespace std;
#define int long long

// memoization
map<int, vector<int>> memo;

vector<int> bestSum(int n, vector<int> arr){
    if(n<0) return {};
    if(memo.find(n)!=memo.end())
        return memo[n];
    for(auto num: arr){
        if(n==num){
            memo[n] = {num};
            return memo[n];
        }
        vector<int> res = bestSum(n-num, arr);
        if(res.size()!=0){
            res.push_back(num);
            if(memo[n].size()>res.size() || memo[n].size()==0)
                memo[n] = res;
        }
    }
    return memo[n];
}

int32_t main(){
    int n = 300;
    vector<int> arr = {14, 10};
    //vector<int> res = bestSum(n, arr);
    //for(auto num: res) cout<<num<<" ";
    pair<int, int> dp[n+1];
    dp[0].first = 0;
    dp[0].second = 0;
    for(int i=1; i<=n; i++) dp[i] = make_pair(-1, INT_MAX);
    for(int i=0; i<=n; i++){
        if(dp[i].first!=-1){
            for(auto weight: arr){
                if(i+weight<=n && dp[i+weight].second > dp[i].second+1) {
                    dp[i+weight].first = i;
                    dp[i+weight].second = dp[i].second+1;
                }
            }
        }
    }
    while(n!=0){
        cout<<n - dp[n].first<<" ";
        n = dp[n].first;
    }
}


