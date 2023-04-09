#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]" << " ";
	err(++it, args...);
}

bool hasPath(int a[][4], int n, int m, int x, int y){
	if(x == n-1 && y == m-1){
		if(a[x][y])
			return true;
		else
			return false;
	}
	
	// rec case
	if(x+1 < n && a[x+1][y] == 1){
		bool b = hasPath(a,n,m,x+1,y);
		if(b)
			return true;
	}
	if(y+1 < n && a[x][y+1] == 1){
		bool b = hasPath(a,n,m,x,y+1);
		if(b)
			return true;
	}
	return false;
}


int countPaths(int a[][4], int n, int m, int x, int y){
	if(x == n-1 && y == m-1){
		if(a[x][y])
			return 1;
		else
			return 0;
	}
	int ways = 0;
	if(x+1 < n && a[x+1][y] == 1){
		ways += countPaths(a,n,m,x+1,y);
	}
	if(y+1 < m && a[x][y+1] == 1){
		ways += countPaths(a,n,m,x,y+1);
	}
	return ways;
}

void printAll(int a[][4], int n, int m, int x, int y, vector<char>& path){
	if(x == n-1 && y == m-1){
		if(a[x][y]){
			for(auto x : path)
				cout << x << " -> " ;
			cout << endl;
		}
	}
	if(x+1 < n && a[x+1][y] == 1){
		path.PB('D');
		printAll(a,n,m,x+1,y,path);
		path.pop_back();
	}
	if(y+1 < m && a[x][y+1] == 1){
		path.PB('R');
		printAll(a,n,m,x,y+1,path);
		path.pop_back();
	}
}



int32_t main(){
	int a[][4] =   {1,1,1,1,
					1,1,0,1,
					0,1,0,0,
					0,1,1,1,
					0,0,1,1};
	int n = 5, m = 4;
	
	// Is there a Path
	if(hasPath(a,n,m,0,0)){
		cout << "Found Path\n";
	}
	else{
		cout << "No Path\n";
	}
	
	// count all Paths
	cout << "Number of Paths = " << countPaths(a,n,m,0,0) << endl;
	
	// Print all Paths
	vector<char> path;
	printAll(a,n,m,0,0,path);

	return 0;
}

// abcd
