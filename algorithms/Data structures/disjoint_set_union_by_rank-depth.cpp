#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5;
int parent[MAX], depth[MAX];

void make(int n){
	parent[n] = n;
	depth[n] = 0;
}

int find(int n){
	if(n == parent[n])
		return n;
	return parent[n] = find(parent[n]);			// Path Compression
}

void unionset(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b){
		if(depth[a] < depth[b])
			swap(a,b);
		parent[b] = a;
		if(depth[a] == depth[b])
			depth[a]++;
	}
}



int32_t main(){
	
	for(int i = 1; i <= 10; i++)
		make(i);
		
	unionset(1,2);
	unionset(1,3);
	cout << find(3) << "\n";
	unionset(5,7);
	unionset(7,9);
	unionset(1,9);
	cout << find(9) << "\n";
	
	


	return 0;
}
