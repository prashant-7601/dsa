#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshal(vector<vector<int>> weights, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(weights[i][j]>weights[i][k]+weights[k][j])
                    weights[i][j] = weights[i][k] + weights[k][j];
            }
        }
    }
    return weights;
}

int main(){
    int n, num;
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
    vector<vector<int>> path = floydWarshal(weights, weights.size());
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout<<path[i][j]<<" ";
        cout<<endl;
    }
}
