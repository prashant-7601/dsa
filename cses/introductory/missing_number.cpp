#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n, x;
    cin>>n;
    int num=0;
    for(int i=1; i<=n; i++) num ^= i;
    for(int i=1; i<n; i++){
        cin>>x;
        num ^= x;
    }
    cout<<num<<endl;
}