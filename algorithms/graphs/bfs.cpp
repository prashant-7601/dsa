#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> graph, int v){
    queue<int> q;
    vector<int> path;
    bool checked[v] = {false};
    q.push(0);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(!checked[temp])
            path.push_back(temp);
        checked[temp] = true;
        for(int i=0; i<graph[temp].size(); i++){
            if(!checked[graph[temp][i]])
                q.push(graph[temp][i]);
        }
    }
    return path;
}

vector<int> search_path(vector<vector<int>> graph, int source, int destination, int v){
    queue<int> q;
    vector<int> path;
    bool checked[v] = {false};
    q.push(source);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i=0; i<graph[temp].size(); i++){
            if(!checked[graph[temp][i]])
                q.push(graph[temp][i]);
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


