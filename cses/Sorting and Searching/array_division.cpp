#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


bool possible(int a[], int n, int max_sum, int k){
	if(max_sum < *max_element(a,a+n)){
		return false;
	}
	int cur_sum = 0, cnt = 0;
	for(int i = 0; i < n; i++){
		if(cur_sum + a[i] > max_sum){
			cnt++;
			cur_sum = a[i];
		}
		else{
			cur_sum += a[i];
		}
	}
	cnt++;
	return (cnt <= k);
}


int32_t main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int l = 0, r = 1e16, ans = -1;
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
