#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a,a+n);
	int sumi = 0;
	for(int i = 0; i < n-1; i++)
		sumi += a[i];
	
	cout << max(2*a[n-1],a[n-1]+sumi) << endl;
	
	return 0;
}
