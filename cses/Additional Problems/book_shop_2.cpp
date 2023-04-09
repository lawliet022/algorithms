#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 5e5;
int dp[N];			// dp[i] = min amount spent to get i pages


int32_t main(){
	int n, x;
	cin >> n >> x;
	int h[n], s[n], k[n];
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int i = 0; i < n; i++){
		cin >> k[i];
	}
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < x; j++){
			
		}
	}
	
	
	
	
	return 0;
}
