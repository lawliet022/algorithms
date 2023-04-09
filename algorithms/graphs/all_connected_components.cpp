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

bool visited[6];
vi adj[6];

void dfs(int s){
	if(visited[s])
		return;
	visited[s]=true;
	cout<<s<<"-";
	for(auto x:adj[s]){
		dfs(x);
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(visited,false,sizeof visited);

	adj[1].PB(3);
	adj[3].PB(1);
	adj[3].PB(4);
	adj[4].PB(3);
	adj[4].PB(1);
	adj[1].PB(4);
	adj[2].PB(5);
	adj[5].PB(2);

	for(int i=1;i<=5;i++){
		if(!visited[i]){
			dfs(i);
			cout<<"\n";
		}
	}
	

	return 0;
}