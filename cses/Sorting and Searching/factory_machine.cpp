#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

bool possible(int a[], int n, int tm, int total){
	int cur = 0;
	for(int i = 0; i < n; i++){
		cur += tm / a[i];
		if(cur >= total){		// condition here because cur can overflow, so return here only
			return 1;
		}
	}
	return cur >= total;
}


int32_t main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int l = 1, r = 1e18;
	int ans = -1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(possible(a,n,mid,k)){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << ans << endl;
	
	return 0;
}
