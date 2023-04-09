#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1e6 + 100;
int m[N];

int32_t main(){
	int n;
	cin >> n;
	if(n*(n+1) % 4){
		cout << "NO";
		return 0;
	}
	int req_sum = n * (n+1) / 4;			// sum of individual sets
	
	int cur = n, cur_sum = n;				
	m[cur] = 1;
	cur--;
	while(cur_sum + cur <= req_sum){		// greedily form sum for one of the set
		m[cur] = 1;
		cur_sum += cur;
		cur--;
	}
	if(cur_sum != req_sum){
		m[req_sum-cur_sum] = 1;
	}
	int sz = 0;
	for(int i = 1; i <= n; i++){
		if(m[i]){
			sz++;
		}
	}
	cout << "YES\n";
	cout << sz << endl;
	for(int i = 1; i <= n; i++){
		if(m[i])
			cout << i << " ";
	}
	cout << endl;
	cout << n - sz << endl;
	for(int i = 1; i <= n; i++){
		if(m[i] == 0)
			cout << i << " " ;
	}
	cout << endl;
	
	return 0;
}
