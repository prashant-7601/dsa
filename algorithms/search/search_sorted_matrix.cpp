#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, key;
    cin>>n>>m;
    int mat[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>mat[i][j];
    }
    cin>>key;
    int row=0, col = m-1;
    bool found = false;
    while(row<n && col>-1){
        if(mat[row][col]==key){
            found = true;
            break;
        }
        else if(mat[row][col]<key)
            row++;
        else
            col--;
    }
    if(found) cout<<"Yes: "<<row<<" "<<col<<endl;
    else cout<<"No\n";
}
