#include<bits/stdc++.h>
using namespace std;

// a << b => a * 2^b
// a >>  b => a / 2^b

void print_bits(int num){
    while(num){
        cout<<(num&1)<<" ";
        num = num>>1;
    }
}

int get_bit(int numb, int pos){
    return (( numb & (1<<pos)) !=0 );
}

int set_bit(int numb, int pos){
    return ( numb | (1<<pos));
}

int clear_bit(int numb, int pos){
    return ( numb & (~(1<<pos)));
}

int update_bit(int numb, int pos, int value){
    numb = clear_bit(numb, pos);
    return ( numb | (value<<pos));
}

int no_of_digits(int num, int base){
    return log(num)/log(base) + 1;
}

bool isOdd(int num){
    return (num&1);
}

int power(int num, int expo){
    int ans = 1;
    while(expo>0){
        if((expo&1)==1)
            ans *= num;
        num *= num;
        expo = expo >> 1;
    }
}

int setBits(int num){
    int count=0;
    while(num){
        count++;
        num -= (num & -num);
    }
    return count;
}

bool ispowerof2(int num){
    return (num && !(num & (num-1)));
}

int xorTill(int num){
    if(num%4==0) return num;
    else if(num%4==1) return 1;
    else if(num%4==2) return num+1;
    else return 0;
}

int xorRange(int a, int b){
    return xorTill(b) ^ xorTill(a-1);
}

int findunique(int arr[], int n){
    int result = arr[0];
    for(int i=1; i<n; i++)
        result ^= arr[i];
    return result;
}

pair<int,int> find2unique(int arr[], int n){
    pair<int,int> result;
    int f = arr[0];
    for(int i=1; i<n; i++)
        f ^= arr[i];
    int pos = 0;
    while(get_bit(f, pos)!=1)
        pos++;
    int s = 0;
    for(int i=0; i<n; i++){
        if(get_bit(arr[i], pos) == 1)
            s ^= arr[i];
    }
    result.first = s;
    result.second = f^s;
    return result;
}

int findunique2(int arr[], int n, int occurence){
    int result = 0;
    for(int i=0; i<64; i++){
        int sum=0;
        for(int j=0; j<n; j++){
            if(get_bit(arr[j], i) == 1)
                sum++;
        }
        if(sum%occurence!=0)
            result = set_bit(result, i);
    }
    return result;
}

int numberofones(int num){
    int count=0;
    while(num){
        num = num&(num-1);
        count++;
    }
    return count;
}

vector<vector<int>> findsubsets(int arr[], int num){
    vector<vector<int>> subsets;
    for(int i=0; i<pow(2,num); i++){
        vector<int> temp;
        for(int j=0; j<num; j++){
            if(i & (1<<j))
                temp.push_back(arr[j]);
        }
        subsets.push_back(temp);
    }
    return subsets;
}

int main(){
    int n;
    int arr[7] = {1, 2, 1,  3, 2,  5};
    pair<int, int> p =find2unique(arr, 6);
    cout<<p.first<<" "<<p.second;
    return 0;
}
