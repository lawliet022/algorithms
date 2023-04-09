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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n=4;

	// when graph is unweighted values in matrix are 0 or 1
	// when graph is weighted values in matrix are 0 or (weight between nodes)
	int adj[n+1][n+1]={{0, 0 , 1 , 1},
						{0, 0, 0, 1},
						{1, 0, 0, 1},
						{1, 1, 1, 1}};

	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cin>>adj[i][j];
	// 	}
	// }




	

	return 0;
}