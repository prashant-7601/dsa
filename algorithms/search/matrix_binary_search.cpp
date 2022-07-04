#include<bits/stdc++.h>
using namespace std;

int find_row(vector<vector<int>> mat, int n, int m, int key){
    int l=0, r=n-1, mid;
    while(l<=r){
        mid = l + (r-l)/2;
        if(key >= mat[mid][0] && key<= mat[mid][m-1])
            return mid;
        else if(key>mat[mid][m-1])
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

pair<int, int> matrix_binary_search(vector<vector<int>> mat, int n, int m, int key){
    int row = find_row(mat, n, m , key);
    if(row!=-1){
        int l=0, r=m-1, mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(mat[row][mid]==key)
                return make_pair(row, mid);
            else if(mat[row][mid]>key)
                r = mid-1;
            else
                l=mid+1;
        }
    }
    return make_pair(row, -1);
}

int main(){
    int n, m, key, temp;
    cin>>n>>m;
    vector<vector<int>> mat;
    for(int i=0; i<n; i++){
        vector<int> nums;
        for(int j=0; j<m; j++) {
            cin>>temp;
            nums.push_back(temp);
        }
        mat.push_back(nums);
    }
    cin>>key;
    pair<int, int> result = matrix_binary_search(mat, n, m, key);

    if(result.first==-1 || result.second==-1) cout<<"No\n";
    else cout<<"Yes: "<<result.first<<" "<<result.second<<endl;
}

