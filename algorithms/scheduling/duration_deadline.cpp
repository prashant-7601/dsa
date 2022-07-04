#include<bits/stdc++.h>
using namespace std;

class Compare{
    public:
    bool operator() (vector<int>& a, vector<int>&b){
        return a[1] > b[2];
    }
};

int32_t main(){
    int n;
    cin>>n;
    int duration[n], deadline[n];
    for(int i=0; i<n; i++) cin>>duration[i];
    for(int i=0; i<n; i++) cin>>deadline[i];
    vector<vector<int>> data(n);
    for(int i=0; i<n; i++){
        data[i].push_back(deadline[i]);
        data[i].push_back(duration[i]);
        data[i].push_back(i+1);
    }
    sort(data.begin(), data.end());
    priority_queue<vector<int>, vector<vector<int>>, Compare> p;
    int curr=n-1;
    while(curr>-1){
        p.push(data[curr]);
        int deadline1 = data[curr][0], deadline2;
        if(curr>0) deadline2 = data[curr-1][0];
        else deadline2 = 0;
        while(deadline1>deadline2 && !p.empty()){
            vector<int> temp = p.top();
            p.pop();
            temp[1]--;
            deadline1--;
            duration[temp[2]-1]--;
            if(temp[1]>0)
                p.push(temp);
        }
        curr--;
    }

    vector<int> res;
    for(int i=0; i<n; i++) {
        if(duration[i]==0) res.push_back(i);
    }
    cout<<"Max number of tasks = "<<res.size()<<endl;
    cout<<"Selected task numbers: ";
    for(int i=0; i<res.size()-1; i++) cout<<res[i]<<", ";
    cout<<res[res.size()-1];
}

