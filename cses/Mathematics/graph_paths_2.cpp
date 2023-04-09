#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

void print(vector<vector<int>> v){
	for(auto x : v){
		for(auto y : x){
			cerr << y << " ";
		}
		cerr << endl;
	}
}

auto matMin(vector<vector<int>> &a, vector<vector<int>> &b){
	int n = a.size();
	vector<vector<int>> res(n,vector<int>(n,(int)2e18));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				res[i][j] = min(res[i][j],a[i][k]+b[k][j]);
			}
		}
	}
	return res;
}


auto matExpo(vector<vector<int>> &mat, int k){
	if(k == 0){
		int n = mat.size();
		vector<vector<int>> id(n,vector<int>(n,2e18));
		for(int i = 0; i < n; i++)
			id[i][i] = 0;
		return id;
	}
	auto res = matExpo(mat,k/2);
	res = matMin(res,res);
	if(k % 2){
		res = matMin(res,mat);
	}
	return res;
}

int32_t main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> mat(n,vector<int>(n,2e18));
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		x--;	y--;
		mat[x][y] = min(mat[x][y],w);
	}
	auto res = matExpo(mat,k);
	if(res[0][n-1] < 2e18){
		cout << res[0][n-1] << endl;
	}
	else{
		cout << -1 << endl;
	}
	
	return 0;
}
