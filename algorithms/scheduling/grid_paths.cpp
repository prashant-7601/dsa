#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>mat[i][j];
    }
    int sum[n][n];
    sum[0][0] = mat[0][0];
    for(int i=1; i<n; i++) sum[0][i] = sum[0][i-1] + mat[0][i];
    for(int i=1; i<n; i++) sum[i][0] = sum[i-1][0] + mat[i][0];
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++) sum[i][j] = max(sum[i-1][j], sum[i][j-1])+mat[i][j];
    }
    cout<<sum[n-1][n-1];
}
