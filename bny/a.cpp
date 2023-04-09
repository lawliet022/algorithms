#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define EPS 1e-9
#define pb push_back 
using namespace std;


#define N 100010
vector<pair<long double, long double> > ranges;
bool greaterx(long double a, long double b){
	return (a - b) > EPS;
}
bool greatereq(long double a, long double b){
	return (a - b) > -1 * EPS;
}
bool equal(long double a, long double b){
	return abs(a - b) < EPS;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		long double b, l;
		cin >> l >> b;
		int n;
		cin >> n;
		ranges.clear();
		for(int i = 0; i < n; i++){
			long double x, r;
			cin >> x >> r;
			if(greatereq(r, b / 2)){
				ranges.pb(mp(x - sqrt(r * r - (b * b / 4)),  (x + sqrt(r * r - (b * b / 4)))));
			}
			//cout << ranges.back().first << " " << ranges.back().second << '\n';
		}
		sort(ranges.begin(), ranges.end());
		if(!ranges.size()){
			cout << -1 << '\n';
			continue;
		}
		if(greaterx(ranges[0].first, 0)){
			cout << -1 << '\n';
			continue;
		}
		else{
			int ans = 1;
			long double cur_right = -1 * ranges[0].second;
			int ind = 0, mk = 0;
			long double maxi = 0;
			for(int i = 0; i < ranges.size(); i++){
				if(greatereq(0, ranges[i].first)){
					maxi = max(maxi, ranges[i].second);
				}
			}
			int ptr = 0;
			while(greaterx(l, maxi)){
				long double cur_max = 0;
				while(greatereq(maxi, ranges[ptr].first)){
					ptr++;
					cur_max = max(cur_max, ranges[ptr].second);
				}
				ans++;
				if(equal(cur_max, maxi)){
					mk = 1;
					break;
				}
				maxi = cur_max;
			}
			if(mk)
				cout << -1 << '\n';
			else cout << ans << '\n';
		}
	}


}
