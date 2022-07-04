#include<bits/stdc++.h>
using namespace std;
#define int long long

// memoization
map<int, int> memo;

int fib(int n){
    if(memo.find(n)!=memo.end())
        return memo[n];
    if(n<=2)
        return 1;
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int32_t main(){
    int n;
    cin>>n;
    cout<<fib(n);
}
