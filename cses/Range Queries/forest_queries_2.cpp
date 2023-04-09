#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

const int N = 1005;
int bit[N][N];
int n;

void add(int x, int y, int val){
	for(int i = x; i < n; i = (i|(i+1))){
		for(int j = y; j < n; j = (j|(j+1))){
			bit[i][j] += val;
		}
	}
}
int getSum(int x, int y){
	int ans = 0;
	for(int i = x; i >= 0; i = (i&(i+1))-1){
		for(int j = y; j >= 0; j = (j&(j+1))-1){
			ans += bit[i][j];
		}
	}
	return ans;
}

char c[N][N];


int32_t main(){
	int q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> c[i][j];
			if(c[i][j] == '*')
				add(i,j,1);
		}
	}
	
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int x, y;
			cin >> x >> y;
			x--;	y--;
			if(c[x][y] == '*'){
				c[x][y] = '.';
				add(x,y,-1);
			}
			else{
				c[x][y] = '*';
				add(x,y,1);
			}
		}
		else{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1--;	x2--;	y1--;	y2--;
			cout << getSum(x2,y2) - (x1 ? getSum(x1-1,y2) : 0LL) - (y1 ? getSum(x2,y1-1) : 0LL) + (x1 && y1 ? getSum(x1-1,y1-1) : 0LL) << endl;
		}
	}
	
	
	
	return 0;
}
