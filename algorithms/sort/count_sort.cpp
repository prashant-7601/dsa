#include<bits/stdc++.h>
using namespace std;


void count_sort(int arr[], int n, int max_ele){
    int counts[max_ele+1] = {0};
    for(int i=0; i<n; i++) counts[arr[i]]++;
    int index=0;
    for(int i=1; i<=max_ele; i++){
        for(int j=1; j<=counts[i]; j++){
            arr[index] = i;
            index++;
        }
    }
}

int main(){
    int n, max_ele = INT_MIN;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        max_ele = max(max_ele, arr[i]);
    }
    count_sort(arr, n, max_ele);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}


