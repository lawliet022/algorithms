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
#define n 5
#define INF 100000000



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int adj[n][n]={{0, 5, 0, 9, 1},
						{5, 0, 2, 0, 0},
						{0, 2, 0, 6, 0},
						{9, 0, 6, 0, 2},
						{1, 0, 0, 2, 0}};

	int distance[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				distance[i][j]=0;
			else if(adj[i][j]){
				distance[i][j]=adj[i][j];
			}
			else
				distance[i][j]=INF;
		}
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
			}
		}
	}
	
	// Distance from a fixes source to all other nodes
	for(int i=0;i<n;i++){
		cout<<distance[0][i]<<"\n";
	}

	return 0;
}