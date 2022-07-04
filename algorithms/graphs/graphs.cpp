#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> explore_island(vector<vector<int>> mat, int i, int j, int length, vector<pair<int, int>>* island){
    mat[i][j] = 0;
    island->push_back(make_pair(i, j));
    /*if(i>0 && j>0 && mat[i-1][j-1]==1){
        //cout<<"Condition 1 true\n";
        mat = explore_island(mat, i-1, j-1, length, island);
    }*/
    if(i>0 && mat[i-1][j]==1){
        //cout<<"Condition 2 true\n";
        mat = explore_island(mat, i-1, j, length, island);
    }
    /*if(i>0 && j<length-1 && mat[i-1][j+1]==1){
        //cout<<"Condition 3 true\n";
        mat = explore_island(mat, i-1, j+1, length, island);
    }*/
    if(j>0 && mat[i][j-1]==1){
        //cout<<"Condition 4 true\n";
        mat = explore_island(mat, i, j-1, length, island);
    }
    if(j<length-1 && mat[i][j+1]==1){
        //cout<<"Condition 5 true\n";
        mat = explore_island(mat, i, j+1, length, island);
    }
    /*if(i<length-1 && j>0 && mat[i+1][j-1]==1){
        //cout<<"Condition 6 true\n";
        mat = explore_island(mat, i+1, j-1, length, island);
    }*/
    if(i<length-1 && mat[i+1][j]==1){
        //cout<<"Condition 7 true\n";
        mat = explore_island(mat, i+1, j, length, island);
    }
    /*if(i<length-1 && j<length-1 && mat[i+1][j+1]==1){
        //cout<<"Condition 8 true\n";
        mat = explore_island(mat, i+1, j+1, length, island);
    }*/
    return mat;
}

