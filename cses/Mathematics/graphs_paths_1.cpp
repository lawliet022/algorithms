#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


vector<vector<int>> matMult(vector<vector<int>> &a, vector<vector<int>> &b){
	vector<vector<int>> res(a.size(),vector<int>(a.size(),0));
	int n = res.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				res[i][j] += a[i][k] * b[k][j] % MOD;
				res[i][j] %= MOD;
			}
		}
	}
	return res;
}


vector<vector<int>> matpow(vector<vector<int>> &mat, int n){
	if(n == 0){
		vector<vector<int>> id(mat.size(),vector<int>(mat.size(),0));
		for(int i = 0; i < (int)mat.size(); i++){
			id[i][i] = 1;
		}
		return id;
	}
	auto res = matpow(mat,n/2);
	res = matMult(res,res);
	if(n % 2){
		res = matMult(res,mat);
	}
	return res;
}	

int32_t main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> mat(n,vector<int>(n,0));
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--;	y--;
		mat[x][y]++;
	}
	
	auto res = matpow(mat,k);
	cout << res[0][n-1] << endl;
	
	return 0;
}
