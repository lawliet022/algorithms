#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;


void func(int *p){
	*p = *p + 1;
}

void func2(int *a, int n){
	a[2] = 10;
}

void func3(int a[], int n){
	a[2] = 20;
}

void happy(char *s){
	s[2] = 'z';
}

void out(int &x){
	x++;
}


void pro(char *s){
	s[1] = 'q';
}

int32_t main(){
	int x = 10;
	cout << &x << endl;		// Address of x
	
	int &y = x;				// Reference of a variable - Just an alias or alternative name
	y++;
	x++;
	cout << x << " " << y << endl;
	
	int *p;				// Pointer of type int
	p = &x;
	
	cout << p << endl;		// Address of x
	
	int **q = &p;		//	Pointer of Pointer
	
	// Dereferencing ( * operation with pointer)
	cout << q << endl;			// Address of p
	cout << *q << endl;			// Address of x
	cout << **q << endl;		// Value of x
	cout << *p << endl;			// Value of x
	
	cout << *(&y) << endl;		// value of y
	
	cout << &(*p) << endl;		// Address of x
	cout << &(*q) << endl;		// Address of p  
	
	
	
	
	// Function call - Pass by reference using Pointers
	
	func(&x);
	cout << x << endl;
	
	
	int a[4] = {1,2,3,4};		// Array values can be changed as array is passed by base address
	func2(a,4);
	for(int i = 0; i < 4; i++)
		cout << a[i] << " ";
	cout << endl;
	
	func3(a,4);
	for(int i = 0; i < 4; i++)
		cout << a[i] << " ";
	cout << endl;
	
	char s[] = "abcdef";
	happy(s);
	cout << s << endl;
	
	// Function call - Pass by reference using reference variable
	
	out(x);
	cout << x;
	
	
	// String and pointers
	char *str = "abcd";
	str = "pq";
	
	cout << str[1] << endl;
	
	//str[1] = 'w';					// Not good idea..
	//cout << str << endl;
	
	char s2[] = "abcd";
	pro(s2);						// Can do this with char array not char pointer
	cout << s2 << endl;
	
	return 0;
}

