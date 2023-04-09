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

int32_t main(){
	vector<int> a = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
	int n = a.size();
	
	int len = sqrt(n + 0.0) + 1;
	vector<int> b(len,1e9);
	for(int i = 0; i < n; i++){
		b[i/len] = min(a[i],b[i/len]);
	}
	
	// Queries
	int l = 2, r = 4;
	int bl = l / len, br = r / len;
	int mini = 1e9;
	if(bl == br){
		for(int i = l; i <= r; i++)
			mini = min(a[i],mini);
	}
	else{
		for(int i = l, end = (bl+1)*len-1; i <= end; i++)
			mini = min(a[i],mini);
		for(int i = bl+1; i < br; i++)
			mini = min(b[i],mini);
		for(int i = br*len; i <= r; i++)
			mini = min(a[i],mini);
	}
	
	cout << "Minimum in given range = " << mini << endl;
	
	// Update a single value in O(logn)
	int pos = 3;
	a[pos] = 1;					// New value of a[pos]
	b[pos/len] = 1e9;
	for(int i = (pos/len)*len, end = (pos/len+1)*len-1; i <= end && i < n; i++){
		b[i/len] = min(b[i/len],a[i]);
	}
	
	return 0;
}
