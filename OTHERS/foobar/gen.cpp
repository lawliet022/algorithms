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

int rand(int a, int b){
	return rand() % (b-a+1) + a;
}

int32_t main(int argc, char *argv[]){
	srand(atoi(argv[1]));
	int n = rand(3,10);
	int p = rand(1,n-2);
	
	int a[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = rand() % 10;
		}
	}
	set<int> s;
	while((int)s.size() < p){
		int row = rand() % n;
		if(row == 0)
			continue;
		if(s.find(row) != s.end())
			continue;
		s.insert(row);
		for(int i = 0; i < n; i++)
			a[row][i] = 0;
	}
	
	cout << n << endl;
	for(int i = 0; i < n; i++){
		//cout << "[";
		for(int j = 0; j < n; j++){
			cout << a[i][j] << endl;
		}
		//cout << "],\n";
	}
	
	return 0;
}

