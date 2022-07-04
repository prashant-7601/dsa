#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s, e;
    cin>>n;
    vector<pair<int, int>> activity(n);
    for(int i=0; i<n; i++){
         cin>>s>>e;
         activity[i].first = e;
         activity[i].second = s;
    }
    sort(activity.begin(), activity.end());
    int count=0, currentEnd = -1;
    for(int i=0; i<n; i++){
        if(activity[i].second>currentEnd){
            count++;
            currentEnd = activity[i].first;
        }
    }
    cout<<count<<endl;
}
