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


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]" << " ";
	err(++it, args...);
}

vector<int> brute(int a, int b){
	int ans = 0;
	cerr << a << " " << b << " here " << endl;
	for(int i = 1; i <= 1000; i++){
		if(a >= b){
			if(a < i){
				return {ans,a,b};
			}
			a -= i;
		}
		else{
			if(b < i){
				return {ans,a,b};
			}
			b -= i;
		}
		ans++;
	}
	return {};
}

int rand(int a, int b){
	return rand() % (b-a+1) + a;
}

int32_t main(){
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		//cout << "Case #" << test << ": ";
		int l, r;
		//cin >> l >> r;
		l = rand(1,1000);
		r = rand(1,1000);
		int lc = l, rc = r;
		//------------------------------------------------------------
		vector<int> me;
		if(l >= r){
			int ll = 1, rr = 2e9;
			int steps = 0;
			while(ll <= rr){
				int mid = (ll + rr) / 2;
				if(l - mid*(mid+1)/2 < r){
					steps = mid;
					rr = mid-1;
				}
				else
					ll = mid+1;
			}
			if(l-steps*(steps+1)/2 < 0){
				//cout << steps - 1 << " " << l-(steps*(steps-1)/2) << " " << r << endl;
				me = {steps - 1,l-(steps*(steps-1)/2),r};
				goto xx;
			}
			
			l -= steps*(steps + 1) / 2;
			int ans = steps;
			
			
			int s2 = 0;
			ll = 0, rr = 2e9;
			while(ll <= rr){
				int mid = (ll + rr) / 2;
				if(mid*(2*(steps+1) + (mid-1)*2)/2 <= r){
					s2 = mid;
					ll = mid+1;
				}
				else
					rr = mid-1;
			}
			
			
			
			int s1 = 0;
			
			ll = 0, rr = 2e9;
			
			while(ll <= rr){
				int mid = (ll + rr) / 2;
				if(mid*(2*(steps+2) + (mid-1)*2)/2 <= l){
					s1 = mid;
					ll = mid+1;
				}
				else
					rr = mid-1;
			}
			
			
			//error(s1,s2);
			//cerr << endl;
			//error(l,r);
			//cerr << endl;
			
			ans += s1 + s2;
			
			l -= s1 * (2*(steps+2) + (s1 -1) * 2) / 2;
			r -= s2 * (2*(steps+1) + (s2 -1) * 2) / 2;
			
			me = {ans,l,r};
			
			//cout << ans << " " << l << " " << r << endl;
		}
		else{
			int ll = 1, rr = 2e9;
			int steps = 0;
			while(ll <= rr){
				int mid = (ll + rr) / 2;
				if(r - mid*(mid+1)/2 <= l){
					steps = mid;
					rr = mid-1;
				}
				else
					ll = mid+1;
			}
			if(r-steps*(steps+1)/2 < 0){
				cout << steps - 1 << " " << l << " " <<  r-(steps*(steps-1)/2) << endl;
				
				me =  {steps - 1, l,  r-(steps*(steps-1)/2)};
				goto xx;
				//continue;
			}
			
			r -= steps*(steps + 1) / 2;
			int ans = steps;
			
			error(steps,l,r);
			cerr << endl;
			
			int s1 = 0;
			ll = 0, rr = 2e9;
			
			while(ll <= rr){
				int mid = (ll + rr) / 2;
				if(mid*(2*(steps+1) + (mid-1)*2)/2 <= l){
					s1 = mid;
					ll = mid+1;
				}
				else
					rr = mid-1;
			}
			
			int s2 = 0;
			ll = 0, rr = 2e9;
			while(ll <= rr){
				int mid = (ll + rr) / 2;
				if(mid*(2*(steps+2) + (mid-1)*2)/2 <= r){
					s2 = mid;
					ll = mid+1;
				}
				else
					rr = mid-1;
			}
			//error(s1,s2);
			//cerr << endl;
			//error(s1,s2);
			//cerr << endl;
			//error(l,r);
			//cerr << endl;
			
			ans += s1 + s2;
			
			l -= s1 * (2*(steps+1) + (s1 -1) * 2) / 2;
			r -= s2 * (2*(steps+2) + (s2 -1) * 2) / 2;
			
			//cout << ans << " " << l << " " << r << endl;
			me = {ans,l,r};
		}
		
		
		
		//-----------------------------------------------------------
		xx:
		
		vector<int> her = brute(lc,rc);
		if(me != her){
			cout << "Wtf\n";
			cerr << lc << " " << rc << endl;
			cerr << me[0] << " " << me[1] << " " << me[2] << endl;
			cerr << her[0] << " " << her[1] << " " << her[2] << endl;
			
			return 0;
		}
		else{
			cout << "Passed\n";
		}
		
	}

	return 0;
}

