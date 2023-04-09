#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]" << " ";
	err(++it, args...);
}

// Min number of steps form (0,0) to all houses i.e. '*' and back to (0,0) by avoiding obstacles i.e. '#'

map<pii,vector<vector<int>>> m;

vector<vi> solve(int x, int y, vector<string> s, int row, int col){
	vector<vector<int>> dis(row,vector<int>(col));
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			dis[i][j] = INT_MAX;
	queue<pair<pii,int>> q;
	map<pii,int> vis;
	q.push({{x,y},0});
	dis[x][y] = 0;
	while(!q.empty()){
		auto p = q.front();
		q.pop();
		vis[{p.F.F,p.F.S}] = true;
		dis[p.F.F][p.F.S] = p.S;
		
		int i = p.F.F;
		int j = p.F.S;
		
		if(i > 0 && s[i-1][j] != '#' && !vis[{i-1,j}]){
			q.push({{i-1,j},p.S+1});
		}
		if(j > 0 && s[i][j-1] != '#' && !vis[{i,j-1}]){
			q.push({{i,j-1},p.S+1});
		}
		if(i < row-1 && s[i+1][j] != '#' && !vis[{i+1,j}]){
			q.push({{i+1,j},p.S+1});
		}
		if(j < col-1 && s[i][j+1] != '#' && !vis[{i,j+1}]){
			q.push({{i,j+1},p.S+1});
		}
		
	}
	return dis;
}

vector<pii> v;
int fullMask;
int dp[(1<<20)+5][50];

int solve(int mask, int last, int dis){
	if(mask == fullMask){
	
		//cout << "---------Found Mask------------" << dis + m[{v[last].F,v[last].S}][0][0] << endl;
		
		return dis + m[{v[last].F,v[last].S}][0][0];
	
	}
	int &ans = dp[mask][last];
	if(ans != -1)
		return ans;
	ans = INT_MAX;
	for(int i = 1; i < (int)v.size(); i++){
		if(mask&(1<<i))
			continue;

		//cout << "Going " << v[last].F << "," << v[last].S << " -> " <<  v[i].F << "," << v[i].S << " in " << m[{v[last].F,v[last].S}][v[i].F][v[i].S] << endl;

		ans = min(ans, solve(mask|(1<<i),i,dis+m[{v[last].F,v[last].S}][v[i].F][v[i].S]));

		//cout << "Returning back to " << v[last].F << "," << v[last].S << endl ;
		
	}
	return ans;
}


int32_t main(){
	//vector<string> s = {
			//"...#.*.",
			//"...#...",
			//".*...*.",
			//"*..#..*"
		//};
		
	vector<string> s = {
			".....*.",
			"...#...",
			".*.#.*.",
			"......."
		};
	int row = 4, col = 7;
	int cnt = 0;					// No of houses
	
	m[{0,0}] = (solve(0,0,s,row,col));
	v.PB({0,0});
	
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(s[i][j] == '*'){
				cnt++;
				m[{i,j}] = (solve(i,j,s,row,col));
				v.PB({i,j});
			}
		}
	} 
	cnt++;
	
	memset(dp,-1,sizeof(dp));
	fullMask = (1<<cnt)-1;
	int ans = solve(1,0,0);
	if(ans != INT_MAX){
		cout << ans << endl;
	}
	else
		cout << "No path\n";

	return 0;
}

