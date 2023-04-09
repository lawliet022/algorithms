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


int N = 5;

bool isbipartate(vi adj[]){

	int color[N+1];
	for(int i = 1; i <= N; i++){
		color[i] = -1;
	}
	
	int src = 1;
	color[src] = 1;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int t = q.front();
		q.pop();

		for(auto x : adj[t]){
			if(x == t)	
				return false;
			if(color[x] == -1){
				 color[x] = 1 - color[t];
				 q.push(x);
			}
			else if(color[x] == color[t]){
				return false;
			}
		}
	}
	return true;

}




int main(){

	 vector<int> adj[N+1];

	 adj[1].PB(2);
	 adj[1].PB(4);
	 adj[2].PB(1);
	 adj[2].PB(3);
	 adj[2].PB(5);
	 adj[3].PB(2);
	 adj[3].PB(5);
	 adj[4].PB(1);
	 adj[4].PB(5);
	 adj[5].PB(2);
	 adj[5].PB(3);
	 adj[5].PB(4);

	 cout << (isbipartate(adj) ? "Yes\n" : "No\n");
	

	return 0;
}