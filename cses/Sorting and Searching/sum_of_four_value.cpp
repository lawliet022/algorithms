#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n, total;
	cin >> n >> total;
	pair<int,int> a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i+1;
	}
	sort(a,a+n);
	
	for(int i = 0; i < n-3; i++){
		if(a[n-3].first + a[n-2].first + a[n-1].first < total - a[i].first)
			continue;
		if(a[i+1].first + a[i+2].first + a[i+3].first > total - a[i].first)
			continue;
		for(int j = i+1; j < n-2; j++){
			int req = total - a[i].first - a[j].first;
			if(a[n-2].first + a[n-1].first < req)
				continue;
			if(a[j+1].first + a[j+2].first > req)
				continue;
			int l = j+1, r = n-1;
			while(l < r){
				if(a[l].first + a[r].first == req){
					cout << a[i].second << " " << a[j].second << " " << a[l].second << " " << a[r].second << endl;
					return 0;
				}
				if(a[l].first + a[r].first > req){
					r--;
				}
				else{
					l++;
				}
			}
		}
	}
	cout << "IMPOSSIBLE";
	
	
	return 0;
}
