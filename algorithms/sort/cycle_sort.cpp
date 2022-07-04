#include<bits/stdc++.h>
using namespace std;


vector<int> find_misssing1(int arr[], int n){  //for duplicates also
    vector<int> missing;
    for(int i=0; i<n; i++){
        if(arr[arr[i]-1] != arr[i] && arr[i]>0){
            int temp = arr[arr[i]-1];
            arr[arr[i]-1] = arr[i];
            arr[i] = temp;
            i--;
        }
    }
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=0; i<n; i++){
        if(arr[i]!=i+1) missing.push_back(i+1);
    }
    return missing;
}

int find_misssing(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i]!=i && arr[i]<n && arr[i]>0){
            int temp = arr[arr[i]];
            arr[arr[i]] = arr[i];
            arr[i] = temp;
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i]!=i) return i;
    }
    return n;
}

void cycle_sort(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i]!=i+1){
            int temp = arr[arr[i]-1];
            arr[arr[i]-1] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(){
    int n, num;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    //cycle_sort(arr, n);
    //cout<<"Sorted array: ";
    //for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    //cout<<endl;

    //int missing = find_misssing(arr, n);
    //cout<<missing<<endl;

    //vector<int> missing = find_misssing1(arr, n);
    //for(auto item: missing) cout<<"Duplicate: "<<arr[item-1]<<" , missing: "<<item<<endl;   //print item for missing numbers
    //cout<<endl;

    vector<int> missing = find_misssing1(arr, n);
    cout<<missing[0]<<endl;
}
