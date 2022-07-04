#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n;
    cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n&1) n = n*3+1;
        else n = n/2;
    }
    cout<<n;
}