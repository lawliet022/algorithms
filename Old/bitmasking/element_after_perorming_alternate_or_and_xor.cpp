// Problem - https://practice.geeksforgeeks.org/problems/element-left-after-performing-alternate-or-xor-operation/0


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


const int MAX = 1e5 + 5;
int seg[4*MAX];

void build(int a[], int v, int tl, int tr, int op){
	if(tl == tr){
		seg[v] = a[tl];
		return;
	}
	int mid = (tl+tr)/2;
	build(a,2*v,tl,mid,op^1);
	build(a,2*v+1,mid+1,tr,op^1);
	if(op == 1){
		seg[v] = seg[2*v] ^ seg[2*v+1];
	}
	else
		seg[v] = seg[2*v] | seg[2*v+1];
}

void update(int v, int tl, int tr, int pos, int val, int op){
	if(tl > tr)
		return;
	if(tl == tr){
		seg[v] = val;
		return;
	}
	int mid = (tl+tr)/2;
	if(pos <= mid){
		update(2*v,tl,mid,pos,val,op^1);
	}
	else
		update(2*v+1,mid+1,tr,pos,val,op^1);
	
	if(op == 1){
		seg[v] = seg[2*v] ^ seg[2*v+1];
	}
	else
		seg[v] = seg[2*v] | seg[2*v+1];
	
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		memset(seg,0,sizeof seg);
		int w = -1;
		for(int i = 0; i < 30; i++){
			if(n == (1<<i)){
				w = i;
				break;
			}
		}
		
		build(a,1,0,n-1,w%2==0);
		//cout << seg[1] << endl;
		int q;
		cin >> q;
		while(q--){
			int pos, val;
			cin >> pos >> val;
			if(pos >= n){
				cout << -1 << endl;
				continue;
			}
			update(1,0,n-1,pos,val,w%2==0);
			cout << seg[1] << endl;
		}
	}

	return 0;
}

