#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int key){
    int l=0, r=1, mid;
    while(arr[r]<key){
        l=r;
        r*=2;
    }
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

int main() {
	int n, key;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cin>>key;
	int ans = binary_search(arr, key);
	cout<<ans<<endl;
}

