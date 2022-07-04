#include<bits/stdc++.h>
using namespace std;

vector<int> dfs(vector<vector<int>> graph, int v){
    stack<int> s;
    vector<int> path;
    bool checked[v] = {false};
    s.push(0);
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        if(!checked[temp])
            path.push_back(temp);
        checked[temp] = true;
        for(int i=0; i<graph[temp].size(); i++){
            if(!checked[graph[temp][i]])
                s.push(graph[temp][i]);
        }
    }
    return path;
}

vector<int> search_path(vector<vector<int>> graph, int source, int destination, int v){
    stack<int> s;
    vector<int> path;
    bool checked[v] = {false};
    s.push(source);
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        for(int i=0; i<graph[temp].size(); i++){
            if(!checked[graph[temp][i]])
                s.push(graph[temp][i]);
        }
        if(temp == destination){
            path.push_back(temp);
            break;
        }
        if(!checked[temp]) path.push_back(temp);
        checked[temp] = true;
    }
    return path;
}

int main(){
    int v, e, source, destination;
    cin>>v>>e;
    vector<vector<int>> graph(v);
    for(int i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        //graph[b].push_back(a); //for Undirected graphs
    }
    cin>>source>>destination;
    vector<int> path = search_path(graph, source, destination, v);

    for(int i=0; i<v; i++){
        cout<<i<<" => ";
        for(int j=0; j<graph[i].size(); j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
    if(path[path.size()-1]==destination){
        for(int i=0; i<path.size(); i++) cout<<path[i]<<" ";
        cout<<endl;
    }
    else cout<<"Path not found!\n";
}

