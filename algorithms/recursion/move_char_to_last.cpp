#include<bits/stdc++.h>
using namespace std;

string move(string s, char ch, int idx, int n, int count, string res){
    if(idx==n){
        while(count--) res+=ch;
        return res;
    }
    if(s.at(idx)==ch){
        return move(s, ch, idx+1, n, count+1, res);
    }
    return move(s, ch, idx+1, n, count, res+s.at(idx));
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    char ch;
    cin>>ch;
    string res = move(s, ch, 0, n, 0, "");
    cout<<res;
}

