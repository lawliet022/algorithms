#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


vector<vector<int>> modmult(vector<vector<int>> &a, vector<vector<int>> &b){
	int n1 = a.size();
	int m1 = a[0].size();
	int n2 = b.size();
	int m2 = b[0].size();
	assert(m1 == n2);
	
	vector<vector<int>> res(n1,vector<int>(m2,0));
	for(int i = 0; i < n1; i++){
		for(int j = 0; j < m2; j++){
			for(int k = 0; k < m1; k++){
				res[i][j] += a[i][k] * b[k][j] % MOD;
				res[i][j] %= MOD;
			}
		}
	}
	return res;
}


vector<vector<int>> modexp(vector<vector<int>> &a, int n){
	if(n == 0){
		vector<vector<int>> id(2,vector<int>(2,0));
		id[0][0] = id[1][1] = 1;
		return id;
	}
	vector<vector<int>> res = modexp(a,n/2);
	res = modmult(res,res);
	if(n % 2){
		res = modmult(res,a);
	}
	return res;
}



int32_t main(){
	int n;
	cin >> n;
	
	if(n < 2){
		cout << n << endl;
		return 0;
	}
	vector<vector<int>> m(2,vector<int>(2));
	m = {{1,1},{1,0}};
	
	auto p = modexp(m,n-1);
	cout << p[0][0] << endl;
	
	return 0;
}
