#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> factorize(int n)
{
    vector<int> factors;
    int flag=0;
    while (!(n % 2)) {
        n >>= 1;
        flag=1;
    }
    if (flag)
        factors.push_back(2);
    for (long long i = 3; i <= sqrt(n); i += 2) {
        flag = 0;
        while (n % i == 0) {
            flag = 1;
            n = n / i;
        }
        if (flag)
            factors.push_back(i);
    }
    if (n > 2)
        factors.push_back(n);
    return factors;
}

vector<int> prime_factorization(int n){
    int spf[n+1];
    for(int i=0; i<=n; i++) spf[i] = i;
    for(int i=2; i<=sqrt(n); i++){
        if(spf[i]==i){
            for(int j=i*i; j<=n; j+=i){
                if(spf[j]==j)
                    spf[j] = i;
            }
        }
    }
    vector<int> factors;
    while(n>1){
        factors.push_back(spf[n]);
        n = n/spf[n];
    }
    return factors;
}

int32_t main(){
    int n;
    cin>>n;
    vector<int> factors = factorize(n);
    for(int i=0; i<factors.size(); i++) cout<<factors[i]<<" ";
    cout<<endl;
}

