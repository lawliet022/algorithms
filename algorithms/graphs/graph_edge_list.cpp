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

	// If graph is unweighted
	vp edges;
	edges.PB({1,2});
	edges.PB({2,3});
	edges.PB({2,4});
	edges.PB({3,4});
	edges.PB({4,1});

	// If graph is weighted .... ex:- {1,2,3} => edge from 1->2 with wt.=3
	vector<tuple<int,int,int>> e;
	e.PB({1,2,5});
	e.PB({2,3,7});
	e.PB({2,4,6});
	e.PB({3,4,5});
	e.PB({4,1,2});


	cout<< get<1>(e[2]);
	

	return 0;
}