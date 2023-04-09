#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD    1000000007
#define int    long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int32_t main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        if(n <= 3){
            cout << n << endl;
            continue;
        }
        int p = 1;
        for(int i = 0; i < 31; i++){
            if((1LL<<i) <= n)
                p = i;
        }
        int prev = (1LL<<p) - 1;
        int dis = __builtin_popcountll(prev);
        int prevprev = (1LL<<(p-1))-1;
        
        int build = (1LL<<p);
        int temp = 0;
        
        while(build <= n && temp < p){
            build |= (1LL<<temp);
            temp++;
        }
        int lastcount;
        if(build > n){
            lastcount = __builtin_popcountll(build) - 1;
        }
        else
            lastcount = __builtin_popcountll(build);
        int ans;
        ans = max(lastcount+dis,dis+__builtin_popcountll(prevprev));
        cout << ans << endl;
    }

    return 0;
}

