#include<bits/stdc++.h>
using namespace std;

vector<int> multiply(vector<int> f, int n){
    int rem=0, product;
    for(int i=0; i<f.size(); i++){
        product = f[i]*n + rem;
        f[i] = product%10;
        rem = product/10;
    }
    while(rem){
        f.push_back(rem%10);
        rem /= 10;
    }
    return f;
}

vector<int> factorial(int N){
    vector<int> f = {1};
    for(int i=2; i<=N; i++){
        f = multiply(f, i);
    }
    reverse(f.begin(), f.end());
    return f;
}

int main(){
    vector<int> f = factorial(5);
    for(int i=0; i<f.size(); i++){
        cout<<f[i];
    }
}
