#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 2e5 + 100;
pair<int,int> seg[4*N];


pair<int,int> combine(pair<int,int> a, pair<int,int> b){
	if(a.first >= b.first)
		return a;
	return b;
}

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = {a[tl],tl};
		return;
	}
	int mid = (tl + tr) / 2;
	build(a,2*v,tl,mid);
	build(a,2*v+1,mid+1,tr);
	seg[v] = combine(seg[2*v],seg[2*v+1]);
}

pair<int,int> getMax(int v, int tl, int tr, int l, int r){
	if(l > r){
		return {-1e12,-1};
	}
	if(tl == l && tr == r){
		return seg[v];
	}
	int mid = (tl + tr) / 2;
	return combine(getMax(2*v,tl,mid,l,min(r,mid)),getMax(2*v+1,mid+1,tr,max(l,mid+1),r));
}

void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		seg[v].first += val;
		return;
	}
	int mid = (tl + tr) / 2;
	if(pos <= mid)
		update(2*v,tl,mid,pos,val);
	else
		update(2*v+1,mid+1,tr,pos,val);

	seg[v] = combine(seg[2*v],seg[2*v+1]);
}



int32_t main(){
	int n, q;
	cin >> n >> q;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	build(a,1,0,n-1);
		
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		int l = 0, r = n-1, ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			auto p = getMax(1,0,n-1,0,mid);
			if(p.first >= x){
				ans = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		if(ans != -1){
			cout << ans+1 << " ";
			update(1,0,n-1,ans,-x);
		}
		else{
			cout << 0 << " ";
		}
	}
	
	
	return 0;
}
