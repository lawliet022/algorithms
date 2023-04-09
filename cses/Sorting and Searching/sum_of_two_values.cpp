#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

void __print(int x) {cerr << x;}
void __print(int32_t x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef HELLO
#define error(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define error(x...)
#endif


int32_t main(){
	int n, k;
	cin >> n >> k;
	pair<int,int> a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a,a+n);
	for(int i = 0; i < n-1; i++){
		int req = k - a[i].first;
		int ans = -1, l = i+1, r = n-1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(a[mid].first <= req){
				ans = mid;
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}
		if(ans != -1 && a[ans].first == req){
			cout << a[i].second+1 << " " << a[ans].second+1 << endl;
			exit(0);
		}
	}
	cout << "IMPOSSIBLE";
	
	return 0;
}
