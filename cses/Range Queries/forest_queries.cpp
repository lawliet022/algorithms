#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n, q;
	cin >> n >> q;
	int a[n+1][n+1];
	memset(a,0,sizeof a);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char c;
			cin >> c;
			if(c == '*'){
				a[i][j] = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	}
	
	while(q--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1] << endl;
	}
	
	
	return 0;
}
