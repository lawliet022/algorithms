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

struct data{
	int sum, pref, suff, best;
};
const int MAX = 1e5;
data seg[4*MAX];


data make_data(int x){
	data temp;
	temp.sum = x;	
	temp.pref = temp.suff = temp.best = max(0LL,x);
	
	return temp;
}

data combine(data x, data y){
	data temp;
	temp.sum = x.sum + y.sum;
	temp.pref = max(x.pref,x.sum+y.pref);
	temp.suff = max(y.suff,x.suff+y.sum);
	temp.best = max(x.suff+y.pref,max(x.best, y.best));
	return temp;
}


void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = make_data(a[tl]);
	}
	else{
		int mid = (tl+tr)/2;
		build(a,2*v,tl,mid);
		build(a,2*v+1,mid+1,tr);
		seg[v] = combine(seg[2*v],seg[2*v+1]);
	}
}

data getMaxSum(int v, int l, int r, int tl, int tr){
	if(l > r)
		return make_data(0);
	if(tl == l && tr == r){
		return seg[v];
	}
	else{
		int mid = (tl+tr)/2;
		return combine(getMaxSum(2*v,l,min(r,mid),tl,mid),getMaxSum(2*v+1,max(mid+1,l),r,mid+1,tr));
	}
}

void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		seg[v] = make_data(val);
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
	int a[] = {1,2,-1,-2,-3,3,-2,3,-1,5};
	int n = sizeof(a)/sizeof(int);
	
	build(a,1,0,n-1);
	
	// Query for max sum in a range
	cout << getMaxSum(1,5,7,0,n-1).best << endl;
	
	update(1,0,n-1,6,2);
	
	cout << getMaxSum(1,5,7,0,n-1).best << endl;
	


	return 0;
}
