#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int num, res=0;
    cin>>n;
    vector<bitset<10> > arr(n);
    for(int i=0; i<n; i++){
        bitset<10> temp;
        for(int j=0; j<n; j++){
            cin>>num;
            temp[j] = num;
        }
        arr[i] = temp;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            bitset<10> temp;
            temp = arr[i]&arr[j];
            int cnt = temp.count();
            res += (cnt*(cnt-1)/2);
        }
    }
    cout<<res;
}
