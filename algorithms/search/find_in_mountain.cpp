#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int l, int r, int key, bool left){
    int mid;
    if(left){
        while(l<=r){
            mid = l + (r-l)/2;
            if(arr[mid]==key)
                return mid;
            else if(arr[mid]<key)
                l = mid+1;
            else
                r = mid-1;
        }
    }
    else{
        while(l<=r){
            mid = l + (r-l)/2;
            if(arr[mid]==key)
                return mid;
            else if(arr[mid]>key)
                l = mid+1;
            else
                r = mid-1;
        }
    }
    return -1;
}

int peak_of_mountain(int arr[], int n){
    int l=0, r=n-1, mid, peak;

    if(arr[l]>arr[r])
        peak = l;
    else
        peak = r;
    l++;
    r--;

    while(l<=r){
        mid = l + (r-l)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            return mid;
        else if(arr[mid]<arr[mid+1])
            l = mid+1;
        else if(arr[mid]>arr[mid+1])
            r = mid-1;
    }
    return peak;
}

int main() {
	int n, key;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cin>>key;
	int peak = peak_of_mountain(arr, key);
	int ans;
	ans = binary_search(arr, 0, peak, key, true);
	if(ans!=-1)
        cout<<ans<<endl;
    else{
        ans = binary_search(arr, peak, n-1, key, false);
        cout<<ans<<endl;
    }
}


