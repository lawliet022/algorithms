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

int egcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = egcd(b,a%b,x1,y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return d;
}


int32_t main(){
	int n, m, a, k;
	while(cin >> n >> m >> a >> k){
		if(!n && !m && !a && !k)
			break;
		int a1 = n, a2 = a+k;
		int d1 = m, d2 = a;
		
		int c = (a1-a2) + (d2-d1);
		int gc = __gcd(d1,d2);
		if(gc == 0){
			if(a1 == a2)
				cout << a1 << endl;
			else
				cout << "Impossible\n";
			continue;
		}
		
		if(c % gc){
			cout << "Impossible\n";
			continue;
		}
		int d = egcd(d2,-d1,m,n);	
		if(d < 0){
			m = -m;
			n = -n;
			d = -d;
		}
		int k = min(floor((c*1.0*m-1)/d1),floor((c*1.0*n-1)/d2));	
		int x = c/gc*m-(k*d1/gc);
		
		cout << a2 + (x-1)*d2 << endl;
	}

	return 0;
}

