#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int > vi;
typedef pair<int, int> pi;
typedef vector<pi> vp;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD 1000000007
#define EPS 1e-9


vi a[10];
int toLeaf[10];
int maxLength[10];

void dfs(int s, int p){
	toLeaf[s] = 0;
	for(auto x : a[s]){
		if(x == p)
			continue;
		dfs(x, s);
		if(a[x].size() == 1)
			toLeaf[s] = max(toLeaf[s], toLeaf[x] + 1);
		else
			toLeaf[s] = max(toLeaf[s], toLeaf[x]) + 1;
	}
}


int main(){
	
	a[1].PB(2);
	a[1].PB(3);
	a[1].PB(4);
	a[2].PB(1);
	a[3].PB(1);
	a[4].PB(1);
	a[2].PB(5);
	a[2].PB(6);
	a[5].PB(2);
	a[6].PB(2);
	a[4].PB(7);
	a[7].PB(4);

	for(int i = 1; i <= 7; i++){
		memset(toLeaf, 0, sizeof toLeaf);
		dfs(i, 0);

		if(a[i].size() == 1){
			maxLength[i] = toLeaf[a[i][0]] + 1;
		}
		else if(a[i].size() >= 2){
			int s1 = 0, s2 = 0;
			for(auto x : a[i]){
				if(toLeaf[x] > min(s1, s2)){
					if(s1 < s2){
						s1 = toLeaf[x];
					}
					else{
						s2 = toLeaf[x];
					}
				}
			}
			maxLength[i] = s1 + s2 + 2;
		}
		cout << "for leaf " << i << "\t";
		for(int i = 1; i <= 7; i++){
			cout << toLeaf[i] << " ";
		}
		cout << "\n";
	}

	for(int i = 1; i <= 7; i++){
		cout << maxLength[i] << " ";
	}
	

	return 0;
}