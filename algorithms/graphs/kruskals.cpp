#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int > vi;
typedef pair<int, int> pi;
typedef vector<pi> vp;
typedef tuple<int, int, int> ti;


#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD 1000000007
#define EPS 1e-9
#define REP(i,a,b) for(ll i=a;i<=b;i++)
#define n 6

int parent[n+1];
int size[n+1];


int find(int x){
	while(x != parent[x])
		x = parent[x];
	return x;
}

bool same(int a, int b){
	return find(a) == find(b);
}

bool unite(int a, int b){
	a = find(a);
	b = find(b);
	if(size[a] < size[b])
		swap(a, b);
	size[a] += size[b];
	parent[b] = a;
}


bool comp(ti a,ti b){
	return (get<2>(a) < get<2>(b));
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}

	vector<ti> edges;
	edges.PB({1,2,3});
	edges.PB({1,5,5});
	edges.PB({2,5,6});
	edges.PB({2,3,5});
	edges.PB({5,6,2});
	edges.PB({3,6,3});
	edges.PB({3,4,9});
	edges.PB({6,4,7});

	edges.PB({2,1,3});
	edges.PB({5,1,5});
	edges.PB({5,2,6});
	edges.PB({3,2,5});
	edges.PB({6,5,2});
	edges.PB({6,3,3});
	edges.PB({4,3,9});
	edges.PB({4,6,7});

	sort(edges.begin(),edges.end(),comp);

	int a, b;
	int wt = 0;
	for(auto x : edges){
		a = get<0>(x);
		b = get<1>(x);	
		if(!same(a,b)){
			unite(a,b);
			cout << "Added edge " << a << " to " << b << "\n";
			wt += get<2>(x);
		}
	}

	cout << "Wt of MST=" << wt << "\n";

	return 0;
}