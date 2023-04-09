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
pair<int,int> seg[4*MAX];

pair<int,int> combine(pii a, pii b){
	if(a.F > b.F)
		return a;
	if(a.F < b.F)
		return b;
	return {a.F,a.S+b.S};
}


void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = MP(a[tl],1);
	}
	else{
		int mid = (tl + tr)/2;
		build(a,2*v,tl,mid);
		build(a,2*v+1,mid+1,tr);
		seg[v] = combine(seg[2*v],seg[2*v+1]);
	}
}

pair<int,int> getRes(int v, int tl, int tr, int l, int r){
	if(l > r)
		return {-1,-1};
	if(tl == l && tr == r){
		return seg[v];
	}
	else{
		int mid = (tl+tr)/2;
		return combine(getRes(2*v,tl,mid,l,min(mid,r)),
						getRes(2*v+1,mid+1,tr,max(l,mid+1),r));
	}
}

void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		seg[v] = {val,1};
	}
	else{
		int mid = (tl+tr)/2;
		if(pos <= mid)
			update(2*v,tl,mid,pos,val);
		else
			update(2*v+1,mid+1,tr,pos,val);
			
		seg[v] = combine(seg[2*v],seg[2*v+1]);
	}
}


int32_t main(){
	int a[] = {1,2,3,4,3,4,2,4,4,3,3,3,2,2,1,2};
	int n = sizeof(a)/sizeof(int);
	
	build(a,1,0,n-1);
	
	pii x = getRes(1,0,n-1,1,4);
	cout << "Max is " << x.F << " and its count in given range is " << x.S << endl;

	update(1,0,n-1,3,2);
	
	x = getRes(1,0,n-1,1,4);
	cout << "After update Max is " << x.F << " and its count in given range is " << x.S << endl;
	

	return 0;
}
