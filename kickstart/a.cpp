#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e5 + 10;
int val[N], par[N], vis[N];

int getBetter(int cur, int thresh) {
  if (vis[cur] || cur == 0) return -1;
  vis[cur] = 1;
  if (val[cur] > thresh) {
    return cur;
  }
  return getBetter(par[cur], thresh);
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

  set<pair<int,int>> s;

  for (auto x : leaf) {
    s.insert({val[x], x});
  }

  int ans = 0;
  while (s.size()) {
    auto p = *s.begin();
    s.erase(s.begin());
    int cur = p.second;
    int xx = getBetter(par[cur], val[cur]);
    if (xx == -1) {
      ans += p.first;
    } else {
      s.insert({val[xx], xx});
    }
  }

  cout << ans << endl;

}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
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