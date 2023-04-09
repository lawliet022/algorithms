#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

struct customer{
	int l, r, idx;
};

bool comp(customer a, customer b){
	if(a.l != b.l)
		return a.l < b.l;
	return a.r < b.r;
}




int32_t main(){
	int n;
	cin >> n;
	vector<customer> v;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		v.push_back({x,y,i+1});
	}
	sort(v.begin(),v.end(),comp);
	int ans[n+1];
	
	deque<int> isFree;
	for(int i = 1; i <= n; i++)
		isFree.push_back(i);
	
	set<pair<int,int>> s;		// {time when free, room no}
	
	for(auto x : v){
		while(s.size() && (*s.begin()).first < x.l){
			isFree.push_front((*s.begin()).second);
			s.erase(s.begin());
		}
		ans[x.idx] = isFree.front();
		s.insert({x.r,isFree.front()});
		isFree.pop_front();
	}
	
	int maxi = 0;
	for(int i = 1; i <= n; i++)
		maxi = max(maxi,ans[i]);
	
	cout << maxi << endl;
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	
	
	
	return 0;
}
