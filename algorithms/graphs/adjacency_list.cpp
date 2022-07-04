#include<bits/stdc++.h>
using namespace std;

map<char, vector<char>> remove_node(map<char, vector<char>> graph){
    char node;
    cin>>node;
    graph.erase(node);
    for(auto item: graph) {
        graph[item.first].erase(remove(graph[item.first].begin(), graph[item.first].end(), node), graph[item.first].end());
    }
    return graph;
}

map<char, vector<char>> remove_edge(map<char, vector<char>> graph){
    char a, b;
    cin>>a>>b;
    graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
    return graph;
}

map<char, vector<char>> add_edge(map<char, vector<char>> graph){
    char a, b;
    cin>>a>>b;
    graph[a].push_back(b);
    return graph;
}

void print(map<char, vector<char>> graph){
    cout<<"\nAdjacency list: \n";
    for(auto item: graph) {
        cout<<item.first<<" => ";
        for(int i=0; i<item.second.size(); i++){
            cout<<item.second[i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
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

    print(graph);

    bool run = true;

    while(run){
        int choice;
        cout<<"Enter 1 to add an edge, 2 to delete an edge, 3 to delete node, 4 to print graph: ";
        cin>>choice;
        if(choice==1)
            graph = add_edge(graph);
        else if(choice==2)
            graph = remove_edge(graph);
        else if(choice==3)
            graph = remove_node(graph);
        else if(choice==4)
            print(graph);
        else
            run = false;
    }

    cout<<"\nExit successfully!\n";
}
