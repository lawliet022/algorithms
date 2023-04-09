#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
//#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Offline - We already know all queries in advance and hene can process than accordingly

const int MAX = 1e5;
int parent[MAX];

void make(int n){
	parent[n] = n;
}

int find(int n){
	if(n == parent[n])
		return n;
	return parent[n] = find(parent[n]);
}

struct query{
	int l, r, c;
};



int32_t main(){
	query q[5];
	q[0] = {1,5,5};
	q[1] = {2,10,2};
	q[2] = {8,10,1};
	q[3] = {3,3,3};
	
	
	vector<int> color(20);
	fill(color.begin(),color.end(),-1);
	
	
	for(int i = 0; i < 20; i++){
		make(i);
	}
	
	for(int i = 3; i >= 0; i--){
		for(int j = find(q[i].l); j <= q[i].r; j = find(j)){
			color[j] = q[i].c;
			parent[j] = j+1;
		}
	}	
	
	for(int i = 0; i < 20; i++){
		cout << color[i] << " ";
	}

	return 0;
}
