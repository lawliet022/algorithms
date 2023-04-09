#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;



// Complexity - O((N + Q) * sqrt(N))

vector<int> v = {1,2,3,4,5,6,1,1,1,2,
				2,2,2,2,3,3,3,4,5,3,
				1,3,3,2,1,1,1,1,1,3};
int len;

map<int,int> m;
set<pair<int,int>> s;


struct query{
	int l, r, ind;
	//bool operator<(query x){
		//return (MP(l/len,r)< MP(x.l/len,x.r));
	//};
};
vector<query> q = {{1,5,0},{2,10,1},{10,15,2},{10,25,3},{5,15,4},{27,28,5},{0,29,6}};


void add(int i){
	if(m[v[i]]){
		s.erase({m[v[i]],v[i]});
		m[v[i]]++;
		s.insert({m[v[i]],v[i]});
	}
	else{
		m[v[i]] = 1;
		s.insert({m[v[i]],v[i]});
	}
}
void remove(int i){
	if(m[v[i]]){
		s.erase({m[v[i]],v[i]});
		m[v[i]]--;
		if(m[v[i]] >= 1)
			s.insert({m[v[i]],v[i]});
	}
	else{
		// cout << "skipped " << i << "\n";
	}	
}

bool comp(query a, query b){
	if(a.l/len != b.l/len){
		return (MP(a.l,a.r) < MP(b.l,b.r));
	}
	else{
		return ((a.l/len & 1) ? (a.r < b.r) : (a.r > b.r));
	}
}

pair<int,int> getans(){
	if(s.size())
		return *(--s.end());
	else
		return {-1,-1};
}

int32_t main(){
	
	int n = v.size();
	len = ceil(sqrt(n*1.0));

	// sort(q.begin(),q.end());				// Also can be used
	sort(q.begin(),q.end(),comp);			// Better as less right point movement

	int cl = 0;
	int cr = -1;
	int ans[q.size()+1];
	for(auto x : q){
		while(cl > x.l){
			cl--;
			add(cl);
		}
		while(cr < x.r){
			cr++;
			add(cr);
		}
		while(cl < x.l){
			remove(cl);
			cl++;
		}
		
		while(cr > x.r){
			remove(cr);
			cr--;
		}
		ans[x.ind] = getans().S;
	}
	for(int i = 0; i < (int)q.size(); i++){
		cout << ans[i] << " "; 
	}


	return 0;
}
