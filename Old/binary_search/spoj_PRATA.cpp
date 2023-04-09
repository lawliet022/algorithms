#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;


int solve(int a, int sumi){
	int l = 0, r = 1e9;
	int ans = 0;
	while(l <= r){
		int mid = (l+r)/2;
		if(mid*(2*a + (mid - 1)*a) <= 2*sumi){
			ans = mid;
			l = mid+1;
		}
		else
			r = mid-1;
	}
	return ans;
}

bool canMake(int a[], int n, int time, int c){
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += solve(a[i],time);		// Finds value of n for given AP sum
	}
	if(ans >= c)
		return true;
	else
		return false;
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int req;
		cin >> req;
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int l = 0, r = 1e9;
		int ans = 0;
		while(l <= r){
			int mid = (l+r)/2;
			if(canMake(a,n,mid,req)){
				ans = mid;
				r = mid - 1;
			}
			else{
				l = mid+1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}

