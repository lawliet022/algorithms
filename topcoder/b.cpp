#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

class MaxPlanting{
	public:
		int most(int width, int height, int size, int max){
			if(width < height){
				swap(width,height);
			}
			if(max == size*size){
				return width*height;
			}
			int a[width][height];
			for(int i = 0; i < width; i++){
				if(i+max >= width)
					break;
				for(int j = 0; j < height; j++){
					if(j+max >= height)
						break;
					
				}
			}
	
};

int32_t main(){
	


	return 0;
}
