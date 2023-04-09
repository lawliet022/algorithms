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

// MAX rectangular area in a histogram - Using Stack

// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0

int a[1000005];
int l[1000005], r[1000005];			// Warning - Make 10^6 or large arrays global else you can receive a Seg fault

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;

	while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        stack<pair<int,int>> s;
        for(int i = 0; i < n; i++){
            if(s.empty()){
                l[i] = 0;
                s.push({a[i],i});
            }
            else{
                while(s.size() && s.top().F >= a[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push({a[i],i});
                    l[i] = 0;
                }
                else{
                    l[i] = s.top().S + 1;
                    s.push({a[i],i});
                }
            }
        }
        while(s.size())
            s.pop();
        
        for(int i = n-1; i >= 0; i--){
            if(s.empty()){
                r[i] = n-1;
                s.push({a[i],i});
            }
            else{
                while(s.size() && s.top().F >= a[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push({a[i],i});
                    r[i] = n-1;
                }
                else{
                    r[i] = s.top().S - 1;
                    s.push({a[i],i});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans,(r[i]-l[i]+1)*a[i] );
        }
        cout << ans << endl;
    }


	return 0;
}
