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

vector<int> zFunction(string s){
	int n = s.size();
	vector<int> z(n,0);
	
	int L = 0, R = 0;
	for(int i = 1; i < n; i++) {
		if(i > R){
			L = R = i;
			while(R < n && s[R-L] == s[R])
				R++;
			z[i] = R-L;
			R--;
		}
		else{
			int k = i-L;
			if(z[k] < R-i+1){
				z[i] = z[k];
			}
			else{
				L = i;
				while (R < n && s[R-L] == s[R])
					R++;
				z[i] = R-L; R--;
			}
		}
	}
	
	return z;

}

int32_t main(){
	string s = "aaabaab";
	
	vector<int> z = zFunction(s);
	
	for(int x : z)
		cout << x << " ";
	cout << endl;

	return 0;
}

