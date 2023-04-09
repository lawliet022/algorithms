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

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		int dp[n+1][n+1];
		const int INF = 1e9;
		
		map<pair<int,int>,string> m;
		
		map<int, char> m2;
		
		for(int i = 0; i < n; i++)
			m2[i] = 'A' + i;
		
		
		for(int i = n-1; i >= 0; i--){
			for(int j = 0; j < n; j++){
				if(i+1 == j){
					m[{i,j}] = m2[i];
				}
				if(j-i < 2){
					dp[i][j] = 0;
				}
				else if(j-i == 2){
					dp[i][j] = a[i]*a[i+1]*a[i+2];
					m[{i,j}] = '(';
					m[{i,j}] += m2[i];
					m[{i,j}] += m2[i+1];
					m[{i,j}] += ')';
				}
				else{
					dp[i][j] = INF;
					for(int k = i+1; k < j; k++){
						if(dp[i][k] + dp[k][j] + a[i]*a[k]*a[j] < dp[i][j]){
							m[{i,j}] = '(';
							m[{i,j}] += m[{i,k}];
							m[{i,j}] += m[{k,j}];
							m[{i,j}] += ')';
							dp[i][j] = dp[i][k] + dp[k][j] + a[i]*a[k]*a[j];
						}
					}
				}
			}
		}
		cout << m[{0,n-1}] << endl;
		
	}

	return 0;
}
s
