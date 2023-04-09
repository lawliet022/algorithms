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
	vector<int> b(len,0);
	for(int i = 0; i < n; i++){
		b[i/len] += a[i];
	}
	
	// Queries
	int l = 2, r = 10;
	int bl = l / len, br = r / len;
	int sum = 0;
	if(bl == br){
		for(int i = l; i <= r; i++)
			sum += a[i];
	}
	else{
		for(int i = l, end = (bl+1)*len-1; i <= end; i++)
			sum += a[i];
		for(int i = bl+1; i < br; i++)
			sum += b[i];
		for(int i = br*len; i <= r; i++)
			sum += a[i];
	}
	
	cout << "Sum = " << sum << endl;
	
	
	// Update a single value in O(1)
	int pos = 3;
	int newVal = 10;					// New value of a[pos]
	b[pos/len] += newVal - a[pos];
	a[pos] = newVal;
	
	
	return 0;
}
