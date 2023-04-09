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

int mat[20][20];
int mod;

void matmult(int a[][20], int b[][20], int d){
	int req[20][20];
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

void nthpower(int ans[][20], int a[][20], int n, int d){
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
	int d, n, m;
	while(cin >> d >> n >> m){
		if(d == 0 && n ==0 && m == 0)
			break;
		mod = m;
		int a[d], f[d];
		for(int i = 0; i < d; i++)
			cin >> a[i];
		for(int i = 0; i < d; i++)
			cin >> f[i];
		if(n <= d){
			cout << f[n-1] << "\n";
			continue;
		}
		for(int i = 0; i < d; i++){
			mat[0][i] = a[i];
		}
		for(int i = 1; i < d; i++){
			for(int j = 0; j < d; j++){
				if(i-1 == j)
					mat[i][j] = 1;
				else
					mat[i][j] = 0;
			}
		}
		int reqPower = n - d;
		int ans[20][20];
		for(int i = 0; i < 20; i++){
			for(int j = 0; j < 20; j++){
				if(i == j)
					ans[i][j] = 1;
				else
					ans[i][j] = 0;
			}
		}
		nthpower(ans,mat,reqPower,d);
		int result = 0;
		for(int i = 0; i < d; i++){
			result += ans[0][i] * f[d-i-1];
			result %= mod;
			if(result < 0)
				result += mod;
		}
		cout << result << "\n";
	}


	return 0;
}
