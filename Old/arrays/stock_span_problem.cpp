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

// Approach -  No of consecutive elements less than equal to a given number on its left

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        stack<pair<int,int>> s;
        for(int i = 0; i < n; i++){
            if(s.empty()){
                cout << 1 << " ";
            }
            else{
                while(s.size() && s.top().F <= a[i])
                    s.pop();
                if(s.empty()){
                    cout << i+1 << " ";
                }
                else{
                    cout << i - s.top().S << " ";
                }
            }
            s.push({a[i],i});
        }
        cout << endl;
    }


	return 0;
}
