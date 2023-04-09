#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1000;
char c[N][N];
bool vis[N][N];

int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n, m;

void dfs(int x, int y){
	vis[x][y] = true;
	for(int i = 0; i < 4; i++){
		int xx = dir[i][0] + x;
		int yy = dir[i][1] + y;
		if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] && c[xx][yy] == '.'){
			dfs(xx,yy);
		}
	}
}


int32_t main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> c[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!vis[i][j] && c[i][j] == '.'){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
