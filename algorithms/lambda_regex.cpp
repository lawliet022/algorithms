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


// . is used to match a single character (does not depend on previous character)
// + is used to match preciding item one or more time
// * is used to match previous item zero or more times
// ? means preceding item is to be matched zero or one time
// {5}	means preceding item is matched 5 times
// {5,} means preceding item is matched 5 or more times
// {5,7} means preceding item is matched between 5 to 7 times
// ^ matches the empty string at the beginning of a line
// $ matches the empty string at the end of a line.

int32_t main(){
	auto f = [](int a, int b){return a+b;};
	cout << f(97,2) << endl;
	
	// C++ raw string
	string s = R"(Hello\nworld)";
	cout << s << endl;
	
	s = R"(abcd
	efgh)";
			
	cout << s << endl;
	
	
	regex pattern(R"(^[a-zA-Z0-9]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+$)");		// raw string is used as \ can be part of expression
	string email = "a@gmail.com";
	if(regex_match(email,pattern)){
		cout << "Matched\n";
	}
	else
		cout << "Not matching\n";
		
	regex email_pattern(R"(^[a-z]+[a-zA-Z0-9]*@[a-z]+[a-zA-z0-9]*\.[a-z]+[a-zA-z0-9]*)");
	if(regex_match(email,email_pattern)){
		cout << "Matched\n";
	}
	else
		cout << "Not matching\n";
	


	return 0;
}

