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



map<pair<int,int>,int> dp;
string s;

const int INF = 1e6;

int v[55][26];
int val[55][55];
void pre(){
	memset(v,0,sizeof v);
	for(int i = 0; i < (int)s.size(); i++){
		for(int j = 0; j < 26; j++)
			v[i+1][j] = v[i][j];
		v[i+1][s[i]-'a']++;
	}
}

int getVal(int x, int y){
	int hf = 0, lf = 100, hp = 100, lp = 100;
	for(int i = 0; i < 26; i++){
		int p = v[y+1][i] - v[x][i];
		if(p > 0){
			if(p == hf){
				hp = min(hp,i);
			}
			if(p == lf){
				lp = min(lp,i);
			}
			
			if(p > hf){
				hf = p;
				hp = i;
			}
			if(p < lf){
				lf = p;
				lp = i;
			}
			
		}
	}
	return (hp - lp);
}

void pre2(){
	int n = s.size();
	memset(val,0,sizeof val);
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			val[i][j] = getVal(i,j);
		}
	}
}


int solve(int pos, int k){
	if(pos == -1){
		return 0;
	}
	if(k <= 0){
		return INF;
	}
	if(dp.count({pos,k})){
		return dp[{pos,k}];
	}
	int &ans = dp[{pos,k}] = 0;
	ans = 1e12;
	for(int i = pos; i >= 0; i--){
		ans = min(ans,val[i][pos] + solve(i-1,k-1));
	}
	return ans;
}


int rand(int a, int b){
	return a + rand() % (b - a + 1);
}


void work(){
	int n, k;
	cin >> n >> k;
	cin >> s;
	pre();
	pre2();
	dp.clear();
	
	cout << solve(n-1,k) << endl;
}

int32_t main(){	
	int t;
	cin >> t;
	while(t--){
		work();
	}
	
	return 0;
}
