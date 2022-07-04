#include<bits/stdc++.h>
using namespace std;

#define int long long

int kadane(int arr[], int n){
    int sum=0, maximum=arr[0];
    for(int i=1; i<n; i++){
        maximum = max(maximum+arr[i], arr[i]);
        sum = max(sum, maximum);
    }
    return sum;
}

int32_t main(){
    int n, total_sum=0;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        total_sum+=arr[i];
    }
    int nonwrapsum = kadane(arr, n);
    for(int i=0; i<n; i++) arr[i] = -arr[i];
    int wrapsum = total_sum + kadane(arr, n);
    cout<<max(wrapsum, nonwrapsum)<<endl;
}
