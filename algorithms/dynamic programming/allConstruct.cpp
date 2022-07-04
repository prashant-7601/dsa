#include<bits/stdc++.h>
using namespace std;
#define int long long

// memoization
map<string, vector<vector<string>>> memo;

vector<vector<string>> allConstruct(string str, vector<string> arr){
    if(memo.find(str)!=memo.end())
        return memo[str];
    for(auto s: arr){
        if(s == str){
            memo[s].push_back({s});
            return memo[s];
        }
        else if(s.length() < str.length() && str.substr(0, s.length())==s){
            string temp = str.substr(s.length(), str.length());
            vector<vector<string>> res = allConstruct(temp, arr);
            for(int i=0; i<res.size(); i++){
                reverse(res[i].begin(), res[i].end());
                res[i].push_back(s);
                reverse(res[i].begin(), res[i].end());
                memo[str].push_back(res[i]);
            }
        }
    }
    return memo[str];
}

int32_t main(){
    string str = "pineapplepenapple";
    vector<string> arr = {"apple","pen","applepen","pine","pineapple"};
    /*vector<vector<string>> res = allConstruct(str, arr);
    for(auto row: res){
        for(auto str: row) cout<<str<<" ";
        cout<<endl;
    }*/
    int n = str.length();
    pair<bool, vector<vector<string>>> dp[n+1];
    dp[0].first = true;
    for(int i=0; i<=n; i++){
        if(dp[i].first){
            vector<vector<string>> temp = dp[i].second;
            for(auto word: arr){
                if(i+word.length()<=n && str.substr(i, word.length())==word){
                    dp[i+word.length()].first = true;
                    if(temp.size()==0){
                        dp[i+word.length()].second.push_back({word});
                    }
                    else{
                        for(int j=0; j<temp.size(); j++){
                            temp[j].push_back(word);
                            dp[i+word.length()].second.push_back(temp[j]);
                        }
                    }
                }
            }
        }
    }
    for(auto row: dp[n].second){
        for(auto word: row) cout<<word<<" ";
        cout<<endl;
    }
}


