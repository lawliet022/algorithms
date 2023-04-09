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
bool marked[4*MAX];


void push(int x){
	if(marked[x]){
		marked[x] = false;
		seg[2*x] = seg[2*x+1] = seg[x];
		marked[2*x] = marked[2*x+1] = true;
	}
}

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = a[tl];
		marked[v] = true; 
	}
	else{
		int mid = (tl+tr)/2;
		build(a,2*v,tl,mid);
		build(a,2*v+1,mid+1,tr);
	}
}


int getValue(int v, int tl, int tr, int pos){
	if(tl == tr){
		return seg[v];
	}
	else{
		push(v);
		int mid = (tl+tr)/2;
		if(pos <= mid)
			return getValue(2*v,tl,mid,pos);
		else
			return getValue(2*v+1,mid+1,tr,pos);
	}
}


// Or Rather instead of pushing delayed updates just return as soon as you encounter a marked state
int getValue2(int v, int tl, int tr, int pos){
	if(marked[v])
		return seg[v];
	if(tl == tr){
		return seg[v];
	}
	else{
		int mid = (tl+tr)/2;
		if(pos <= mid)
			return getValue(2*v,tl,mid,pos);
		else
			return getValue(2*v+1,mid+1,tr,pos);
	}
}

void update(int v, int tl, int tr, int l, int r, int val){
	if(l > r)
		return;
	if(tl == l && tr == r){
		push(v);
		marked[v] = true;
		seg[v] = val;
	}
	else{
		push(v);
		int mid = (tl+tr)/2;
		update(2*v,tl,mid,l,min(r,mid),val);
		update(2*v+1,mid+1,tr,max(l,mid+1),r,val);
	}
}

int32_t main(){
	int a[] = {1,2,3,4,5,4,3,2,1,2,3,4,5,6,7,8,9};
	int n = sizeof(a)/sizeof(int);
	
	build(a,1,0,n-1);
	
	cout << getValue(1,0,n-1,3) << endl;
	
	update(1,0,n-1,2,6,10);
	update(1,0,n-1,5,12,20);
	
	cout << getValue(1,0,n-1,3) << endl;
	
	cout << getValue(1,0,n-1,5) << endl;
	

	return 0;
}
