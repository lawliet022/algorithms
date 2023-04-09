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


// Preprocessing in O(nlogn)	
// This sparse table method can also be applied for range gcd, range lcm, etc quaries in O(logn)
// But its main application is range min/max quaries in O(1)

int32_t main(){
	vector<int> a = {18,17,19,4,15,-2,-3,3,5,19};
	int n = a.size();
	
	//const int logn = log(n)/log(2) + 1;		// Or just hardcode it to something like 32 i.e max 2^32 length
	const int logn = 40;
	
	int spt[n][logn];
	
	for(int i = 0; i < n; i++)
		spt[i][0] = a[i];
	
	for(int j = 1; (1<<j) <= n; j++){
		for(int i = 0; i + (1 << j) <= n; i++){
			spt[i][j] = min(spt[i][j-1],spt[i+(1<<(j-1))][j-1]);
		}
	}
	
	
	
	
	// Queries
	int l = 0, r = 6;
	//int k = log(r-l+1)/log(2);			// In case of large number of quaries precompute all log2 values as below
	
	int MAX = 1e6;
	int log[MAX+1];
	log[1] = 0;
	for(int i = 2; i <= MAX; i++){
		log[i] = log[i/2] + 1;
		cout << i << "\n";
	}
	int k = log[r-l+1];
	
	cout << min(spt[l][k],spt[r-(1<<k)+1][k]) << endl;
	

	return 0;
}
