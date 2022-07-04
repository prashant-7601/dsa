#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    int weight[n];
    for(int i=0; i<n; i++) cin>>weight[i];
    pair<int,int> best[1<<n];
    best[0] = {0,0};
    for (int s = 1; s < (1<<n); s++) {
    // initial value: n+1 rides are needed
    best[s] = {n+1,0};
    for (int p = 0; p < n; p++) {
        if (s&(1<<p)) {
            auto option = best[s^(1<<p)];
            if (option.second+weight[p] <= x) {
                // add p to an existing ride
                option.second += weight[p];
            }
            else {
                // reserve a new ride for p
                option.first++;
                option.second = weight[p];
            }
            best[s] = min(best[s], option);
        }
    }
    }
    int i = 1<<n;
    cout<<best[i].first<<" "<<best[i].second<<endl;
    return 0;
}

