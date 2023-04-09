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
int bit1[MAX], bit2[MAX];
int n;

void add(int b[], int index, int val){
	for(int i = index; i < n; i = i|(i+1))
		b[i] += val;
}

int getSum(int b[], int x){
	int ans = 0;
	for(int i = x; i >= 0; i = (i&(i+1))-1){
		ans += b[i];
	}
	return ans;
}

void range_update(int l, int r, int val){
	add(bit1,l,val);
	add(bit1,r+1,-val);
	add(bit2,l,val*(l-1));
	add(bit2,r+1,-val*r);
	
}

int range_sum(int l, int r){
	return (getSum(bit1,r)*r - (l > 0 ? getSum(bit1,l-1)*(l-1) : 0)) - (getSum(bit2,r) - (l > 0 ? getSum(bit2,l-1) : 0));
}


int32_t main(){
	vi a = {0,0,0,0,0,0,0,0,0,0};
	n = a.size();
	
	range_update(1,5,2);
	range_update(3,7,2);
	
	cout << range_sum(5,7);

	return 0;
}
