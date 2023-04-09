#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int32_t main(){
	//ios::sync_with_stdio(0);
    //cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

		sort(a.begin(),a.end());						// Unique not required actually in this problem
		a.resize(unique(a.begin(),a.end())-a.begin());

        int k;
        cin >> k;
    	int ans = 0;
    	for(int i = 1; i < (1<<a.size()); i++){
    		int x = 1;
    		vi v;
    		for(int j = 20; j >= 0; j--){
    			if(i&(1<<j)){
    				v.PB(a[j]);
    			}
    		}
    		if(v.size() == 1)
				x = v[0];
			else{
				int f = v[0]*v[1]/__gcd(v[0],v[1]);				// finally... lcm(a1,a2,a3,..) can be solved this way
				for(int i = 2; i < (int)v.size(); i++)			// don't just multiply all terms and then divide by gcd
					f = f*v[i]/__gcd(f,v[i]);					// it will give wrong ans
				x = f;
			}
    		if(v.size()%2)
				ans += k/x;
			else
				ans -= k/x;
    	}
    	cout << ans << endl;
    }
	return 0;
}
