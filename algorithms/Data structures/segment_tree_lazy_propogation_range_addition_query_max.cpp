#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
int seg[4*MAX], lazy[4*MAX];


void push(int v){
	seg[2*v] += lazy[v];
	lazy[2*v] += lazy[v];
	seg[2*v+1] += lazy[v];
	lazy[2*v+1] += lazy[v];
	lazy[v] = 0;
}

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = a[tl];
	}
	else{
		int mid = (tl+tr)/2;
		build(a,2*v,tl,mid);
		build(a,2*v+1,mid+1,tr);
		seg[v] = max(seg[2*v],seg[2*v+1]);
	}
}

int getMax(int v, int tl, int tr, int l, int r){
	if(l > r)
		return -INF;
	if(tl == l && tr == r)
		return seg[v];
	push(v);
	int mid = (tl+tr)/2;
	return max(getMax(2*v,tl,mid,l,min(mid,r)),getMax(2*v+1,mid+1,tr,max(l,mid+1),r));
}


void update(int v, int tl, int tr, int l, int r, int val){
	if(l > r)
		return;
	if(tl == l && tr == r){
		seg[v] += val;
		lazy[v] += val;
	}
	else{
		push(v);
		int mid = (tl+tr)/2;
		update(2*v,tl,mid,l,min(r,mid),val);
		update(2*v+1,mid+1,tr,max(l,mid+1),r,val);
		
	}
}


int32_t main(){
	int a[] = {1,2,3,-1,4,2,3,-1,5,7};
	int n = sizeof(a)/sizeof(int);
	
	build(a,1,0,n-1);
	
	cout << getMax(1,0,n-1,1,3) << endl;
	
	update(1,0,n-1,0,1,4);
	
	cout << getMax(1,0,n-1,1,3) << endl;
	

	return 0;
}
