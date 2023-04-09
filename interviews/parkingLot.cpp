#include<bits/stdc++.h>
using namespace std;

class abc{
private:
	int a;
public:
	abc(int x): a(x){};
	void show(){
		cout << a << endl;
	}
};

int main(){
	abc *ob = NULL;
	ob = new abc(10);
	
	ob->show();
	
	
	return 0;
}
