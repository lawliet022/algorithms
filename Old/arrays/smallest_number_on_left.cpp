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
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
            
        stack<int> s;
        for(int i = 0; i < n; i++){
            if(s.empty()){
                cout << -1 << ' ';
            }
            else{
                while(s.size() && s.top() >= a[i])
                    s.pop();
                if(s.empty()){
                    cout << -1 << " ";
                }
                else{
                    cout << s.top() << " ";
                }
            }
            s.push(a[i]);
        }
        cout << endl;
    }


	return 0;
}
