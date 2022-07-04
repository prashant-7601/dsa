#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum, k, num;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0; i<n; i++){
        cin>>num;
        arr.push_back(num);
    }
    sum = arr[0];
    int i=0, j=0;
    while(i<n && j<n){
        if(sum==k)
            break;
        else if(sum<k && j<n-1){
            j++;
            sum+=arr[j];
        }
        else if(sum>k && i<n-1){
            sum-=arr[i];
            i++;
        }
        else{
            break;
        }
    }
    if(sum==k) cout<<"YES\n";
    else cout<<"No\n";
}
