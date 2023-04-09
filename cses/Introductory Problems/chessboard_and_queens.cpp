#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


char c[8][8];
int diag1[20], diag2[20], col[8];

int solve(int row){
	if(row == 8){
		return 1;
	}
	int ans = 0;
	for(int i = 0; i < 8; i++){
		if(col[i] || diag1[row+i] || diag2[8+row-i] || c[row][i] == '*'){
			continue;
		}
		col[i] = diag1[row+i] = diag2[8+row-i] = 1;
		ans += solve(row+1);
		col[i] = diag1[row+i] = diag2[8+row-i] = 0;
	}
	return ans;
}


int32_t main(){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cin >> c[i][j];
		}
	}
	cout << solve(0) << endl;
	
	return 0;
}
