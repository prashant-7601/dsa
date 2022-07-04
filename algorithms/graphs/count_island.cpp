#include<bits/stdc++.h>
using namespace std;

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

vector<vector<int>> explore_island(vector<vector<int>> mat, int i, int j, int length){
    mat[i][j] = 0;
    cout<<"checking index "<<i<<" "<<j<<endl;
    /*if(i>0 && j>0 && mat[i-1][j-1]==1){
        //cout<<"Condition 1 true\n";
        mat = explore_island(mat, i-1, j-1, length);
    }*/
    if(i>0 && mat[i-1][j]==1){
        //cout<<"Condition 2 true\n";
        mat = explore_island(mat, i-1, j, length);
    }
    /*if(i>0 && j<length-1 && mat[i-1][j+1]==1){
        //cout<<"Condition 3 true\n";
        mat = explore_island(mat, i-1, j+1, length);
    }*/
    if(j>0 && mat[i][j-1]==1){
        //cout<<"Condition 4 true\n";
        mat = explore_island(mat, i, j-1, length);
    }
    if(j<length-1 && mat[i][j+1]==1){
        //cout<<"Condition 5 true\n";
        mat = explore_island(mat, i, j+1, length);
    }
    /*if(i<length-1 && j>0 && mat[i+1][j-1]==1){
        //cout<<"Condition 6 true\n";
        mat = explore_island(mat, i+1, j-1, length);
    }*/
    if(i<length-1 && mat[i+1][j]==1){
        //cout<<"Condition 7 true\n";
        mat = explore_island(mat, i+1, j, length);
    }
    /*if(i<length-1 && j<length-1 && mat[i+1][j+1]==1){
        //cout<<"Condition 8 true\n";
        mat = explore_island(mat, i+1, j+1, length);
    }*/
    return mat;
}

int count_island(map<char, vector<char>> graph){
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
                mat = explore_island(mat, i, j, index);
                count++;
            }
        }
    }

    return count;
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

    int islands = count_island(graph);
    cout<<"Number of islands: "<<islands<<endl<<endl;

    return 0;
}
