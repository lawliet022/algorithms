#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n;
	cin >> n;
	int a[n+1];
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	stack<int> s;
	for(int i = 1; i <= n; i++){
		while(!s.empty() && a[s.top()] >= a[i]){
			s.pop();
		}
		if(s.empty()){
			cout << 0 << " ";
		}
		else{
			cout << s.top() << " ";
		}
		s.push(i);
	}
	
	return 0;
}
