#include<bits/stdc++.h>
using namespace std;

void topologicalSortUtils(vector<int> graph[], bool visited[], stack<int> &s, int i){
    visited[i] = true;
    int n = graph[i].size();
    for(int j=0; j<n; j++){
        if(!visited[graph[i][j]]) topologicalSortUtils(graph, visited, s, graph[i][j]);
    }
    s.push(i);
}

vector<int> topologicalSort(vector<int> graph[], int v){
    bool visited[v];
    stack<int> s;
    for(int i=0; i<v; i++){
        if(!visited[i]) topologicalSortUtils(graph, visited, s, i);
    }
    vector<int> result;
    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

int main(){
    vector<int> graph[6];
    graph[0] = {4};
    graph[1] = {2, 3, 5};
    graph[2] = {4, 5};
    graph[3] = {};
    graph[4] = {};
    graph[5] = {};
    vector<int> result = topologicalSort(graph, 6);
    for(int i=0; i<6; i++) cout<<result[i]<<" ";
}
