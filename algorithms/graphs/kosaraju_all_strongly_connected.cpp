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

class Graph{
	int v;
	list<int> *adj;
	
public:
	
	Graph(int v){
		this->v = v;
		adj = new list<int>[v];
	}
	
	void addEdge(int x, int y){
		adj[x].push_back(y);
	}
	
	Graph getTranspose(){
		Graph G(v);
		for(int i = 0; i < v; i++){
			for(auto x : adj[i]){
				G.adj[x].PB(i);
			}
		}
		return G;
	}
	
	void dfs(int cur, bool vis[], stack<int> &s){
		vis[cur] = true;
		for(auto x : adj[cur]){
			if(!vis[x])
				dfs(x,vis,s);
		}
		s.push(cur);
	}
	
	void dfsUtil(int cur, bool vis[]){
		vis[cur] = true;
		cout << cur << " ";
		for(auto x : adj[cur]){
			if(!vis[x])
				dfsUtil(x,vis);
		}
	}
	
	void printSCC(){
		stack<int> s;
		bool *vis = new bool[v];
		for(int i = 0; i < v; i++)
			vis[i] = false;
		for(int i = 0; i < v; i++){
			if(!vis[i])
				dfs(i,vis,s);
		}
		for(int i = 0; i < v; i++)
			vis[i] = false;
			
		Graph R = getTranspose();
		while(!s.empty()){
			int v = s.top();
			s.pop();
			if(!vis[v]){
				R.dfsUtil(v,vis);
				cout << endl;
			}
		}
	}
};


int32_t main(){
	Graph G(5);
	G.addEdge(1,0);
	G.addEdge(0,2);
	G.addEdge(2,1);
	G.addEdge(0,3);
	G.addEdge(3,4);
	G.addEdge(4,3);
	
	cout << "SCCs are - " << endl;
	G.printSCC();
	
	

	return 0;
}

