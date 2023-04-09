#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);
 
struct node{
	int pref, suff, best, total;
};
 
node combine(node a, node b){
	node n;
	n.pref = max(a.pref,a.total+b.pref);
	n.suff = max(b.suff,b.total+a.suff);
	n.total = a.total + b.total;
	n.best = max({a.best,b.best,n.pref,n.suff,a.suff+b.pref});
	return n;
}
 
node make(int x){
	node n;
	n.pref = max(0LL,x);
	n.suff = max(0LL,x);
	n.total = x;
	n.best = max(0LL,x);
	return n;
}
 
const int N = 2e5 + 100;
node seg[4*N];
 
void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = make(a[tl]);
		return;
	}
	int mid = (tl + tr) / 2;
	build(a,2*v,tl,mid);
	build(a,2*v+1,mid+1,tr);
	seg[v] = combine(seg[2*v],seg[2*v+1]);
}
 
void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		seg[v] = make(val);
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
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	build(a,1,0,n-1);
	
	while(q--){
		int pos, val;
		cin >> pos >> val;
		pos--;
		update(1,0,n-1,pos,val);
		cout << seg[1].best << endl;
	}
	return 0;
}
