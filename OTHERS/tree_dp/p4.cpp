#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;



// Given a tree T, where each node i has cost Ci. Steve starts at root node, and navigates to one node that he hasn't visited yet at random. 
// Steve will stop once there are no unvisited nodes. Such a path takes total time equal to sum of costs of all nodes visited. What node should be 
// assigned as root such that expected total time is minimised?

const int N = 10;
vector<int> adj[N];
int val[N];
double f[N];			// expected value when chosing only subtree i with i as root node
double g[N];			// expected value when ignoring ith subtree and chosing parent(i) as root
double ans[N];
int cnt[N];				// number of direct children of i


void dfs(int cur, int par){
	double tot = 0.0;
	for(auto x : adj[cur]){
		if(x == par)
			continue;
		dfs(x,cur);
		tot += f[x];
		cnt[cur]++;
	}
	if(cnt[cur] == 0){
		f[cur] = val[cur];
	}
	else
		f[cur] = val[cur] + tot / cnt[cur];
}

void dfs2(int cur, int par){
	if(par){
		int c = (int)adj[par].size() == cnt[par] ? cnt[par] - 1 : cnt[par];
		g[cur] = val[par] + ( (f[par] - val[par])*cnt[par] - f[cur] + g[par]) / c;
	}
	int c = par ? cnt[cur] + 1 : cnt[cur];
	ans[cur] = val[cur] + (g[cur] + (f[cur] - val[cur]) * cnt[cur]) / c;
	
	for(auto x : adj[cur]){
		if(x == par)
			continue;
		dfs2(x,cur);
	}
}


void addEdge(int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

int32_t main(){
	val[1] = 1;	val[2] = 2;	val[3] = 3;	val[4] = 1;	val[5] = 5;	val[6] = 1;	val[7] = 6;
	
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(2,5);
	addEdge(3,6);
	addEdge(6,7);
	
	
	
	dfs(1,0);
	
	dfs2(1,0);
	
	int mini = 1e12;
	int idx = -1;
	
	for(int i = 1; i <= 7; i++){
		cout << i << " -> " <<  f[i] << " " << g[i] << " " << ans[i] << "\n";
		if(ans[i] < mini){
			mini = ans[i];
			idx = i;
		}
	}
	cout << idx << endl;
	
	
	return 0;
}

