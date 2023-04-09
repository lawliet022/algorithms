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
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int cur_max = a[0];
	int cost = 0;
	for(int i = 1; i < n; i++){
		if(a[i] > cur_max){
			cur_max = a[i];
		}
		else{
			cost += cur_max - a[i];
		}
	}
	cout << cost << endl;
	
	return 0;
}
