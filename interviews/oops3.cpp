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

// Friend function - is not a member function.. can access protected as well as private members of the class

class abc{
	int a;
public:
	abc(int x): a(x){};
	friend void show(abc w);
};

void show(abc w){
	cout << w.a << endl;
}

int32_t main(){
	abc ob(10);
	show(ob);
	
	return 0;
}

