#include<bits/stdc++.h>
using namespace std;


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
        if(mid<r && arr[mid]>arr[mid+1])
            return mid;
        else if(mid>l && arr[mid]<arr[mid-1])
            return mid-1;
        else if(arr[l]>arr[mid])
            r = mid-1;
        else
            l = mid+1;
    }
    return peak;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int peak = peak_of_mountain(arr, n);
	cout<<(peak+1)%n<<endl;
}

