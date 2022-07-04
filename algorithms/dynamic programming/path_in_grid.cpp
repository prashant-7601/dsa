#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int values[n][n], sum[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>values[i][j];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++){
            if(i>0 && j>0)
                sum[i][j] = max(sum[i][j-1],sum[i-1][j])+values[i][j];
            else if(i>0)
                sum[i][j] = sum[i-1][j] + values[i][j];
            else if(j>0)
                sum[i][j] = sum[i][j-1] + values[i][j];
            else
                sum[i][j] = values[i][j];
        }
    }
    cout<<sum[n-1][n-1]<<endl;
    return 0;
}
