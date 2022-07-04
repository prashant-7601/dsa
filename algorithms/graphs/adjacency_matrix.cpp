#include<bits/stdc++.h>
using namespace std;

map<char, int> dictionary;

vector<vector<int>> remove_node(vector<vector<int>> mat){
    return mat;
}

vector<vector<int>> remove_edge(vector<vector<int>> mat){
    return mat;
}

vector<vector<int>> add_edge(vector<vector<int>> mat){
    char a, b;
    cin>>a>>b;
    if(dictionary.find(a)==dictionary.end())
        dictionary[a] = dictionary.size();
    if(dictionary.find(b)==dictionary.end())
        dictionary[b] = dictionary.size();
    for(int i=0; i<dictionary.size(); i++){
        if(i<mat.size()){
            for(int j=mat.size(); j<dictionary.size(); j++)
                mat[i].push_back(0);
        }
        else{
            vector<int> temp;
            for(int j=0; j<dictionary.size(); j++)
                temp.push_back(0);
            mat.push_back(temp);
        }
    }
    mat[dictionary[a]][dictionary[b]] = 1;
    return mat;
}

void print(vector<vector<int>> mat){
    cout<<"Matrix is: \n";
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat.size(); j++) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

vector<vector<int>> input_matrix(map<char, vector<char>> graph){
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
    map<char, int> temp = dictionary;
    for(auto item: graph){
        for(auto node: item.second)
            mat[temp[item.first]][temp[node]] = 1;
    }
    return mat;
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

    vector<vector<int>> mat  = input_matrix(graph);

    print(mat);

    bool run = true;

    while(run){
        int choice;
        cout<<"Enter 1 to add an edge, 2 to delete an edge, 3 to delete node, 4 to print graph: ";
        cin>>choice;
        if(choice==1)
            mat = add_edge(mat);
        else if(choice==2)
            mat = remove_edge(mat);
        else if(choice==3)
            mat = remove_node(mat);
        else if(choice==4)
            print(mat);
        else
            run = false;
    }

    cout<<"\nExit successfully!\n";
}
