#include<bits/stdc++.h>
using namespace std;

string findSubstring(string s, int k){
    string q;
    int countVowel = 0, maxV = 0;
    for(int j=0; j<k; j++){
        if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                maxV+=1;
        }
    }
    q = s.substr(0, k);
    countVowel = maxV;
    int start=0;
    for(int i=k; i<s.length(); i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            countVowel++;
        if(s[start] == 'a' || s[start] == 'e' || s[start] == 'i' || s[start] == 'o' || s[start] == 'u')
            countVowel--;
        start++;
        if(countVowel>maxV){
            maxV = countVowel;
            q = s.substr(start, k);
        }
    }
    cout<<maxV<<endl;
    if(maxV==0)
        return "Not found!";
    return q;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    string res  = findSubstring(s, k);
    cout<<res<<endl;
}
