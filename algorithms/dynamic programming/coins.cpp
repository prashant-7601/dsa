#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX-1

bool ready[1000];
int value[1000];
vector<int> coins = {1, 2, 5};

int solve(int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (ready[x]) return value[x];
    int best = INF;
    for (auto c : coins) {
        best = min(best, solve(x-c)+1);
    }
    ready[x] = true;
    value[x] = best;
    return best;
}


int main(){
    int n;
    cin>>n;
    int value[n+1], first[n+1], count[n+1]={0};
    value[0] = 0;
    count[0] = 1;
    for (int x = 1; x <= n; x++) {
        value[x] = INT_MAX;
        for (auto c : coins) {
            if (x-c >= 0) {
                value[x] = min(value[x], value[x-c]+1);
                count[x] += count[x-c];
                first[x] = c;
            }
        }
    }
    cout<<"no of optimal solutions: "<<count[n]<<endl;
    cout<<"min coins: "<<value[n]<<endl;
    while (n > 0) {
        cout << first[n] << " ";
        n -= first[n];
    }
    cout<<endl;

}
