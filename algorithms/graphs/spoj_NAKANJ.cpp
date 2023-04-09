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

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		string start, end;
		cin >> start >> end;
		int x1, y1, x2, y2;
		x1 = start[0] - 'a';
		y1 = start[1] - '1';
		x2 = end[0] - 'a';
		y2 = end[1] - '1';
		queue<pair<pii,int>> q;
		map<pair<int,int>,int> vis;
		q.push({{x1,y1},0});
		vis[{x1,y1}] = 1;
		while(!q.empty()){
			int curx = q.front().F.F;
			int cury = q.front().F.S;
			int dis = q.front().S;
			q.pop();
			if(curx == x2 && cury == y2){
				cout << dis << endl;
				break;
			}
			if(curx-1>=0 && cury-2>=0 && !vis[{curx-1,cury-2}]){
				vis[{curx-1,cury-2}] = 1;
				q.push({{curx-1,cury-2},dis+1});
			}
			if(curx+1<=7 && cury-2>=0 && !vis[{curx+1,cury-2}]){
				vis[{curx+1,cury-2}] = 1;
				q.push({{curx+1,cury-2},dis+1});
			}
			if(curx-1>=0 && cury+2<=7 && !vis[{curx-1,cury+2}]){
				vis[{curx-1,cury+2}] = 1;
				q.push({{curx-1,cury+2},dis+1});
			}
			if(curx+1<=7 && cury+2<=7 && !vis[{curx+1,cury+2}]){
				vis[{curx+1,cury+2}] = 1;
				q.push({{curx+1,cury+2},dis+1});
			}
			
			if(curx-2>=0 && cury-1>=0 && !vis[{curx-2,cury-1}]){
				vis[{curx-2,cury-1}] = 1;
				q.push({{curx-2,cury-1},dis+1});
			}
			if(curx+2<=7 && cury-1>=0 && !vis[{curx+2,cury-1}]){
				vis[{curx+2,cury-1}] = 1;
				q.push({{curx+2,cury-1},dis+1});
			}
			if(curx-2>=0 && cury+1<=7 && !vis[{curx-2,cury+1}]){
				vis[{curx-2,cury+1}] = 1;
				q.push({{curx-2,cury+1},dis+1});
			}
			if(curx+2<=7 && cury+1<=7 && !vis[{curx+2,cury+1}]){
				vis[{curx+2,cury+1}] = 1;
				q.push({{curx+2,cury+1},dis+1});
			}
		}
	}

	return 0;
}
