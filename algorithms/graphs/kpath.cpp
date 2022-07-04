#include<bits/stdc++.h>
using namespace std;

bool processed[1000];
vector<vector<int>> paths;

void find_paths(vector<vector<int>> weights, int n, int source, int destination, int k, vector<int> path){
    if(source==destination){
        if(path.size()==k+1)
            paths.push_back(path);
        return;
    }
    processed[source] = true;
    for(int j=0; j<n; j++){
        if(!processed[j] && weights[source][j]!=0){
            path.push_back(j);
            find_paths(weights, n, j, destination, k, path);
            path.pop_back();
        }
    }
    return;
}

int main(){
    int n, num, source, destination, k;
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
    cin>>source>>destination>>k;
    source--;
    destination--;
    vector<int> path = {source};
    find_paths(weights, weights.size(), source, destination, k, path);
    int min_path = INT_MAX;
    int min_index = -1;
    for(int i=0; i<paths.size(); i++){
        int sum=0;
        for(int j=0; j<paths[i].size()-1; j++){
            sum += weights[paths[i][j]][paths[i][j+1]];
        }
        if(sum<min_path){
            min_path = sum;
            min_index = i;
        }
    }
    if(min_index == -1)
        cout<<"No path of length k is available."<<endl;
    else
        cout<<"Weight of shortest path from ("<<source+1<<","<<destination+1<<") with "<<k<<" edges : "<<min_path<<endl;
}
