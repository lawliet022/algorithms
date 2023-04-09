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
	vector<int> a(100,0);
	int n = a.size();
	
	int len = sqrt(n+.0) + 1;
	int b[len+1];
	
	// Updating range [l, r] with val
	int l = 2, r = 20, val = 5;
	int cl = l / len;
	int cr = r / len;
	if(cl == cr){
		for(int i = l; i <= r; i++){
			a[i] += val;
		}
	}
	else{
		for(int i = l, end = (cl+1)*len-1; i <= end; i++){
			a[i] += val;
		}
		for(int i = cl+1; i <= cr-1; i++){
			b[i] += val;
		}
		for(int i = cr*len; i <= r; i++)
			a[i] += val;
	}
	
	// Query Single value
	int ind = 3;
	cout << a[ind] + b[ind/len];


	return 0;
}
