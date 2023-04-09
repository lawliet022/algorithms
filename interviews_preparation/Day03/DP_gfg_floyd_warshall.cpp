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

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                string s;
                cin >> s;
                if(s != "INF")
                    a[i][j] = stoll(s);
                else
                    a[i][j] = 1e7;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] != 1e7)
                    cout << a[i][j] << " ";
                else
                    cout << "INF ";
            }
            cout << endl;
        }
    }


	return 0;
}
