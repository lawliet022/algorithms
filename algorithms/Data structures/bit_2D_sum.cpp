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

const int MAX = 1e3;
int bit[MAX][MAX];
int n, m;


// Single Update and Range Query on 2D Matrix


void add(int x, int y, int val){
	for(int i = x; i < n; i = i|(i+1))
		for(int j = y; j < m; j = j|(j+1))
			bit[i][j] += val;
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


int sum(int x1, int y1, int x2, int y2){
	int a = getSum(x2,y2);
	int b = x1 > 0 ? getSum(x1-1,y2) : 0;
	int c = y1 > 0 ? getSum(x2, y1-1) : 0;
	int d = (x1 > 0 && y1 > 0) ? getSum(x1-1,y1-1) : 0;
	
	return a-b-c+d;
}


int32_t main(){
	int a[3][4] = {1,2,3,4,
					5,6,7,8,
					9,10,11,12
					};
					
	n = 3; m = 4;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			add(i,j,a[i][j]);
			
	int x1 = 0, y1 = 0, x2 = 1, y2 = 2;
	cout << sum(x1,y1,x2,y2);


	return 0;
}
