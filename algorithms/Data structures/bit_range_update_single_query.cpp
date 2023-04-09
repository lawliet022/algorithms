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
int bit[MAX];
int n;

void add(int x, int val){
	for(int i = x; i < n; i = (i|(i+1)))
		bit[i] += val;
}

int getSum(int x){
	int res = 0;
	for(int i = x; i >= 0; i = (i&(i+1))-1){
		res += bit[i];
	}
	return res;
}

void rangeAdd(int l, int r, int val){
	add(l,val);
	if(r < n-1){
		add(r+1,-val);
	}
}


int32_t main(){
	n = 10;
	
	// Range Update
	int l = 2, r = 8, val = 2;		// Adding 2 to range [2,8]
	rangeAdd(l,r,val);
	
	l = 3, r = 7, val = 3;			// Adding 3 to range [3,7]
	rangeAdd(l,r,val);
	
	
	// Single Query
	int x = 2;
	cout << getSum(x);				// Getting value of a[x]

	return 0;
}
