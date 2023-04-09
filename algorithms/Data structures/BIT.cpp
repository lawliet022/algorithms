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



// Single Update and Range Query
const int MAX = 1e5;
int bit[MAX];
int n;

void add(int index, int val){
	for(int i = index; i < n; i = i|(i+1))
		bit[i] += val;
}

int getSum(int x){
	int ans = 0;
	for(int i = x; i >= 0; i = (i&(i+1))-1){
		ans += bit[i];
	}
	return ans;
}


int32_t main(){
	vector<int> a = {1,3,5,6,7,8,9,10,5};
	n = a.size();
	
	for(int i = 0; i < n; i++)
		add(i,a[i]);
		
	
	// Sum Queries
	int l = 0, r = 4;
	
	cout << getSum(r) - (l > 0 ? getSum(l-1) : 0);
	
	// Update Queries
	
	add(1,3);		// Adding 3 to a[1] 


	return 0;
}