int count_island(map<char, vector<char>> graph, vector<pair<int, int>>* largest, vector<pair<int, int>>* smallest){
    int count=0;
    map<char, int> dictionary;
    int index=0;
    for(auto item: graph){
        dictionary[item.first] = index;
        index++;
    }

    vector<vector<int>> mat;
    for(int i=0; i<index; i++){
        vector<int> temp;
        for(int j=0; j<index;  j++) temp.push_back(0);
        mat.push_back(temp);
    }

    for(auto item: graph){
        for(auto node: item.second){
            mat[dictionary[item.first]][dictionary[node]] = 1;
        }
    }

    cout<<"Matrix is: \n";
    for(int i=0; i<index; i++){
        for(int j=0; j<index; j++) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    for(int i=0; i<index; i++){
        for(int j=0; j<index; j++){
            if(mat[i][j]==1){
                vector<pair<int, int>> island;
                mat = explore_island(mat, i, j, index, &island);
                count++;
                if(island.size() > largest->size()) *largest = island;
                else if(island.size() < smallest->size() || smallest->size()==0) *smallest = island;
            }
        }
    }

    return count;
}

vector<char> largest_components(map<char, vector<char>> graph){
    int count=0;
    stack<char> s;
    vector<char> largest;
    map<char, bool> checked;
    for(auto item: graph) checked[item.first] = false;
    for(auto item: graph){
        if(!checked[item.first]){
            s.push(item.first);
            count++;
        }
        vector<char> flag;
        while(!s.empty()){
            char temp = s.top();
            s.pop();
            if(!checked[temp]) flag.push_back(temp);
            checked[temp] = true;
            for(int i=0; i<graph[temp].size(); i++){
                if(!checked[graph[temp][i]])
                    s.push(graph[temp][i]);
            }
        }
        if(flag.size()>largest.size())
            largest = flag;
    }
    return largest;
}

int count_connected_components(map<char, vector<char>> graph){
    int count=0;
    stack<char> s;
    map<char, bool> checked;
    for(auto item: graph) checked[item.first] = false;
    for(auto item: graph){
        if(!checked[item.first]){
            s.push(item.first);
            count++;
        }
        while(!s.empty()){
            char temp = s.top();
            s.pop();
            checked[temp] = true;
            for(int i=0; i<graph[temp].size(); i++){
                if(!checked[graph[temp][i]])
                    s.push(graph[temp][i]);
            }
        }
    }
    return count;
}

vector<char> shortest_path(map<char, vector<char>> graph, char source, char destination){
    queue<char> q;
    map<char, char> path;
    map<char, bool> checked;
    for(auto item: graph) checked[item.first] = false;
    q.push(source);
    bool found = false;
    while(!q.empty()){
        char parent = q.front();
        checked[parent] = true;
        q.pop();
        for(auto child: graph[parent]){
            if(!checked[child]){
                q.push(child);
                checked[child] = true;
                path[child] = parent;
                if(child==destination){
                    found = true;
                    break;
                }
            }
        }
        if(found)
            break;
    }
    vector<char> result;
    if(found){
        while(destination!=source){
            result.push_back(destination);
            destination = path[destination];
        }
        result.push_back(destination);
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<char> bfs_search(map<char, vector<char>> graph, char source, char destination){
    queue<char> q;
    vector<char> path;
    map<char, bool> checked;
    for(auto item: graph) checked[item.first] = false;
    q.push(source);
    while(!q.empty()){
        char temp = q.front();
        q.pop();
        if(temp == destination){
            path.push_back(temp);
            break;
        }
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

vector<char> bfs(map<char, vector<char>> graph){
    queue<char> q;
    vector<char> nodes;
    map<char, bool> checked;
    for(auto item: graph) checked[item.first] = false;
    q.push(graph.begin()->first);
    while(!q.empty()){
        char temp = q.front();
        q.pop();
        if(!checked[temp])
            nodes.push_back(temp);
        checked[temp] = true;
        for(int i=0; i<graph[temp].size(); i++){
            if(!checked[graph[temp][i]])
                q.push(graph[temp][i]);
        }
    }
    return nodes;
}

vector<char> dfs_search(map<char, vector<char>> graph, char source, char destination){
    stack<char> s;
    vector<char> path;
    map<char, bool> checked;
    for(auto item: graph) checked[item.first] = false;
    s.push(source);
    while(!s.empty()){
        char temp = s.top();
        s.pop();
        if(temp == destination){
            path.push_back(temp);
            break;
        }
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

vector<char> dfs(map<char, vector<char>> graph){
    stack<char> s;
    vector<char> nodes;
    map<char, bool> checked;
    for(auto item: graph) checked[item.first] = false;
    s.push(graph.begin()->first);
    while(!s.empty()){
        char temp = s.top();
        s.pop();
        if(!checked[temp])
            nodes.push_back(temp);
        checked[temp] = true;
        for(int i=0; i<graph[temp].size(); i++){
            if(!checked[graph[temp][i]])
                s.push(graph[temp][i]);
        }
    }
    return nodes;
}

map<char, vector<char>> input_graph_with_edges(){
    map<char, vector<char>> graph;
    int edges;
    cin>>edges;
    for(int i=0; i<edges; i++){
        char a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        //graph[b].push_back(a);  //for undirected graph
    }
    return graph;
}

int main(){

    map<char, vector<char>> graph;

    graph = input_graph_with_edges();

    cout<<"\nAdjacency list: \n";
    for(auto item: graph) {
        cout<<item.first<<" => ";
        for(int i=0; i<item.second.size(); i++){
            cout<<item.second[i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    vector<char> nodes;

    nodes = dfs(graph);
    cout<<"Depth First Search: \n";
    for(int i=0; i<nodes.size(); i++) cout<<nodes[i]<<" ";
    cout<<endl<<endl;

    nodes = bfs(graph);
    cout<<"Breadth First Search: \n";
    for(int i=0; i<nodes.size(); i++) cout<<nodes[i]<<" ";
    cout<<endl<<endl;

    /*char source, destination;
    cout<<"Source: ";
    cin>>source;
    cout<<"Destination: ";
    cin>>destination;

    vector<char> path;

    path = dfs_search(graph, source, destination);
    cout<<"Depth First Search: \n";
    if(path[path.size()-1]==destination){
        for(int i=0; i<path.size(); i++) cout<<path[i]<<" ";
    }
    else cout<<"Path not found!";
    cout<<endl<<endl;

    path = bfs_search(graph, source, destination);
    cout<<"Breadth First Search: \n";
    if(path[path.size()-1]==destination){
        for(int i=0; i<path.size(); i++) cout<<path[i]<<" ";
    }
    else cout<<"Path not found!";
    cout<<endl<<endl;

    cout<<"Connected component count: "<<count_connected_components(graph)<<endl<<endl;  //only for undirected graphs

    vector<char> largest = largest_components(graph);
    cout<<"Size of largest component: "<<largest.size()<<endl;
    for(auto node: largest) cout<<node<<" ";
    cout<<endl<<endl;

    cout<<"Finding shortest path!\n";
    path = shortest_path(graph, source, destination);
    if(path.size()>0){
        for(auto node: path) cout<<node<<" ";
    }
    else cout<<"No path found!";
    cout<<endl<<endl;*/

    vector<pair<int, int>> largest_island, smallest_island;
    int islands = count_island(graph, &largest_island, &smallest_island);
    cout<<"Number of islands: "<<islands<<endl;
    cout<<"Number of nodes in smallest island "<<smallest_island.size()<<endl;
    cout<<"Number of nodes in largest island "<<largest_island.size()<<endl<<endl;

    return 0;
}
