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

int d, n, m;

int a[30][30], b[30][30];

void matmul(int b[][30], int a[][30]){
	int res[d][d];
	for(int i = 0; i < d; i++)
		for(int j = 0; j < d; j++){
			res[i][j] = 0;
			for(int k = 0; k < d; k++){
				res[i][j] += b[i][k]*a[k][j];
				res[i][j] %= m;
			}
		}
	for(int i = 0; i < d; i++)
		for(int j = 0; j < d; j++)
			b[i][j] = res[i][j];
}


void matpow(int n){
	if(n == 0)
		return;
	matpow(n>>1);
	matmul(b,b);
	if(n&1){
		matmul(b,a);
	}
}


int32_t main(){
	while(cin >> d >> n >> m){
		if(!d && !n && !m)
			break;
		int x[d];					// Stores f[i] value
		
		// Initialising recurrance matrix
		for(int i = 0; i < d; i++)
			for(int j = 0; j < d; j++)
				a[i][j] = 0;
		
		for(int i = 0; i < d; i++)
			cin >> a[0][i];
		
		for(int i = 1; i < d; i++)
			a[i][i-1] = 1;
		
		// Identity matrix
		for(int i = 0; i < d; i++)
			for(int j = 0; j < d; j++)
				b[i][j] = (i == j ? 1 : 0);
		
		for(int i = 0; i < d; i++)
			cin >> x[i];
		
		if(n <= d){
			cout << x[n-1] % m << endl;
			continue;
		}
		matpow(n-d);
		int ans = 0;
		for(int i = 0; i < d; i++)
			ans += x[d-i-1]*b[0][i];
		ans %= m;
		cout << ans << endl;
	}

	return 0;
}

