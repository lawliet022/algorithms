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
int seg[4*MAX];
int a[MAX];
void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = (a[tl] == 0 ? 1 : 0);
	}
	else{
		int mid = (tl+tr)/2;
		build(a,2*v,tl,mid);
		build(a,2*v+1,mid+1,tr);
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}

int getCount(int v, int l, int r, int tl, int tr){
	if(l > r)
		return 0;
	if(l == tl && r == tr){
		return seg[v];
	}
	else{
		int mid = (tl+tr)/2;
		return getCount(2*v,l,min(r,mid),tl,mid) + getCount(2*v+1,max(l,mid+1),r,mid+1,tr);
	}
}


// Similar idea can be applied to problems like finding min index i such that prefix sum till that index is greater than equal 
// to some given number (p.s this problem can also be solved more easily by performing lower_bound on prefix sum array)
int kthZeroPos(int v, int tl, int tr, int k){
	if(k > seg[v]){
		return -1;
	}
	if(tl == tr){
		return tl;
	}
	else{
		int mid = (tl+tr)/2;
		if(seg[2*v] >= k){
			return kthZeroPos(2*v,tl,mid,k);
		}
		else{
			k -= seg[2*v];
			return kthZeroPos(2*v+1,mid+1,tr,k);
		}
	}
}


void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		seg[v] = (val == 0 ? 1 : 0);
	}
	else{
		int mid = (tl+tr)/2;
		if(pos <= mid)
			update(2*v,tl,mid,pos,val);
		else
			update(2*v+1,mid+1,tr,pos,val);
		seg[v] = seg[2*v]+seg[2*v+1];
	}
}

int32_t main(){
	int a[] = {1,2,3,0,0,2,0,1,0,5,0,6,3,2,0};
	int n = sizeof(a)/sizeof(int);
	
	build(a,1,0,n-1);
	
	// No of Zeroes in a range
	cout << getCount(1,0,5,0,n-1) << "  ";
	
	// Position of kth zero
	cout << kthZeroPos(1,0,n-1,2) << endl;

	update(1,0,n-1,2,0);
	
	cout << getCount(1,0,5,0,n-1) << "  ";	
	cout << kthZeroPos(1,0,n-1,2);


	return 0;
}
