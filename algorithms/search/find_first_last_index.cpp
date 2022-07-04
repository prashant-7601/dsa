#include<bits/stdc++.h>
using namespace std;

pair<int, int> find_answer(int arr[], int n, int key){
	pair<int, int> ans;
	ans.first = -1;
	ans.second = -1;

	int l = 0, r=n-1, mid;
	while(l<=r) {
		mid = (l+r)/2;
		if(arr[mid] == key){
			ans.first = mid;
			r = mid-1;
		}
		else if(arr[mid] < key)
			l = mid+1;
		else
			r = mid-1;
	}
	l = 0, r=n-1;
	while(l<=r) {
		mid = (l+r)/2;
		if(arr[mid] == key){
			ans.second = mid;
			l = mid+1;
		}
		else if(arr[mid] < key)
			l = mid+1;
		else
			r = mid-1;
	}
	return ans;
}

int main() {
	int n, key;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cin>>key;
	pair<int, int> ans = find_answer(arr, n, key);
	cout<<ans.first<<" "<<ans.second<<endl;
}
