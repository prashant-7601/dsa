#include<bits/stdc++.h>
using namespace std;

int friends_pairs(int n){
    if(n<=2) return n;
    return friends_pairs(n-1) + friends_pairs(n-2)*(n-1);
}

int count_tiling_ways(int n){
    if(n<=1) return n;
    return count_tiling_ways(n-1) + count_tiling_ways(n-2);
}

int count_path_maze(int n, int i, int j){
    if(i==n || j==n) return 1;
    if(i>n || j>n) return 0;
    int count=0;
    count+=count_path_maze(n, i+1, j);
    count+=count_path_maze(n, i, j+1);
    return count;
}

int count_path(int s, int e){
    if(s==e) return 1;
    if(s>e) return 0;
    int count=0;
    for(int i=1; i<=6; i++)
        count+=count_path(s+i, e);
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<friends_pairs(n);
}


