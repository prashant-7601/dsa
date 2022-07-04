#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int
int mod = 1000000007;


int fastpow(int base, int e){
    int res = 1;
    while(e>0){
        if(e&1) res *= base;
        base *= base;
        e >>= 1;
    }
    return res;
}


int modpow(int base, int e, int m){
    int res = 1;
    base %= m;
    while(e>0){
        if(e&1) res = res*base %m;
        base = base*base %m;
        e >>= 1;
    }
    return res;
}

class comp{
    public:
    bool operator()(vector<int>&a, vector<int> &b){
        return ((a[1]-a[0]+1)*a[2]) < ((b[1]-b[0]+1)*b[2]);
    }
};

void solve(){
    int n, k, m;
    cin>>n>>m;
    
}


int32_t main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}
