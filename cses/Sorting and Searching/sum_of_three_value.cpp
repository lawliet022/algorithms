#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n, target;
	cin >> n >> target;
	pair<int,int> a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i+1;
	}
	sort(a,a+n);
	
	for(int i = 0; i < n-2; i++){
		if(a[i].first > target)
			break;
		int req = target - a[i].first;
		int l = i+1, r = n-1;
		while(l < r){
			int val = a[l].first + a[r].first;
			if(val == req){
				cout << a[i].second << " " << a[l].second << " " << a[r].second << endl;
				return 0;
			}
			if(val < req){
				l++;
			}
			else{
				r--;
			}
		}
	}
	cout << "IMPOSSIBLE";
	
	
	return 0;
}
