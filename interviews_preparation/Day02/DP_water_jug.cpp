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
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
		int a, b, c;
		cin >> a >> b >> c;
        map<pair<int,int>,int> m;
	
    	queue<pair<pair<int,int>,int>> q;
    	q.push({{0,0},0});
    	m[{0,0}] = 1;
    	int ans = -1;
    	
    	while(!q.empty()){
    		auto p = q.front();
    		q.pop();
    		
    		if(p.F.F == c || p.F.S == c){
    			ans = p.S;
    			break;
    		}
    		if(p.F.F != a){							// Filling 1st
    			if(m.count({a,p.F.S}) == 0){
    				q.push({{a,p.F.S},p.S+1});
    				m[{a,p.F.S}] = 1;
    			}
    		}
    		if(p.F.S != b){							// Filling 2nd
    			if(m.count({p.F.F,b}) == 0){
    				q.push({{p.F.F,b},p.S+1});
    				m[{p.F.F,b}] = 1;
    			}
    		}
    		if(p.F.F){								// 1 -> 2
    			if(p.F.S + p.F.F <= b){							
    				if(m.count({0,p.F.F+p.F.S}) == 0){
    					q.push({{0,p.F.F+p.F.S},p.S+1});
    					m[{0,p.F.F+p.F.S}] = 1;
    				}
    			}
    			else{
    				if(m.count({p.F.F-(b-p.F.S),b}) == 0){
    					q.push({{p.F.F-(b-p.F.S),b},p.S+1});
    					m[{p.F.F-(b-p.F.S),b}] = 1;
    				}
    			}
    			if(m.count({0,p.F.S}) == 0){								// Throw 2
    				q.push({{0,p.F.S},p.S+1});
    				m[{0,p.F.S}] = 1;
    			}
    		}
    		if(p.F.S){								//  2 -> 1
    			if(p.F.S + p.F.F <= a){							
    				if(m.count({p.F.F+p.F.S,0}) == 0){
    					q.push({{p.F.F+p.F.S,0},p.S+1});
    					m[{p.F.F+p.F.S,0}] = 1;
    				}
    			}
    			else{
    				if(m.count({a,p.F.S-(a-p.F.F)}) == 0){
    					q.push({{a,p.F.S-(a-p.F.F)},p.S+1});
    					m[{a,p.F.S-(a-p.F.F)}] = 1;
    				}
    			}
    			if(m.count({p.F.F,0}) == 0){								// Throw 2
    				q.push({{p.F.F,0},p.S+1});
    				m[{p.F.F,0}] = 1;
    			}
    		}
    	}
    	cout << ans << endl;
    }


	return 0;
}
