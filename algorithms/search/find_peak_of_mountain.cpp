#include<bits/stdc++.h>
using namespace std;

int peak_of_mountain(int arr[], int n){
    int l=0, r=n-1, mid, ans;

    peak = max(arr[l], arr[r]);
    l++;
    r--;

    while(l<=r){
        mid = l + (r-l)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            return arr[mid];
        else if(arr[mid]<arr[mid+1])
            l = mid+1;
        else if(arr[mid]>arr[mid+1])
            r = mid-1;
    }
    return peak;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int ans = peak_of_mountain(arr, n);
	cout<<ans<<endl;
}


