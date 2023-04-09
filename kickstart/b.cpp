#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e5 + 10;
int val[N], par[N], vis[N];

int rec(int cur) {
	if (vis[cur] || cur == 0) return 0;
	vis[cur] = 1;
	return max(val[cur], rec(par[cur]));
}

void solve(){
  int n;
  cin >> n;

  set<int> leaf;

  for (int i = 1; i <= n; i++)  vis[i] = 0;
  for (int i = 1; i <= n; i++) leaf.insert(i);

  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> par[i];
    if (leaf.find(par[i]) != leaf.end()) {
      leaf.erase(par[i]);
    }
  }

	int ans = 0;

	vector<int> v(leaf.begin(), leaf.end());
	sort(v.begin(), v.end());

	do {
		memset(vis, 0, sizeof vis);

		int cur = 0;
		for (auto x : v) {
			cur += rec(x);
		}
		ans = max(ans, cur);
	} while (next_permutation(v.begin(), v.end()));


  cout << ans << endl;

}

int32_t main(){
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    #ifndef HELLO
      cout << "Case #" << tt << ": ";
    #endif 
    solve();
  }
  
  return 0;
}