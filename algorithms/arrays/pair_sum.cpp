#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n, k;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);
    cin>>k;
    int i=0, j=n-1;
    bool found=false;
    while(i<j){
        if(arr[i]+arr[j]==k) {
            found = true;
            break;
        }
        else if(arr[i]+arr[j]<k)
            i++;
        else
            j--;
    }
    if(found)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
