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


int getSteps(int n){
	if(n == 1)
		return 1;
	return 2*getSteps(n-1) + 1;
}

void PrintSteps(int n, char source, char other, char dest){
	if(n == 1){
		cout << "Moving disk from " << source << " to " << dest << endl;
		return;
	}
	PrintSteps(n-1,source,dest,other);
	PrintSteps(1,source,other,dest);
	PrintSteps(n-1,other,source,dest);
}


int32_t main(){
	int n;
	cin >> n;
	
	cout << getSteps(n) << endl;		// Also in O(1) ans is 2^N - 1
	
	// Printing all Steps
	PrintSteps(n,'A','B','C');

	return 0;
}

