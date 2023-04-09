#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 505;
int dis[N][N];

int32_t main(){
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i != j){
				dis[i][j] = 1e16;
			}
			else{
				dis[i][i] = 0;
			}
		}
	}
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		dis[x][y] = min(dis[x][y],w);
		dis[y][x] = min(dis[y][x],w);
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	
	while(q--){
		int x, y;
		cin >> x >> y;
		if(dis[x][y] == (int)1e16){
			cout << -1 << endl;
		}
		else{
			cout << dis[x][y] << endl;
		}
	}
	
	return 0;
}
