#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n, sum=0;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int maximum=arr[0];
    for(int i=1; i<n; i++){
        maximum = max(maximum+arr[i], arr[i]);
        sum = max(sum, maximum);
    }
    cout<<sum<<endl;
}
