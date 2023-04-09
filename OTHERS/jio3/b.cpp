#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

int d4[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int d8[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

const int N = 1005;
int a[N][N];

int vis[N][N];

int n, m;

void dfs(int x, int y){
	if(a[x][y] == 0)
		return;
	a[x][y] = 0;
	for(int i = 0; i < 4; i++){
		int xx = x + d4[i][0];
		int yy = y + d4[i][1];
		if(xx >= 0 && xx < n && yy >= 0 && yy < m){
			dfs(xx,yy);
		}
	}
}



void solve(){
	cin >> n >> m;
	memset(a,0,sizeof a);
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
	for(int i = 0; i < n; i++){
		if(a[i][0] == 1)
			dfs(i,0);
		if(a[i][m-1] == 1)
			dfs(i,m-1);
	}
	
	for(int i = 0; i < m; i++){
		if(a[0][i] == 1)
			dfs(0,i);
		if(a[n-1][i] == 1)
			dfs(n-1,i);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != 0){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout << ans << endl;
	
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
