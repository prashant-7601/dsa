#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> find_paths(vector<vector<int>> weights, int n, int source){
    vector<vector<int>> paths;
    for(int i=0; i<n; i++){
        paths.push_back({NULL, INT_MAX});
    }
    paths[0][1] = 0;
    for(int a0=1; a0<n; a0++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(weights[i][j]!=0){
                    if(paths[j][1] > paths[i][1]+weights[i][j]){
                        paths[j][1] = paths[i][1]+weights[i][j];
                        paths[j][0] = i;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(weights[i][j]!=0){
                if(paths[j][1] > paths[i][1]+weights[i][j]){
                    cout<<"Negative cycle detetcted\n";
                    return  {};
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
