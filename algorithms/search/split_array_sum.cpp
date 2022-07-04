#include<bits/stdc++.h>
using namespace std;

int find_result(int arr[], int n, int m){
    int l=0, r=0, mid;
    for(int i=0; i<n; i++){
        l = max(l, arr[i]);
        r += arr[i];
    }
    while(l<r){
        mid = l + (r-l)/2;
        int sum=0, pieces=1;
        for(int i=0; i<n; i++){
            if(sum+arr[i]>mid){
                sum=0;
                pieces++;
            }
            sum+=arr[i];
        }
        if(pieces>m)
            l = mid+1;
        else
            r = mid;
    }
    return r;
}

int main() {
	int n, m;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cin>>m;
	int result = find_result(arr, n, m);
	cout<<result<<endl;
}
