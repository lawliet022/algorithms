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

//Function overriding on the other hand occurs when a derived class has a definition for one
//of the member functions of the base class. That base function is said to be overridden.

class abc{
public:
	virtual void show(){			// Runtime Polymorphism - Function Overriding - Dynamic binding
		cout << "In abc\n";
	}
};

class def : public abc{
public:
	void show(){
		cout << "In def\n";
	}
};


int32_t main(){
	abc *a = new def();
	a->show();
	
	// Enum
	enum phone{nokia, poco, vivo, apple};
	
	phone p = poco;
	cout << p << endl;
	
	if(p == poco)
		cout << "YES\n";
	return 0;
}

