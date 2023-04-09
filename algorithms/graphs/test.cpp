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

ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%MOD;n=(n*n)%MOD;k>>=1;}return ans%MOD;}

vi a[10];
int dist[10];
bool visited[10];



int main(){

	memset(visited, false, sizeof(visited));
	vector<pi> adj[6];
	adj[1].PB({2,5});
	adj[1].PB({4,9});
	adj[1].PB({5,1});
	adj[2].PB({1,5});
	adj[2].PB({3,2});
	adj[3].PB({2,2});
	adj[3].PB({4,6});
	adj[4].PB({3,6});
	adj[4].PB({1,9});
	adj[4].PB({5,2});
	adj[5].PB({4,2});
	adj[5].PB({1,1});

	for(int i = 1; i <= 5; i++)
		dist[i] = MOD;

	dist[1] = 0;

	priority_queue<pair<int,int>> q;
	q.push({0, 1});

	while(!q.empty()){
		int p = q.top().S;
		q.pop();
		if(visited[p])
			continue;
		for(auto x : adj[p]){
			int b, w;
			b = x.F, w = x.S;
			if(dist[b] > dist[p] +  w){
				dist[b] = dist[p] + w;
				q.push({-dist[b],b});
			}
		}
	}

	for(int i = 1; i <= 5; i++)
		cout << dist[i] << " ";

	return 0;
}
 
 