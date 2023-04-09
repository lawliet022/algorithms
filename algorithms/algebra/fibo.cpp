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

void matrixmult(int a[2][2], int b[2][2]){
	int res[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			res[i][j] = 0;
			for(int k = 0; k < 2; k++){
				res[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			a[i][j] = res[i][j];
}

void nthpower(int a[2][2], int res[2][2], int n){		// matrix^n
	if(n == 0){
		return;
	}
	nthpower(a, res, n/2);
	if(n & 1){
		matrixmult(res,res);
		matrixmult(res,a);
	}
	else
		matrixmult(res,res);
}

pair<int,int> fib(int n){
	if(n == 0){
		return {0,1};
	}
	pair<int,int> p = fib(n >> 1);
	int c = p.F * (2*p.S - p.F);
	int d = p.F * p.F + p.S * p.S;
	if(n & 1){
		return {d,c+d};
	}
	else
		return {c,d};
}


int32_t main(){
	for(int n = 0; n <= 100; n++){
		int a[2][2] = {0,1,1,1};
		int res[2][2] = {1,0,0,1};
		nthpower(a,res,n);
		
		// (fn  fn+1) = (f0 f1)*(0 1)^n
		//						(1 1)
		
		int fn = res[1][0];		// nth term
		
		cout << fn << " " << fib(n).F << "\n";
	}

	return 0;
}
