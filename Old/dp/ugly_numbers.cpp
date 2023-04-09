#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define vi vector<int>
#define int long long
using namespace std;


int32_t main(){
	vector<int> v;
	map<int,int> vis;
	priority_queue<int,vector<int>,greater<int>> q;
	q.push(2);
	q.push(3);
	q.push(5);
	while((int)v.size() <= 11000){
		int x = q.top();
		q.pop();
		v.PB(x);
		if(vis[2*x] == 0){
			q.push(2*x);
			vis[2*x] = 1;
		}
		if(vis[3*x] == 0){
			q.push(3*x);
			vis[3*x] = 1;
		}
		if(vis[5*x] == 0){
			q.push(5*x);
			vis[5*x] = 1;
		}
	}
	v.PB(1);
	sort(v.begin(),v.end());
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << v[n-1] << endl;
	}
	
	return 0;
}

