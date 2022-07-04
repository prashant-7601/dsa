#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    string s;
    cin>>s;
    int res=1, left=0, right=0, n=s.length();
    while(right<n){
        while(right<n && s[right]==s[left]) right++;
        res = max(res, right-left);
        left = right;
    }
    cout<<res<<endl;
}