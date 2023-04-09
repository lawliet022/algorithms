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
int seg[4*MAX];

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = a[tl];
	}
	else{
		int mid = (tl+tr)/2;
		build(a,2*v,tl,mid);
		build(a,2*v+1,mid+1,tr);
		seg[v] = 0;
	}
}

int getValue(int v, int tl, int tr, int pos){
	if(tl == tr){
		return seg[v];
	}
	else{
		int mid = (tl+tr)/2;
		if(pos <= mid)
			return seg[v] + getValue(2*v,tl,mid,pos);
		else
			return seg[v] + getValue(2*v+1,mid+1,tr,pos);
	}
}

void update(int v, int tl, int tr, int l, int r, int val){
	if(l > r)
		return;
	if(tl == l && tr == r){
		seg[v] += val;
	}
	else{
		int mid = (tl+tr)/2;
		update(2*v,tl,mid,l,min(mid,r),val);
		update(2*v+1,mid+1,tr,max(mid+1,l),r,val);
	}
}

int32_t main(){
	int a[] = {1,2,3,4,5,6,5,4,3,2,1};
	int n = sizeof(a)/sizeof(int);
	
	build(a,1,0,n-1);
	
	update(1,0,n-1,1,4,3);
	update(1,0,n-1,3,7,2);
	
	cout << getValue(1,0,n-1,2);

	return 0;
}
