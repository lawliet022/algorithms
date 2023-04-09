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

void matmul(int a[2][2], int b[2][2]){
	int res[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			res[i][j] = 0;
			for(int k = 0; k < 2; k++){
				res[i][j] += a[i][k]*b[k][j];
				res[i][j] %= MOD;
			}
		}
	}
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			a[i][j] = res[i][j];
}

void matpow(int a[2][2], int res[2][2], int n){
	if(n == 0)
		return;
	matpow(a,res,n>>1);
	if(n&1){
		matmul(res,res);
		matmul(res,a);
	}
	else{
		matmul(res,res);
	}
}


int32_t main(){
	// Formula for fib(m) + fib(m+1) + ... + fib(n) = fib(n+2) - fib(m+1)
	
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> m >> n;
		int a[2][2] = {0,1,1,1};		// Fibo recurrence matrix
		int res[2][2] = {1,0,0,1};		// Idendity matrix
		matpow(a,res,n+2);
		
		int fn2 = res[1][0];
		
		// resetting identity matrix
		res[0][0] = 1;
		res[0][1] = 0;
		res[1][0] = 0;
		res[1][1] = 1;
		
		matpow(a,res,m+1);
		
		int fm1 = res[1][0];
		
		cout << (fn2 - fm1 + MOD) % MOD << endl;
		
		
	}

	return 0;
}

