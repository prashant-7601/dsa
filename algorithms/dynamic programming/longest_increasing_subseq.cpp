#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int length[n+1]={0};
    for (int k = 0; k < n; k++) {
        length[k] = 1;
        for (int i = 0; i < k; i++) {
            if (arr[i] < arr[k]) {
                length[k] = max(length[k],length[i]+1);
            }
        }
    }
    cout<<*max_element(length, length+n)<<endl;
}
