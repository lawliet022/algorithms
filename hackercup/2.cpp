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


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]" << " ";
	err(++it, args...);
}

const int MAX = 1e6 + 10;
int p[MAX];
void pre(){
	p[0] = 1;
	for(int i = 1; i < MAX; i++)
		p[i] = (p[i-1]*2)%MOD;
		
}

int32_t main(){
	
	int t;
	cin >> t;
	pre();
	for(int test = 1; test <= t; test++){
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int a = 0, b = 0, ans = 0;
		for(int i = n-1; i >= 0; i--){
			if(s[i] == 'A'){
				a++;
			}
			else if(s[i] == 'B'){
				b++;
				if(b - a > k){
					ans = (ans + p[i+1])%MOD;
					b--;
					a++;
				}
			}
			if(a >= b){
				a = 0;
				b = 0;
			}
		}
		if(ans < 0)
			ans += MOD;
		cout << "Case #" << test << ": " << ans << endl;
	}

	return 0;
}

