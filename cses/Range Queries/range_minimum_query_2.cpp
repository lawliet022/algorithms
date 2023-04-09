#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 2e5 + 100;
int seg[4*N];

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = a[tl];
		return;
	}
	int mid = (tl + tr) / 2;
	build(a,2*v,tl,mid);
	build(a,2*v+1,mid+1,tr);
	seg[v] = min(seg[2*v],seg[2*v+1]);
}

int getMin(int v, int tl, int tr, int l, int r){
	if(l > r)
		return 1e12;
	if(tl == l && tr == r){
		return seg[v];
	}
	int mid = (tl + tr) / 2;
	return min(getMin(2*v,tl,mid,l,min(r,mid)), getMin(2*v+1,mid+1,tr,max(l,mid+1),r));
}

void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		seg[v] = val;
		return;
	}
	int mid = (tl + tr) / 2;
	if(pos <= mid)
		update(2*v,tl,mid,pos,val);
	else
		update(2*v+1,mid+1,tr,pos,val);
	seg[v] = min(seg[2*v], seg[2*v+1]);
}


int32_t main(){
	int n, q;
	cin >> n >> q;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	build(a,1,0,n-1);
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int pos, val;
			cin >> pos >> val;
			pos--;
			update(1,0,n-1,pos,val);
		}
		else{
			int l, r;
			cin >> l >> r;
			l--;	r--;
			cout << getMin(1,0,n-1,l,r) << endl;
		}
	}
	
	return 0;
}
