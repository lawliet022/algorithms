#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e6 + 10;
vector<int> v[N];
int vis[N];

void pre(){
	for(int i = 2; i < N; i++){
		for(int j = i; j < N; j += i){
			if(vis[j]){
				v[j].push_back(i);
			}
		}
	}
}

int found[N];

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		vis[a[i]] = 1;
	}
	pre();
	sort(a,a+n);
	int ans = 1;
	for(int i = 0; i < n; i++){
		for(auto x : v[a[i]]){
			if(found[x]){
				ans = max(ans,x);
			}
			found[x] = 1;
		}
	}
	
	cout << ans << endl;
	
	cerr << "Time = " << 1.0*clock()/CLOCKS_PER_SEC << endl ; 
	
	
	
	return 0;
}
