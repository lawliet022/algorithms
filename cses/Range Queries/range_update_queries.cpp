#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 2e5 + 100;
int bit[N];

int n;

void update(int pos, int val){
	for(int i = pos; i < n; i=(i|(i+1))){
		bit[i] += val;
	}
}
int getSum(int pos){
	int ans = 0;
	for(int i = pos; i >= 0; i=(i&(i+1))-1){
		ans += bit[i];
	}
	return ans;
}



int32_t main(){
	int q;
	cin >> n >> q;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		update(i,a[i]);
		update(i+1,-a[i]);
	}
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int l, r, x;
			cin >> l >> r >> x;
			l--;	r--;
			update(l,x);
			update(r+1,-x);
		}
		else{
			int pos;
			cin >> pos;
			pos--;
			cout << getSum(pos) << endl;
		}
		
	}
	
	
	return 0;
}
