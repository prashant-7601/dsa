#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int x, y, curr;
    cin>>x>>y;
    if(x<=y){
        if(y&1){
            curr = y*y*1ll;
            while(x-->1){
                curr--;
            }
        }
        else{
            curr = (y-1)*(y-1)*1ll + 1;
            while(x-->1){
                curr++;
            }
        }
    }
    else{
        if(x&1){
            curr = (x-1)*(x-1)*1ll + 1;
            while(y-->1){
                curr++;
            }
        }
        else{
            curr = x*x*1ll;
            while(y-->1){
                curr--;
            }
        }
    }
    cout<<curr<<endl;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}