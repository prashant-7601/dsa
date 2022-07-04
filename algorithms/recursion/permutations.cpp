#include<bits/stdc++.h>
using namespace std;

string arr[10] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string s, string result, int index){
    if(index==s.length()){
        cout<<result<<endl;
        return;
    }
    string temp = arr[s[index]-'0'];
    for(int i=0; i<temp.length(); i++){
        keypad(s, result+temp[i], index+1);
    }
}

void permutations(string s, string result){
    if(s.length()==0){
        cout<<result<<endl;
        return;
    }
    for(int i=0; i<s.length(); i++){
        char ch = s.at(i);
        permutations(s.substr(0, i)+s.substr(i+1), result+ch);
    }
}

void combinations(string s, string result, int index){
    if(index==s.length()){
        cout<<result<<endl;
        return;
    }
    combinations(s, result+s.at(index), index+1);
    combinations(s, result, index+1);
}

int main(){
    string s;
    cin>>s;
    permutations(s, "");
}
