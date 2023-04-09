#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 2e5 + 100;
int a[N];
const int sz = sqrt(2e5) + 1;

struct query{
	int idx;
	pair<int,int> p;
};

bool comp(query &pp, query &qq){
	auto a = pp.p;
	auto b = qq.p;
	if(a.first / sz != b.first / sz)
		return a.first < b.first;
	return (a.first / sz & 1 ? a.second < b.second : a.second > b.second);
}


int m[1000005];
int current = 0;

void add(int i){
	if(m[a[i]] == 0)
		current++;
	m[a[i]]++;
}

void remove(int i){
	m[a[i]]--;
	if(m[a[i]] == 0){
		current--;
	}
}





int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	map<int,int> ma;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		ma[a[i]] = 1;
	}
	int cur = 1;
	for(auto &x : ma){
		x.second = cur++;
	}
	
	for(int i = 0; i < n; i++){
		a[i] = ma[a[i]];
	}
	
	query Q[q];
	for(int i = 0; i < q; i++){
		int x, y;
		cin >> x >> y;
		x--;	y--;
		Q[i] = {i,{x,y}};
	}
	sort(Q,Q+q,comp);
	
	int l = 0, r = -1;
	
	int ans[q+1];
	
	int op = 0;
	
	for(int i = 0; i < q; i++){
		auto v = Q[i].p;
		while(l > v.first){
			l--;
			add(l);
			op++;
		}
		while(r < v.second){
			r++;
			add(r);
			op++;
		}
		while(l < v.first){
			remove(l);
			l++;
			op++;
		}
		while(r > v.second){
			remove(r);
			r--;
			op++;
		}
		ans[Q[i].idx] = current;
	}
	
	for(int i = 0; i < q; i++){
		cout << ans[i] << endl;
	}
		
	cerr << "Time = " << 1.0*clock()/CLOCKS_PER_SEC << endl ; 
	
	
	return 0;
}
