#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

const int MAX = 1e5 + 10;
int seg[4*MAX];

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = a[tl];
	}
	else{
		int mid = (tl+tr)/2;
		build(a,2*v,tl,mid);
		build(a,2*v+1,mid+1,tr);
		seg[v] = max(seg[2*v], seg[2*v+1]);
	}
}

int getMax(int v, int tl, int tr, int l, int r){
	if(l > r)
		return 0;
	if(tl == l && tr == r)
		return seg[v];
	int mid = (tl+tr)/2;
	
	return max(getMax(2*v,tl,mid,l,min(r,mid)), 
			getMax(2*v+1,mid+1,tr,max(l,mid+1),r));
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
			
		seg[v] = max(seg[2*v], seg[2*v+1]);
	}
}

int32_t main(){
	int n;
	cin >> n;
	int pos[n];
	for(int i = 0; i < n; i++)
		cin >> pos[i];
	int h[n];
	for(int i = 0; i < n; i++)
		cin >> h[i];
		
	int ans[n] = {0};
	
	ans[n-1] = pos[n-1] + h[n-1];
	update(1,0,n-1,n-1,ans[n-1]);
	
	for(int i = n-2; i >= 0; i--){
		int last = pos[i] + h[i];
		int q = lower_bound(pos,pos+n,last) - pos;
		if(q == n){
			q--;
		}
		if(pos[q] > last)
			q--;
		int res = getMax(1,0,n-1,i,q);
		ans[i] = max(res,last);
		
		update(1,0,n-1,i,ans[i]);
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << '\n';
	

	return 0;
}

