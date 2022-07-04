#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    float profit=0, weight, w, p;
    vector<vector<float>> arr;
    cin>>n>>weight;
    for(int i=0; i<n; i++){
        cin>>w>>p;
        arr.push_back({p/w, w, p});
    }
    sort(arr.begin(), arr.end());
    for(int i=n-1; i>=0; i--){
        if(weight > arr[i][1]){
            weight -= arr[i][1];
            profit += arr[i][2];
        }
        else{
            profit += weight*arr[i][0];
            break;
        }
    }
    cout<<profit<<endl;
}
