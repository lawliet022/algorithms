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
const int INF = 1e9;
vector<int> seg[4*MAX];

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v].PB(a[tl]);
	}
	else{
		int mid = (tl+tr)/2;
		build(a,2*v,tl,mid);
		build(a,2*v+1,mid+1,tr);
		merge(seg[2*v].begin(),seg[2*v].end(),seg[2*v+1].begin(),seg[2*v+1].end(),back_inserter(seg[v]));
	}
}

int getElement(int v, int l, int r, int tl, int tr, int ele){
	if(l > r)
		return INF;
	if(tl == l && tr == r){
		auto p = lower_bound(seg[v].begin(),seg[v].end(),ele);
		if(p == seg[v].end())
			return INF;
		else
			return *p;
	}
	else{
		int mid = (tl+tr)/2;
		return min(getElement(2*v,l,min(r,mid),tl,mid,ele), getElement(2*v+1,max(mid+1,l),r,mid+1,tr,ele));
	}
}


int32_t main(){
	int a[] = {5,1,9,3,7,4,11,105,64,32,-1,39};
	int n = sizeof(a)/sizeof(int);
	
	build(a,1,0,n-1);
	
	cout << getElement(1,7,n-1,0,n-1,-2) << endl;
	

	return 0;
}
