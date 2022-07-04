#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main(){
    int n, p, d;
    cin>>n;
    vector<pair<int, int>> jobs(n);
    for(int i=0; i<n; i++){
         cin>>p>>d;
         jobs[i].first = p;
         jobs[i].second = d;
    }
    sort(jobs.begin(), jobs.end());
    int maxEndTime = 0;
    for(int i=0; i<n; i++){
        if(jobs[i].second > maxEndTime) maxEndTime = jobs[i].second;
    }
    int fill[maxEndTime], count=0, maxProfit=0;
    for(int i=0; i<maxEndTime; i++) fill[i] = -1;
    for(int i=0; i<n; i++){
        int j = jobs[i].second-1;
        while(j>=0 && fill[j]!=-1) j--;
        if(j>=0 && fill[j]==-1){
            fill[j]=i;
            count++;
            maxProfit+=jobs[i].first;
        }
    }
    cout<<count<<" "<<maxProfit<<endl;
}
