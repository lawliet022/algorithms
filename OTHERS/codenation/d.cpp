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

const int MAX = 10005;
pair<int,int> seg[4*MAX + 10];	// Max

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = {a[tl],tl};
	}
	else{
		int mid = (tl+tr)>>1;
		build(a,2*v,tl,mid);
		build(a,2*v+1,mid+1,tr);
		if(seg[2*v].F >= seg[2*v+1].F)
			seg[v] = seg[2*v];
		else
			seg[v] = seg[2*v+1];
	}
}

pair<int,int> getMax(int v, int tl, int tr, int l, int r){
	if(l > r)
		return {-1,-1};
	if(tl == l && tr == r)
		return seg[v];
	int mid = (tl+tr)/2;
	
	pair<int,int> p1 = getMax(2*v,tl,mid,l,min(r,mid)); 
	pair<int,int> p2 = getMax(2*v+1,mid+1,tr,max(l,mid+1),r);
	if(p1.F >= p2.F)
		return p1;
	else
		return p2;
}

void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		seg[v] = {val,tl};
	}
	else{
		int mid = (tl+tr)>>1;
		if(pos <= mid)
			update(2*v,tl,mid,pos,val);
		else
			update(2*v+1,mid+1,tr,pos,val);
		
		if(seg[2*v].F >= seg[2*v+1].F)
			seg[v] = seg[2*v];
		else
			seg[v] = seg[2*v+1];	
	}
}

//---------------Min Seg tree

pair<int,int> seg2[4*MAX + 10];	// Max

void build2(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg2[v] = {a[tl],tl};
	}
	else{
		int mid = (tl+tr)>>1;
		build2(a,2*v,tl,mid);
		build2(a,2*v+1,mid+1,tr);
		if(seg2[2*v].F <= seg[2*v+1].F)
			seg2[v] = seg2[2*v];
		else
			seg2[v] = seg2[2*v+1];
	}
}

pair<int,int> getMin(int v, int tl, int tr, int l, int r){
	if(l > r)
		return {1LL*1e15,1LL*1e15};
	if(tl == l && tr == r)
		return seg2[v];
	int mid = (tl+tr)/2;
	
	pair<int,int> p1 = getMin(2*v,tl,mid,l,min(r,mid)); 
	pair<int,int> p2 = getMin(2*v+1,mid+1,tr,max(l,mid+1),r);
	if(p1.F <= p2.F)
		return p1;
	else
		return p2;
}

void update2(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		seg2[v] = {val,tl};
	}
	else{
		int mid = (tl+tr)/2;
		if(pos <= mid)
			update2(2*v,tl,mid,pos,val);
		else
			update2(2*v+1,mid+1,tr,pos,val);
		
		if(seg2[2*v].F <= seg2[2*v+1].F)
			seg2[v] = seg2[2*v];
		else
			seg2[v] = seg2[2*v+1];	
	}
}




int32_t main(){
	int t;
	cin >> t;
	while(t--){
		memset(seg,0,sizeof seg);
		memset(seg2,0,sizeof seg2);
		
		int n, k;
		cin >> n >> k;
		vector<int> v[n+1];
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++){
			if(a[i] % k == 0){
				while(a[i] % k == 0){
					v[i].PB(a[i]);
					a[i] /= k;
				}
				v[i].PB(a[i]);
			}
			else{
				v[i].PB(a[i]*k);
				v[i].PB(a[i]);
			}
		}
		int x[n];
		for(int i = 0; i < n; i++){
			x[i] = v[i][0];
		}
		build(x,1,0,n-1);
		build2(x,1,0,n-1);
		
		int pos[n+1] = {0};
		for(int i = 0; i < n; i++){
			pos[i] = 0;
		}
		int ans = 1e18;
		while(1){
			pii mini = getMin(1,0,n-1,0,n-1);
			pii maxi = getMax(1,0,n-1,0,n-1);
			ans = min(ans,maxi.F-mini.F);
			if(pos[maxi.S] == (int)v[maxi.S].size()-1){
				break;
			}
			pos[maxi.S]++;
			update(1,0,n-1,maxi.S,v[maxi.S][pos[maxi.S]]);
			update2(1,0,n-1,maxi.S,v[maxi.S][pos[maxi.S]]);
		}
		cout << ans << endl;
	}

	return 0;
}

