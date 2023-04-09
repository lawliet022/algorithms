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

// For topological sorting graph should be Directed and Acyclic

const int MAX = 10;

vi adj[MAX];
bool vis[MAX];

stack<int> s;

void topological_sort(int cur){
	vis[cur] = true;
	for(auto x : adj[cur]){
		if(vis[x])
			continue;
		topological_sort(x);
	}
	s.push(cur);
}


int32_t main(){
	
	adj[5].PB(2);
    adj[5].PB(0);
    adj[4].PB(0);
    adj[4].PB(1);
    adj[2].PB(3);
    adj[3].PB(1);
    
    memset(vis, false, sizeof vis);
    
    for(int i = 0; i <= 5; i++){
		if(!vis[i]){
			topological_sort(i);
		}
	}
    
    cout << "Topological Sort -> " << endl;
    while(!s.empty()){
		cout << s.top() << "->";
		s.pop();
	}
    
    

	return 0;
}

