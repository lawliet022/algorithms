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


// something like 111100001111 in constant time given position a and b
int32_t main(){
	int a = 2, b = 5;		// .....11111000011
	
	int no = (1<<(b-a+1))-1;
	no <<= a;
	no = ~no;
	
	for(int i = 30; i >= 0; i--)
		if(no&(1<<i))
			cout << 1;
		else
			cout << 0;
			

	return 0;
}

