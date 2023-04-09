#include<bits/stdc++.h>
using namespace std;

class base 
{
	public:
		base(){
			x = 10;
			y = 20;
			z = 30;
		}
		int x;
	protected:
		int y;
	private:
		int z;
};
class publicDerived: public base
{
	// x is public
	// y is protected
	// z is not accessible from publicDerived
	public:
		void showy(){			// can do this because y is inherited as protected and protected members can be acccessed by subclass
			cout << y << endl; 
		}
};
class protectedDerived: protected base
{
	// x is protected
	// y is protected
	// z is not accessible from protectedDerived
};
class privateDerived: private base
{
	// x is private
	// y is private
	// z is not accessible from privateDerived
};



int main(){
	
	publicDerived ob;
	
	cout << ob.x << endl;
	//cout << ob.y << endl;		// can't do this.. y is protected in publicDerived 
	
	ob.showy();
	
	return 0;
}
