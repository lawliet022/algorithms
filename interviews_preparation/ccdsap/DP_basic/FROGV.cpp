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

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q, x;
	cin >> n >> x >> q;
	vector<pii> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(a.begin(),a.end());
	int idx[n];
	for(int i = 0; i < n; i++)
		idx[a[i].S] = i;
	
	int pref[n+1] = {0};
	for(int i = 1; i < n; i++){
		if(a[i].F-a[i-1].F > x){
			pref[i] = 1 + pref[i-1];
		} 
		else
			pref[i] = pref[i-1];
	}
	
	while(q--){
		int p, q;
		cin >> p >> q;
		p--, q--;
		p = idx[p];
		q = idx[q];
		if(p > q)
			swap(p,q);
		
		if(pref[q] == pref[p]){
			cout << "Yes\n";
		}
		else
			cout << "No\n";
	}

	return 0;
}

