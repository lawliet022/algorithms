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

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = a[tl];
	}
	else{
		int mid = (tl+tr)/2;
		build(a,2*v,tl,mid);
		build(a,2*v+1,mid+1,tr);
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}

int getSum(int v, int tl, int tr, int l, int r){
	if(l > r)
		return 0;
	if(tl == l && tr == r)
		return seg[v];
	int mid = (tl+tr)/2;
	
	return getSum(2*v,tl,mid,l,min(r,mid)) + 
			getSum(2*v+1,mid+1,tr,max(l,mid+1),r);
}

void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		seg[v] = val;
	}
	else{
		int mid = (tl+tr)/2;
		if(pos <= mid)
			update(2*v,tl,mid,pos,val);
		else
			update(2*v+1,mid+1,tr,pos,val);
			
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}



int32_t main(){
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int n = sizeof(a)/ sizeof(int);
	
	build(a,1,0,n-1);
	
	cout << getSum(1,0,n-1,1,5) << endl;
	
	update(1,0,n-1,2,4);
	
	cout << getSum(1,0,n-1,1,5) << endl;
	
	

	return 0;
}
