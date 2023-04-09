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

const int N = 5;

int solve(int g[][N], int s, int d, int k){
	if(k == 0 && s == d){
		return 1;
	}	
	if(k == 0 && s != d){
		return 0;
	}
	if(k <= 0)
		return 0;
	int res = 0;
	for(int i = 0; i < N; i++){
		if(g[s][i])
			res += solve(g,i,d,k-1);
	}
	return res;
}

void matmul(int a[][N], int b[][N]){
	int c[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			c[i][j] = 0;
			for(int k = 0; k < N; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			a[i][j] = c[i][j];
}



void matexpo(int a[][N], int g[][N], int k){
	if(k == 0)
		return;
	while(k > 0){
		if(k&1){
			matmul(a,g);
		}
		matmul(g,g);
		k >>= 1;
	}
}


int32_t main(){
	int g[N][N] = { 0, 0, 1, 0, 0, 
					1, 1, 0, 0, 0, 
					1, 0, 1, 1, 1, 
					1, 1, 0, 1, 0, 
					1, 0, 0, 0, 1};
	
	int source = 0, dest = 4, walk = 9;
	
	// Method 1 (Recursive) - O(N^(walk)) in worst case
	cout << solve(g,source,dest,walk) << endl;
	
	
	// Dynamic Programming - O(N^3 * K)
	int dp[N+1][N+1][walk+1];
	
	for(int i = 0; i <= walk; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				dp[j][k][i] = 0;
				
				if(i == 0 && j == k)
					dp[j][k][i] = 1;
				if(i == 1 && g[j][k])
					dp[j][k][i] = 1;
				if(i > 1){
					for(int l = 0; l < N; l++)
						if(g[j][l])
							dp[j][k][i] += dp[l][k][i-1];
				}
			}
		}
	}
	cout << dp[source][dest][walk] << endl;
	
	
	// Matrix Expo - O(N^3 * log(Walk))
	// Raise the adjacency matrix to kth power to get number of walks for all possible pairs
	
	int ans[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j)
				ans[i][j] = 1;
			else
				ans[i][j] = 0;
		}
	}
	matexpo(ans,g,walk);
	cout << ans[source][dest] << endl;
	
	
	return 0;
}

