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

class TreeLine{
	public:
		 int longest(vector <int> x, vector <int> y){
			if(x.size() <= 2){
				return (int)x.size();
			}
			int best = 2;
			int n = x.size();
			const int inf = 123456789; // :(
			for(int i = 0; i < n; i++){
				for(int j = i+1; j < n; j++){
					int count = 2;
					long double slope = 0;
					long double intercept = 0;
					if(x[j] - x[i] != 0){
						slope = (1.0*y[j]-y[i])/(1.0*x[j]-x[i]);
						intercept =  -1.0*x[i] * slope + 1.0*y[i];
					}
					else{
						slope = inf;
						intercept = inf;
					}
					if(intercept != inf){
						for(int k = 0; k < n; k++){
							if(k != i && k != j){
								long double slope2, intercept2;
								if(x[j] - x[k] == 0){
									continue;
								}
								else{
									if(x[k] - x[j] != 0){
										//cout << i << " " << j << " " << k << "\n";
										slope2 = (1.0*y[j]-y[k])/(1.0*x[j]-x[k]);
										intercept2 =  -1.0*x[k] * slope2 + 1.0*y[k];
										//cout << fixed << setprecision(10) << slope << " " << slope2 << " " << intercept << " " << intercept2 << "\n";
										if( abs(slope2-slope) < EPS && abs(intercept - intercept2) < EPS){
											count++;
											//cout << count << "--\n";
										}
									}
								}
							}
						}
					}
					else{
						//int xcor = x[i];
						for(int k = 0; k < n; k++){
							if(k != i && k != j){
								if(x[k] == x[i]){
									count++;
									//cout << count << "**\n";
								}
							}
						}
					}
					best = max(best,count);
				}
			}
			return best;
		 }
};

int32_t main(){
	vector<int> x = {0, 1, 6, 5, 2, 2, 2, 2, 2}, y = {0, 2, 6, 10, 0, 1, 3, 5, 6};
	
	TreeLine ob;
	
	cout << ob.longest(x,y);


	return 0;
}
