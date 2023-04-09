#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


const int N = 1e6 + 10;
int seg[4*N];

int getMin(int v, int tl, int tr, int l, int r){
	if(l > r)
		return 1e16;
	if(tl == l && tr == r){
		return seg[v];
	}
	int mid = (tl + tr) / 2;
	return min(getMin(2*v,tl,mid,l,min(r,mid)) , getMin(2*v+1,mid+1,tr,max(l,mid+1),r));
}

void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		seg[v] = val;
		return;
	}
	int mid = (tl + tr) / 2;
	if(pos <= mid){
		update(2*v,tl,mid,pos,val);
	}
	else{
		update(2*v+1,mid+1,tr,pos,val);
	}
	seg[v] = min(seg[2*v],seg[2*v+1]);
}

int dp[N], cost[N];

void solve(){
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i <= 4*n + 2; i++){
		seg[i] = 1e18;
	}
	for(int i = 0; i < n; i++)
		dp[i] = 0;
		
	for(int i = 0; i < n; i++){
		cin >> cost[i];
		if(!cost[i]){
			cost[i] = 1e18;
		}
	}
	
	if(m >= n-1){
		cout << 0 << endl;
		return;
	}
	for(int i = 0; i <= m; i++){
		if(cost[i] < 1e10){
			update(1,0,n-1,i,cost[i]);
		}
	}
	bool ok = true;
	for(int i = m+1; i < n; i++){
		int p = getMin(1,0,n-1,i-m,i-1);
		dp[i] = p;
		if(p < 1e16){
			update(1,0,n-1,i,p+cost[i]);
		}
		else{
			ok = false;
			break;
		}
	}
	
	if(!ok){
		cout << -1 << endl;
		return;
	}
	cout << dp[n-1] << endl;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//freopen("in3.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int t;
	cin >> t;
	int test = 1;
	while(t--){
		cout << "Case #" << test++ << ": ";
		solve();
	}
	
	return 0;
}
