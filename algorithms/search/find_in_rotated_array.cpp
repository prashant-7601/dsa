#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int l, int r, int key){
    int mid;
    while(l<=r){
        mid = l + (r-l)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

int peak_of_mountain(int arr[], int n){
    int l=0, r=n-1, mid;

    if(arr[l]>arr[r] && arr[l]>arr[l+1])
        return l;

    while(l<=r){
        mid = l + (r-l)/2;
        if(mid<=r && arr[mid]>arr[mid+1] && arr[mid]>=arr[mid-1])
            return mid;
        else if(mid>=l && arr[mid]<arr[mid-1])
            return mid-1;
        else if(arr[l]>arr[mid])
            r = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int main() {
	int n, key;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cin>>key;
	int peak = peak_of_mountain(arr, n);
	cout<<peak<<endl;
	int ans;
	ans = binary_search(arr, 0, peak, key);
	if(ans!=-1)
        cout<<ans<<endl;
    else{
        ans = binary_search(arr, peak+1, n-1, key);
        cout<<ans<<endl;
    }
}



