#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> board, int x, int y, int n){
    bool check = true;
    int a=x, b=y;
    while(x>=0){
        if(board[x][y]==1)
            return false;
        x--;
    }
    x=a;
    while(y>=0 && x>=0){
        if(board[x][y]==1)
            return false;
        x--;
        y--;
    }
    x=a;
    y=b;
    while(x>=0 && y<n){
        if(board[x][y]==1)
            return false;
        x--;
        y++;
    }
    return true;
}

void place_queen(vector<vector<int>> board, int n, int idx){
    if(idx == n){
        cout<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cout<<board[i][j]<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i=0; i<n ; i++){
        if(isSafe(board, idx, i, n)){
            board[idx][i] = 1;
            place_queen(board, n, idx+1);
            board[idx][i] = 0;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> board;
    vector<int> temp;
    for(int i=0; i<n; i++) temp.push_back(0);
    for(int i=0; i<n; i++) board.push_back(temp);
    place_queen(board, n, 0);
}
