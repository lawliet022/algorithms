#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);
 
class line{
public:
	int x1, y1, x2, y2;
	line(){}
	line(int a, int b, int c, int d){
		x1 = a;	y1 = b;
		x2 = c;	y2 = d;
	}
};
 
map<int,int> m;
 
const int MAX = 6e5;
int bit[MAX];
int N = 5e5 + 100;
 
void add(int index, int val){
	for(int i = index; i < N; i = i|(i+1))
		bit[i] += val;
}
 
int getSum(int x){
	int ans = 0;
	for(int i = x; i >= 0; i = (i&(i+1))-1){
		ans += bit[i];
	}
	return ans;
}


bool isVertical(line a){
	return a.x1 == a.x2;
}

vector<int> p[MAX], q[MAX], r[MAX], s[MAX];

int32_t main(){
	int n;
	cin >> n;
	
	line a[n];
	
	for(int i = 0; i < n; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a[i] = line(x1,y1,x2,y2);
		m[x1] = m[y1] = m[x2] = m[y2] = 1;
	}
	
	// Compression
	int cnt = 1;
	for(auto &x : m){
		x.second = cnt++;
	}
	
	for(int i = 0; i < n; i++){
		a[i].x1 = m[a[i].x1];
		a[i].y1 = m[a[i].y1];
		a[i].x2 = m[a[i].x2];
		a[i].y2 = m[a[i].y2];
	}
	
	for(int i = 0; i < n; i++){
		if(isVertical(a[i])){
			r[a[i].x1].push_back(a[i].y1);
			s[a[i].x1].push_back(a[i].y2);
		}
		else{
			p[a[i].x1].push_back(a[i].y1);
			q[a[i].x2].push_back(a[i].y1);
		}
	}
	int ans = 0;
	
	for(int i = 1; i <= 5e5; i++){
		if(p[i].size()){				// add y1 for starting of intervals at x1 = i
			for(auto x : p[i]){
				add(x,1);
			}
		}
		for(int j = 0; j < (int)r[i].size(); j++){			// for each vertical line at x1 = x2 = i, get intersections
			ans += getSum(s[i][j]) - getSum(r[i][j]-1);
		}
		if(q[i].size()){			// remove y2 for starting of intervals at x2 = i
			for(auto x : q[i]){
				add(x,-1);
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
