#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

map<pii,int> m;

int solve(int a[], int n, int cur, int gcd){
	if(cur == n){
		if(gcd == 1)
			return 1;
		else
			return 0;
	}
	if(m.count({cur,gcd}))
		return m[{cur,gcd}];
	
	return m[{cur,gcd}] = solve(a,n,cur+1,gcd) + solve(a,n,cur+1,__gcd(gcd,a[cur]));
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		m.clear();
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		int ans = 0;
		
		for(int i = 0; i < n-1; i++)
			ans += solve(a,n,i+1,a[i]);
		
		cout << ans << endl;
	}

	return 0;
}

