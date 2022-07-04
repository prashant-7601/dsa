#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> find_paths(vector<vector<int>> weights, int n, int source){
    vector<vector<int>> paths;
    for(int i=0; i<n; i++){
        paths.push_back({NULL, INT_MAX});
    }
    paths[0][1] = 0;
    stack<int> s;
    bool processed[n];
    s.push(source);
    while(!s.empty()){
        int top = s.top();
        s.pop();
        processed[top] = true;
        for(int j=0; j<n; j++){
            if(weights[top][j]!=0){
                if(!processed[j]) s.push(j);
                if(paths[top][1]+weights[top][j] < paths[j][1]){
                    paths[j][0] = top;
                    paths[j][1] = paths[top][1]+weights[top][j];
                }
            }
        }
    }
    return paths;
}

int main(){
    int n, num, source;
    cin>>n;
    vector<vector<int>> weights;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            cin>>num;
            temp.push_back(num);
        }
        weights.push_back(temp);
    }
    cin>>source;
    source--;
    vector<vector<int>> path = find_paths(weights, weights.size(), source);
    for(int i=0; i<n; i++) {
        int node = i;
        cout<<node+1<<" ";
        while(node!=0){
            node = path[node][0];
            cout<<node+1<<" ";
        }
        cout<<": "<<path[i][1]<<endl;
    }
}
