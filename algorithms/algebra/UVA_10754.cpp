#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int mat[30][30];
int mod;

void matmult(int a[][30], int b[][30], int d){
	int req[30][30];
	for(int i = 0; i < d; i++){
		for(int j = 0; j < d; j++){
			req[i][j] = 0;
			for(int k = 0; k < d; k++){
				req[i][j] += a[i][k] * b[k][j];
				req[i][j] %= mod;
				if(req[i][j] < 0)
					req[i][j] += mod;
			}
		}
	}
	for(int i = 0; i < d; i++){
		for(int j = 0; j < d; j++){
			a[i][j] = req[i][j];
		}
	}
}

void nthpower(int ans[][30], int a[][30], int n, int d){
	if(n == 0){
		return;
	}
	nthpower(ans,a,n/2,d);
	if(n & 1){
		matmult(ans,ans,d);
		matmult(ans,a,d);
	}
	else{
		matmult(ans,ans,d);
	}
}




int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int k, m, n;
		cin >> k >> m >> n;
		mod = m;
		int c[k+1],a[k+1];
		for(int i = 0; i < k+1; i++)
			cin >> c[i];
		for(int i = 0; i < k; i++)
			cin >> a[i];
		a[k] = c[k];
		
		if(n < k){
			int res = a[n] % mod;
			if(res < 0)
				res += mod;
			cout << res << "\n";
			if(t)
				cout << "\n";
			continue;
		}
			
		int ans[30][30], x[30][30];
		for(int i = 0; i < 30; i++){
			for(int j = 0; j < 30; j++)
				if(i == j)
					ans[i][j] = 1;
				else
					ans[i][j] = 0;
		}
		for(int i = 0; i < k; i++){
			x[0][i] = c[i];
		}
		x[0][k] = 1;
		
		for(int i = 1; i < k; i++){
			for(int j = 0; j <= k; j++){
				if(i-1 == j)
					x[i][j] = 1;
				else
					x[i][j] = 0;
			}
		}
		
		for(int i = 0; i < k; i++)
			x[k][i] = 0;
		x[k][k] = 1;
		
		//for(int i = 0; i <= k; i++){
			//for(int j = 0; j <= k; j++)
				//cout << x[i][j] << " ";
			//cout << "\n";
		//}
		//cout << "\n";
		
		int reqpow = n - k + 1;
		nthpower(ans,x,reqpow,k+1);
		
		//for(int i = 0; i <= k; i++){
			//for(int j = 0; j <= k; j++)
				//cout << ans[i][j] << " ";
			//cout << "\n";
		//}
		
		int res = 0;
		for(int i = 0; i < k; i++){
			res += ans[0][i] * a[k-i-1];
			res %= mod;
		}
		res += ans[0][k] * a[k];
		res %= mod;
		if(res < 0)
			res += mod;
		cout << res << "\n";
		if(t)
			cout << "\n";
	}


	return 0;
}
