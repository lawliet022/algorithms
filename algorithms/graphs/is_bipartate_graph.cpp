#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int > vi;
typedef pair<int, int> pi;
typedef vector<pi> vp;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD 1000000007
#define EPS 1e-9
#define REP(i,a,b) for(ll i=a;i<=b;i++)

#define v 4

bool isbipartite(int g[][v], int s){

	int color[4];
	memset(color,-1,sizeof color);

	color[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		
		if(g[u][u])
			return false;

		for(int i=0;i<v;i++){
			if(g[u][i] && color[i]==-1){
				color[i]=1-color[u];
				q.push(i);
			}
			else if(g[u][i] && color[i]==color[u]){
				return false;
			}
		}
	}
	return true;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int g[v][v]={{0, 1, 0, 1},
			{1, 0, 1, 0},
			{0, 1, 0, 1},
			{1, 0, 1, 0}};

	cout<< (isbipartite(g,0) ? "yes\n" : "no\n") ;

	return 0;
}
