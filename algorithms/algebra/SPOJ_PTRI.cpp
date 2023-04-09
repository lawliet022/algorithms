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

const int MAX = 1e8 + 5;

int prime[(MAX >> 5) + 10];
#define get(x) (prime[(x >> 5)] >> (x&31)&1)
#define set(x) (prime[x >> 5]  |= (1 << (x&31)))

vector<pair<int,pair<int,int>>> p;

void bitsieve(){
	set(1);
	int line = 1;
	int count = 0;
	for(int i = 2; i <= MAX; i++){
		if(!get(i)){
			count++;
			p.PB({i,{line,count}});
			if(line == count){
				line++;
				count = 0;
			}
			for(int j = i*i; j <= MAX; j += i)
				set(j);
		}
	}
}


//int bsearch(int x){
	//int l = 0, r = 1e8;
	//while(l < r){
		//int mid = (l+r+1)/2;
		//if(mid*(mid+1)/2 < x)
			//l = mid;
		//else
			//r = mid-1;
	//}
	//return l+1;
//}


bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
	if(a.F < b.F)
		return 1;
	else
		return 0;
}


int32_t main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	
	cerr << "Time = " << 1.0*clock()/CLOCKS_PER_SEC << endl ; 
	bitsieve();
	cerr << "Time = " << 1.0*clock()/CLOCKS_PER_SEC << endl ; 
	int t;
	cin >> t;
	//while(t--){
		//int x;
		//cin >> x;
		//if(get(x)){
			//cout << -1 << endl;
		//}
		//else{
			//auto z = lower_bound(p.begin(),p.end(),MP(x,MP(-1,-1)),cmp);
			//cout << p[(z-p.begin())].S.F << " " << p[(z-p.begin())].S.S  << endl;
		//}
	//}


	return 0;
}
