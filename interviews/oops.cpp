#include<bits/stdc++.h>
using namespace std;

class abc{
private:
	int a;
	int b;				// Instance variable
public:
	static int cnt;		// class variable
	abc(){};
	abc(int x, int y): a(x), b(y){cnt++;};
	~abc(){
		cout << "bye " << cnt-- << "\n";
	}
	void show(){
		cout << a << " " << b << endl;
	}
	void show(int x){				// Function Overloading (Compile time Polymorphism / Early Binding)
		cout << a+x << " " << b+x << endl;
	}
	abc operator+(const abc &ob){	// Operator Overloading (Also Compile time polymorphism)
		abc res;
		res.a = a + ob.a;
		res.b = b + ob.b;
		return res;
	}
};


int abc::cnt = 0;		// Initilising a static(class) variable

int main(){
	// Can use this method for heap memory but for now lets stick with normal method only
	//abc *ob = NULL;
	//ob = new abc(10);
	
	//ob->show();		// Always remember no '.' now only '->'
	//delete(ob1);
	
	
	abc ob1(5, 10);
	abc ob2(10,15);
	abc ob3 = ob1 + ob2;
	ob3.show();
	
	
	return 0;
}
