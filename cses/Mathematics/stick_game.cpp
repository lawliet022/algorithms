#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e6 + 100;
bool dp[N];

int32_t main(){
	int n, k;
	cin >> n >> k;
	
	int a[k];
	for(int i = 0; i < k; i++){
		cin >> a[i];
	}
	
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		bool ok = 0;
		for(int j = 0; j < k; j++){
			if(i-a[j] >= 0)
				ok = ok | !dp[i-a[j]];
		}
		dp[i] = ok;
	}
	
	for(int i = 1; i <= n; i++){
		if(dp[i])
			cout << 'W';
		else
			cout << 'L';
	}
	
	
	
	return 0;
}
