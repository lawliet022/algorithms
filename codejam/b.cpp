#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;


const int MAX = 200;
int parent[MAX], cnt[MAX];

void make(int n){
	parent[n] = n;
	cnt[n] = 1;
}

int find(int n){
	if(n == parent[n])
		return n;
	return parent[n] = find(parent[n]);			// Path Compression
}

void unionset(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b){
		if(cnt[a] < cnt[b])
			swap(a,b);
		parent[b] = a;
			cnt[a] += cnt[b];
	}
}



int32_t main(){
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		cout << "Case #" << test << ": ";
		
		int n;
		cin >> n;
		int x[n], y[n];
		for(int i = 0; i < n; i++){
			cin >> x[i] >> y[i];
		}
		int ans = 1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j)
					continue;
				for(int k = 0; k < n; k++)
					make(i);
				int sy = abs(y[j] - y[i]);
				int sx = abs(x[j] - x[i]);
				if(sx != 0){
					int cn = __gcd(sx,sy);
					sy /= cn;
					sx /= cn;
				}
				for(int k = 0; k < n; k++){
					if(vis[k] == 0){
						for(int l = 0; l < n; l++){
							if(!vis[l] && k != l){
								int ty = abs(y[l]-y[k]);
								int tx = abs(x[l]-x[k]);
								if(sx == 0 && sx == tx){
									unionset(k,l);
								}
								else if(tx == 0){
									continue;
								}
								else{
									int cm = __gcd(tx,ty);
									tx /= cm;
									ty /= cm;
									if(tx == sx && ty == sy){
										unionset(k,l);
									}
								}
							}
						}
					}
				}
				vector<int> v;
				for(int i = 0; i < n; i++){
					if(findparent(i) == i)
						v.push_back(cnt[i]);
				}
				int cur = 0;
				do{
					
				}
				while(next_permutation(v.begin(),v.end()));
				
			}
		}
		
	}

	return 0;
}

