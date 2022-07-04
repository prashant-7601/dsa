#include<bits/stdc++.h>
using namespace std;

string move_to_last(string s, string result, int n, int index, int count, char ch){
    if(index==n){
        while(count--) result+=ch;
        return result;
    }
    if(s.at(index)==ch) count++;
    else result+=s.at(index);
    return move_to_last(s, result, n, index+1, count, ch);
}

int fibonacci(int n){
    if(n<2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

bool check_sorted(int arr[], int n, int index){
    if(index==n-1)
        return true;
    if(arr[index]<arr[index+1])
        return check_sorted(arr, n, index+1);
    else
        return false;
}

int find_last(int arr[], int n, int index, int key){
   if(index==-1)
        return -1;
   if(arr[index]==key)
        return index;
   else
        return find_last(arr, n, index-1, key);
}

int find_first(int arr[], int n, int index, int key){
   if(index==n)
        return -1;
   if(arr[index]==key)
        return index;
   else
        return find_first(arr, n, index+1, key);
}

int main(){
    int n;
    cin>>n;
    //int fibo = fibonacci(n);
    //cout<<n<<"th fibonacci number: "<<fibo<<endl;
    //int arr[n];
    //for(int i=0; i<n; i++) cin>>arr[i];
    //cin>>key;
    //cout<<find_first(arr, n, 0, key)<<" "<<find_last(arr, n, n-1, key);
    string s;
    char key;
    cin>>s>>key;
    cout<<move_to_last(s, "", n, 0, 0, key);
}
