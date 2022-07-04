#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid,  int r){
    int n1=mid-l+1, n2=r-mid;
    int a[n1], b[n2];
    for(int i=0; i<n1; i++)
        a[i] = arr[l+i];
    for(int j=0; j<n2; j++)
        b[j] = arr[mid+1+j];
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k] = a[i];
            i++;
            k++;
        }
        else{
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = b[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    merge_sort(arr, 0, n-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}
