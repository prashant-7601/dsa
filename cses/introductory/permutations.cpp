#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n;
    cin>>n;
    if(n==1) {
        cout<<1;
        return 0;
    }
    if(n<4){
        cout<<"NO SOLUTION";
        return 0;
    }
    if(n==4){
        cout<<"2 4 1 3";
        return 0;
    }
    for(int i=1; i<=n; i+=2) cout<<i<<" ";
    for(int i=2; i<=n; i+=2) cout<<i<<" ";
    return 0;
}