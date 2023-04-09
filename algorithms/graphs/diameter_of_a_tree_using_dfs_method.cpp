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
int final;
int node;

void dfs(int s, int parent,int dis) {
	if(dis==max(dis,final)){
		final=dis;
		node=s;
	}
	for(auto u:adj[s]){
		if(u==parent)
			continue;
		dfs(u,s,dis+1);
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

	int a,b;

	final=0;
	dfs(1,0,0);

	a=node;
	final=0;
	dfs(a,0,0);
	b=node;

	cout<<"from "<<a<<" to "<<b<<"\n";



	return 0;
}