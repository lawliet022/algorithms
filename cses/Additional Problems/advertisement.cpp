#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 2e5 + 100;
pair<int,int> seg[4*N];


pair<int,int> combine(pair<int,int> a, pair<int,int> b){
	if(a.first < b.first)
		return a;
	return b;
}

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = {a[tl],tl};
		return;
	}
	int mid = (tl + tr) / 2;
	build(a,2*v,tl,mid);
	build(a,2*v+1,mid+1,tr);
	seg[v] = combine(seg[2*v],seg[2*v+1]);
}

pair<int,int> query(int v, int tl, int tr, int l, int r){
	if(l > r)
		return make_pair((int)1e12,-1LL);
	if(tl == l && tr == r)
		return seg[v];
	int mid = (tl + tr) / 2;
	return combine(query(2*v,tl,mid,l,min(r,mid)),query(2*v+1,mid+1,tr,max(l,mid+1),r));
}

int ans = 0;
int n;

void solve(int l, int r){
	if(l > r)
		return;
	auto p = query(1,0,n-1,l,r);
	ans = max(ans,p.first * (r - l + 1));
	solve(l,p.second-1);
	solve(p.second+1,r);
}



int32_t main(){
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	//build(a,1,0,n-1);
	//solve(0,n-1);
	//cout << ans << endl;
	
	
	// Using stack in O(n)
	int pref[n+1], suff[n+1];
	pref[0] = -1;
	suff[n-1] = n;
	stack<int> s;
	s.push(0);
	for(int i = 1; i < n; i++){
		while(!s.empty() && a[s.top()] >= a[i])
			s.pop();
		if(!s.empty()){
			pref[i] = s.top();
		}
		else{
			pref[i] = -1;
		}
		s.push(i);
	}
	s = {};
	s.push(n-1);
	for(int i = n-2; i >= 0; i--){
		while(!s.empty() && a[s.top()] >= a[i])
			s.pop();
		if(!s.empty()){
			suff[i] = s.top();
		}
		else{
			suff[i] = n;
		}
		s.push(i);
	}
	
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans,(suff[i]-pref[i]-1)*a[i]);
	}
	cout << ans << endl;
	
	
	return 0;
}
