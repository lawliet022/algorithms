#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

vector<vector<int>> matMult(vector<vector<int>> &a, vector<vector<int>> &b){
	vector<vector<int>> v(6,vector<int>(6,0));
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			for(int k = 0; k < 6; k++){
				v[i][j] += a[i][k] * b[k][j] % MOD;
				v[i][j] %= MOD;
			}
		}
	}
	return v;
}


vector<vector<int>> matExpo(vector<vector<int>> &v, int n){
	if(n == 0){
		vector<vector<int>> id(6,vector<int>(6,0));
		for(int i = 0; i < 6; i++){
			id[i][i] = 1;
		}
		return id;
	}
	vector<vector<int>> res = matExpo(v,n/2);
	res = matMult(res,res);
	if(n % 2){
		res = matMult(res,v);
	}
	return res;
}


int32_t main(){
	int n;
	cin >> n;
	int a[10] = {0};
	a[0] = 1;
	for(int i = 1; i < 6; i++){
		for(int j = 1; j <= 6; j++){
			if(i-j >= 0)
				a[i] += a[i-j];
		}
	}
	
	if(n <= 5){
		cout << a[n] << endl;
		return 0;
	}
	vector<vector<int>> v(6,vector<int>(6,0));
	for(int i = 0; i < 6; i++)
		v[0][i] = 1;
	v[1][0] = v[2][1] = v[3][2] = v[4][3] = v[5][4] = 1;
	
	vector<vector<int>> res = matExpo(v,n-5);
	
	int ans = 0;
	
	for(int i = 0; i < 6; i++){
		ans = (ans + res[0][i] * a[5-i] % MOD);
	}
	ans %= MOD;
	
	cout << ans << endl;
	
	
	return 0;
}
