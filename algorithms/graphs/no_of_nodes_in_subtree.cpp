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
#define n 8

vi adj[n+1];
int total[n+1];


void dfs(int s, int parent) {
	total[s]=1;
	for(auto u:adj[s]){
		if(u==parent)
			continue;
		dfs(u,s);
		total[s]+=total[u];
	}
}

int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);

	adj[1].PB(2);
	adj[1].PB(3);
	adj[1].PB(4);
	adj[2].PB(1);
	adj[2].PB(5);
	adj[2].PB(6);
	adj[3].PB(1);
	adj[4].PB(1);
	adj[4].PB(7);
	adj[5].PB(2);
	adj[6].PB(2);
	adj[6].PB(8);
	adj[7].PB(4);
	adj[8].PB(6);

	memset(total,0,sizeof(total));

	dfs(1,0);

	cout<<"No of nodes in each subtree assuming 1 is parent\n";
	for(int i=1;i<=n;i++){
		cout<<i<<" has "<<total[i]<<"\n";
	}
	

	return 0;
}