#include<bits/stdc++.h>
using namespace std;

int hamming(int a, int b){
    return __builtin_popcount(a^b);
}

int main(){
    int n;
    cin>>n;
    string arr[n];
    int res = INT_MAX, x, y;
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++){
        stringstream obj1(arr[i]);
        obj1 >> x;
        for(int j=i+1; j<n;  j++){
            stringstream obj2(arr[j]);
            obj2 >> y;
            res = min(res, hamming(x, y));
        }
    }
    cout<<res<<endl;
}
