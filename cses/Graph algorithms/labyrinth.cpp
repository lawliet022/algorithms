#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1000;
char c[N][N];
bool vis[N][N];
pair<int,int> par[N][N];
int n, m;
int dir[4][5] = {{1,0},{0,1},{-1,0},{0,-1}};

char getDirection(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first+1){
		return 'U';
	}
	if(a.first == b.first-1){
		return 'D';
	}
	if(a.second == b.second+1){
		return 'L';
	}
	if(a.second == b.second-1){
		return 'R';
	}
	assert(false);
	return ' ';
}


int32_t main(){
	cin >> n >> m;
	int x1, y1, x2, y2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> c[i][j];
			if(c[i][j] == 'A'){
				x1 = i;
				y1 = j;
			}
			if(c[i][j] == 'B'){
				x2 = i;
				y2 = j;
				c[i][j] = '.';
			}
		}
	}
	queue<pair<int,int>> q;
	q.push({x1,y1});
	vis[x1][y1] = 1;
	
	while(!q.empty()){
		auto p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = p.first + dir[i][0];
			int yy = p.second + dir[i][1];
			if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] && c[xx][yy] == '.'){
				par[xx][yy] = {p.first,p.second};
				vis[xx][yy] = 1;
				q.push({xx,yy});
			}
		}
	}
	
	if(!vis[x2][y2]){
		cout << "NO";
		return 0;
	}

	string s = "";
	pair<int,int> cur = {x2,y2};
	while(par[cur.first][cur.second] != make_pair(x1,y1)){
		s += getDirection(par[cur.first][cur.second],cur);
		cur = par[cur.first][cur.second];
	}
	s += getDirection({x1,y1},cur);
	
	reverse(s.begin(),s.end());
	cout << "YES\n" << s.size() << endl;
	cout << s << endl;
	
	
	return 0;
}
