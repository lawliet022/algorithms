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

vector<int> v = {9,18,19,27,28,29,36,37,38,39,45,46,47,48,49,54,55,56,57,58,59,63,64,65,66,67,68,69,
					72,73,74,75,76,77,78,79,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
	

int32_t main(){
	int t;
	cin >> t;
	map<int,int> m;
	m[9] = 1;
	m[8] = 2;
	m[7] = 3;
	m[6] = 4;
	m[5] = 5;
	m[4] = 6;
	m[3] = 7;
	m[2] = 8;
	m[1] = 9;
	m[0] = 10; 
	while(t--){
		int n;
		cin >> n;
		if(n <= 90){
			int p = lower_bound(v.begin(),v.end(),n) - v.begin();
			if(v[p] != n){
				cout << -1 << endl;
			}
			else{
				if(n % 10 == 9){
					cout << 1 << endl;
				}
				else{
					int temp = 0, flag = 0;
					for(int i = 1; i < 100; i++){
						for(int j = i; j >= 1; j--){
							if(v[temp] == n){
								flag = j;
								break;
							}
							temp++;
						}
						if(flag)
							break;
					}
					cout << flag << endl;
				}
			}
		}
		else{
			cout << m[n % 10] << endl;
		} 
	}

	return 0;
}

