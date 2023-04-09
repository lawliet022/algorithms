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

int rand(int a, int b){
	return a + rand() % (b - a + 1);
}

string getString(int mini, int maxi){
	string a = "";
	int n = rand(mini,maxi);
	for(int i = 0; i < n; i++){
		char c = 'a' + rand(0,6);
		a += c;
	}
	return a;
}

int32_t main(int argc, char* argv[]){
	srand(atoi(argv[1]));	
	cout << 1 << endl;
	int n = rand(3, 10);
	cout << n << endl;
	for(int i = 0; i < n; i++){
		cout << rand(1, 10) * 5 << " ";
	}
	cout << endl;
	
	for (int i = 1; i <= n; i++) {
		cout << rand(0, i - 1) << " ";
	}
	cout << endl;
	
	return 0;
}

