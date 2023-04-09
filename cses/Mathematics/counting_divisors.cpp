#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e6 + 100;
int cnt[N];

void pre(){
	for(int i = 1; i < N; i++){
		for(int j = i; j < N; j += i){
			cnt[j]++;
		}
	}
}


int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	pre();
	while(t--){
		int x;
		cin >> x;
		cout << cnt[x] << endl;
	}
	
	return 0;
}
