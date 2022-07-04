#include<bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int n, string src, string helper, string dest){
    if(n==1){
        cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }
    tower_of_hanoi(n-1, src, dest, helper);
    cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;
    tower_of_hanoi(n-1, helper, src, dest);
}

int main(){
    int n;
    cin>>n;
    tower_of_hanoi(n, "S", "H", "D");
}
