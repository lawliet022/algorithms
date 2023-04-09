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

vi adj[6];
bool visited[6];
int num;
int edges;

bool iscyclic(int s, int parent){

	visited[s] = true;
	cout << "Visited " << s <<"\n";

	for(auto u : adj[s]){
		if(!visited[u]){
			if(iscyclic(u, s)){
				return true;
			}
		}

		else{
			if(u != parent){
				return true;
			}	
		}
	}
	return false;
}

void dfs(int s){
	if(visited[s])
		return;
	num++;
	visited[s] = true;
	for(auto x : adj[s]){
		dfs(x);
		edges++;
	}	
}



int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);

	memset(visited, false, sizeof visited);

	adj[1].PB(3);
	adj[3].PB(1);
	adj[1].PB(4);
	adj[4].PB(1);
	adj[3].PB(4);
	adj[4].PB(3);
	adj[3].PB(5);
	adj[5].PB(3);
	adj[3].PB(2);
	adj[2].PB(3);
	adj[2].PB(5);
	adj[5].PB(2);


	// Because here in this there is only one component so no loop over nodes is required
	if(iscyclic(1, -1)){
		cout << "Cycle found\n";
	}
	else{
		cout << "Not found\n";
	}


	// Or alternatively, if number of edges in a component is greater than nodes-1 (i.e. not a tree) - (Undirected Only)
	// => Cycle is there

	memset(visited, false, sizeof visited);
	dfs(1);

	cout << "No of Nodes = "<< num << "\n No of edges " << edges/2 <<"\n";
	
	if(edges/2 > num - 1){
		cout << "Cycle found\n";
	}
	else{
		cout << "No cycle found\n";
	}
	


	// for(int i = 1; i <= 5; i++){
	// 	if(!visited[i]){
	// 		if(iscyclic(i, -1)){
	// 			cout << "Cycle found\n";
	// 			break;
	// 		}
	// 	}
	// }


	

	return 0;
}
