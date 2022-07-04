#include<bits/stdc++.h>
using namespace std;

vector<int> find_composites(int n){
    bool arr[n+1] = {false};
    for(int i=2; i<=sqrt(n); i++){
        if(!arr[i]){
            for(int j=i*i; j<=n; j+=i)
                arr[j]=true;
        }
    }
    vector<int> composites;
    for(int i=1; i<n; i++){
        if(arr[i]) composites.push_back(i);
    }
    return composites;
}

int main(){
    int n;
    cin>>n;
    vector<int> composites = find_composites(n);
    for(int i=0; i<composites.size(); i++) cout<<composites[i]<<" ";
    cout<<endl;
}

