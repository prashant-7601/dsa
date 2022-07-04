#include<bits/stdc++.h>
using namespace std;

string remove_duplicates(string s, map<char, bool> m, int idx, int n, string res){
    if(idx==n){
        return res;
    }
    if(m[s[idx]]){
        return remove_duplicates(s, m, idx+1, n, res);
    }
    m[s.at(idx)] = true;
    return remove_duplicates(s, m, idx+1, n, res+s.at(idx));
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char, bool> m;
    string res = remove_duplicates(s, m, 0, n, "");
    cout<<res;
}

