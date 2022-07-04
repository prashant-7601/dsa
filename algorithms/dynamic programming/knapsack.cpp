#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum=0;
    cin>>n;
    int weights[n];
    for(int i=0; i<n; i++){
        cin>>weights[i];
        sum+=weights[i];
    }
    bool possible[sum+1] = {false};
    possible[0] = true;
    possible[sum] = true;
    for (int k = 0; k < n; k++) {
        for (int x = sum-weights[k]; x >= 0; x--)
            possible[x+weights[k]] |= possible[x];
    }
    for(int i=0; i<=sum; i++) {
        if(possible[i]) cout<<i<<" possible\n";
        else cout<<i<<" not possible\n";
    }
    return 0;
}
