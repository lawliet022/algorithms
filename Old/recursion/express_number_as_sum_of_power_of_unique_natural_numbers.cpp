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



int solve(int n, int k, int last, int sumi){
	if(sumi > n){
		return 0;
	}
	if(sumi == n)
		return 1;
	int cnt = 0;
	for(int i = last+1; i <= 1000; i++){
		if(sumi + pow(i,k) <= n){
			cnt += solve(n,k,i,sumi+pow(i,k));
		}
		else
			break;
	}
	return cnt;
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << solve(n,k,0,0) << endl;
	}

	return 0;
}

