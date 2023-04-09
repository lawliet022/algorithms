#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

long double dp[105][605];

int32_t main(){
	int n, a, b;
	cin >> n >> a >> b;	
	dp[0][0] = 1.0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 6; j++){
			for(int k = 0; k <= b; k++){
				if(k-j >= 0){
					dp[i][k] += dp[i-1][k-j] / 6.0;
				}
			}
		}
	}
	long double p = 0;
	for(int i = a; i <= b; i++){
		p += dp[n][i];
	}
	cout << fixed << setprecision(6) << p << endl;
	
	
	return 0;
}
