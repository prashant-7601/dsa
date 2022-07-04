#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n, result=2;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int diff = arr[1]-arr[0];
    for(int i=2; i<n; i++){
        int count=2;
        while(arr[i]-arr[i-1]==diff){
            count++;
            i++;
        }
        diff=arr[i]-arr[i-1];
        result = max(result, count);
    }
    cout<<result<<endl;
}
