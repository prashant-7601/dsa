#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i=l-1;
    for(int j=l; j<r; j++){
       if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
       }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quick_sort(int arr[], int l, int r){
    if(l<r){
        int piv = partition(arr, l , r);
        quick_sort(arr, l, piv-1);
        quick_sort(arr, piv+1, r);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    quick_sort(arr, 0, n-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

