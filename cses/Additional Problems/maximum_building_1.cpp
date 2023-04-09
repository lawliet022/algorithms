#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

// its equivalent to finding maximum area of 1's rectangle in a binary matrix

int32_t main(){
	int n, m;
	cin >> n >> m;
	int a[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			if(c == '.')
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
	int mat[n][m];
	memset(mat,0,sizeof mat);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i && a[i][j]){
				mat[i][j] = (mat[i-1][j] + 1);
			}
			else if(a[i][j]){
				mat[i][j] = 1;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		int pref[m], suff[m];
		stack<int> s;
		pref[0] = -1, suff[m-1] = m;
		s.push(0);
		for(int j = 1; j < m; j++){
			while(!s.empty() && mat[i][s.top()] >= mat[i][j]){
				s.pop();
			}
			if(!s.empty()){
				pref[j] = s.top();
			}
			else{
				pref[j] = -1;
			}
			s.push(j);
		}
		
		s = {};
		s.push(m-1);
		for(int j = m-2; j >= 0; j--){
			while(!s.empty() && mat[i][s.top()] >= mat[i][j]){
				s.pop();
			}
			if(!s.empty()){
				suff[j] = s.top();
			}
			else{
				suff[j] = m;
			}
			s.push(j);
		}
		for(int j = 0; j < m; j++){
			ans = max(ans,(suff[j]-pref[j]-1) * mat[i][j]);
		}
	}
	cout << ans << endl;
	
	return 0;
}
