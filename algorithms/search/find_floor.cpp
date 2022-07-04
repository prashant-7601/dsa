#include<bits/stdc++.h>
using namespace std;

int search_floor(int arr[], int n, int key){
    if(key<arr[0])
        return -1;
    else{
        int mid, left=0, right=n-1;
        while(left<=right){
            mid = (left+right)/2;
            if(arr[mid]==key)
                return mid;
            else if(arr[mid]<key)
                left=mid+1;
            else
                right=mid-1;
        }
        return left-1;
    }
}

int main(){
    int n, key;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    cin>>key;

    int index = search_floor(arr, n, key);
    if(index>-1) cout<<arr[index]<<endl;
    else cout<<"Not found\n";
    return 0;
}

