#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

class query{
public:
	char t;
	int a, b;
	query(char tt ,int aa, int bb) : t(tt), a(aa), b(bb) {}
};

const int N = 1e6;
int cnt[N];
int seg[4*N];

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v] = a[tl];
		return;
	}
	int mid = (tl + tr) / 2;
	build(a,2*v,tl,mid);
	build(a,2*v+1,mid+1,tr);
	seg[v] = seg[2*v] + seg[2*v+1];
}

int getSum(int v, int tl, int tr, int l, int r){
	if(l > r)
		return 0;
	if(tl == l && tr == r){
		return seg[v];
	}
	int mid = (tl + tr) / 2;
	return getSum(2*v,tl,mid,l,min(r,mid)) + getSum(2*v+1,mid+1,tr,max(l,mid+1),r);
}

void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		seg[v] += val;
		return;
	}
	int mid = (tl + tr) / 2;
	if(pos <= mid)
		update(2*v,tl,mid,pos,val);
	else
		update(2*v+1,mid+1,tr,pos,val);
	seg[v] = seg[2*v] + seg[2*v+1];
}


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	vector<int> v;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		v.push_back(a[i]);
	}
	vector<query> Q;
	for(int i = 0; i < q; i++){
		char c;
		int x, y;
		cin >> c >> x >> y;
		Q.push_back(query(c,x,y));
		if(c == '!'){
			v.push_back(y);
		}
		else{
			v.push_back(x);
			v.push_back(y);
		}
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	
	unordered_map<int,int,custom_hash> m;
	for(int i = 0; i < (int)v.size(); i++){
		m[v[i]] = i+1;
	}
	
	for(int i = 0; i < n; i++){
		a[i] = m[a[i]];
		cnt[a[i]]++;
	}
	
	int sz = m.size() + 10;
	build(cnt,1,0,sz-1);
	
	for(int i = 0; i < q; i++){
		if(Q[i].t == '!'){
			int pos = Q[i].a;
			pos--;
			int val = m[Q[i].b];
			update(1,0,sz-1,a[pos],-1);
			a[pos] = val;
			update(1,0,sz-1,a[pos],1);
		}
		else{
			int x, y;
			x = Q[i].a;
			y = Q[i].b;
			x = m[x];
			y = m[y];
			cout << getSum(1,0,sz-1,x,y) << endl;
		}
	}
	
	
	
	return 0;
}
