#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt = 0;
    while(n%2==0){
        cnt++;
        n/=2;
    }
    cout<<"2 "<<cnt<<endl;
    for(int i=3; i*i<=n; i+=2){
        cnt = 0;
        while(n%i==0){
            cnt++;
            n/=i;
        }
        if(cnt)
            cout<<i<<" "<<cnt<<endl;
    }
    if(n>1) cout<<n<<" 1\n";
}
