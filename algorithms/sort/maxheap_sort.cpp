#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int c1 = 2*i+1, c2 = 2*i+2;
    int maximum = i;
    if(c1<n && arr[c1] > arr[maximum]) maximum = c1;
    if(c2<n && arr[c2] > arr[maximum]) maximum = c2;
    if(maximum!=i){
        int temp = arr[i];
        arr[i] = arr[maximum];
        arr[maximum] = temp;
        heapify(arr, n, maximum);
    }
}

void extract_maximum(int arr[], int n){
    int temp = arr[0];
    arr[0] = arr[n-1];
    arr[n-1] = temp;
    n--;
    heapify(arr, n, 0);
}

void extract_minimum(int arr[], int n){
    n--;
    heapify(arr, n, 0);
}

void heap_sort(int arr[], int n, bool ascending=true){
    if(ascending){
        while(n>1){
            extract_maximum(arr, n);
            n--;
        }
    }
    else{
        while(n>1){
            extract_minimum(arr, n);
            n--;
        }
    }
}

void build_heap(int arr[], int n){
    for(int i=n/2; i>=0; i--)
        heapify(arr, n, i);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    build_heap(arr, n);
    heap_sort(arr, n);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}
