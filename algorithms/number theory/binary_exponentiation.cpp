#include<bits/stdc++.h>
using namespace std;

int exponent(int base, int power){
    int res=1;
    while(power){
        if(power%2==0){
            base = base*base;
            power = power/2;
        }
        else{
            res = res*base;
            power--;
        }
    }
    return res;
}

int main(){
    int n, p;
    cin>>n>>p;
    cout<<exponent(n, p);
}
