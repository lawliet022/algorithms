#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

int cost(int a[], int n, int p){
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += abs(a[i]-p);
	}
	return ans;
}

void solve(int a[], int n){							
	int l = a[0], r = a[n-1], ans = l;
	while(l < r){
		int mid = (l + r) / 2;
		if(cost(a,n,mid) < cost(a,n,mid+1)){
			ans = mid;
			r = mid-1;
		}
		else{
			ans = mid+1;
			l = mid+1;
		}
	}
	
	int res = 1e16;
	for(int p : {ans-1,ans,ans+1}){
		res = min(res,cost(a,n,p));
	}
	cout << res << endl;
}

void solve2(int a[], int n){
	int ans = 1e16;
	int suff[n+1] = {0};
	for(int i = n-1; i >= 0; i--){
		suff[i] = suff[i+1] + a[i];
	}
	int pref = 0;
	for(int i = 0; i < n; i++){
		int left = i, right = n - i - 1;
		ans = min(ans,left*a[i]-pref+suff[i+1]-right*a[i]);
		pref += a[i];
	}
	
	cout << ans << endl;
	
}


int32_t main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	
	//solve(a,n);			// alternate ternery search solution
	//solve2(a,n);			// another solution using prefix and suff sum
	
	// its always optimal to take them to the value of middle element in array
	int opt = a[n / 2];
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += abs(opt-a[i]);
	}
	cout << ans << endl;
	
	
	
	return 0;
}



