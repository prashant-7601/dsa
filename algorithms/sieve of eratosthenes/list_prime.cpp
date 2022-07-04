#include<bits/stdc++.h>
using namespace std;

#define int long long int

vector<int> find_primes(int n){
    bool arr[n+1] = {false};
    for(int i=2; i<=sqrt(n); i++){
        if(!arr[i]){
            for(int j=i*i; j<=n; j+=i)
                arr[j]=true;
        }
    }
    vector<int> primes;
    for(int i=1; i<n; i++){
        if(!arr[i]) primes.push_back(i);
    }
    return primes;
}

int32_t main(){
    int n;
    cin>>n;
    vector<int> primes = find_primes(n);
    for(int i=0; i<primes.size(); i++) cout<<primes[i]<<" ";
    cout<<endl;
}
