#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

bool isValid(int a[][9], int val, int x, int y){
	
	// In same row
	for(int i = 0; i < 9; i++)
		if(a[x][i] == val)
			return false;
	for(int i = 0; i < 9; i++)
		if(a[i][y] == val)
			return false;
			
	int sx = (x/3)*3, sy = (y/3)*3;
	
	for(int i = sx; i <= sx+2; i++){
		for(int j = sy; j <= sy+2; j++){
			if(a[i][j] == val)
				return false;
		}
	}
	return true;
}

bool solveSudoku(int a[][9], int x, int y){
	if(x == 9){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		return true;
	}

	// rec case
	if(y == 9){
		return solveSudoku(a,x+1,0);
	}
	if(a[x][y] != 0){
		return solveSudoku(a,x,y+1);
	}
	for(int i = 1; i <= 9; i++){
		if(isValid(a,i,x,y)){
			a[x][y] = i;
			bool b = solveSudoku(a,x,y+1);
			if(b)
				return true;
		}
	}
	a[x][y] = 0;
	return false;
}

int32_t main(){
	int a[][9] = {
		5, 3, 0, 0, 7, 0, 0, 0, 0,
		6, 0, 0, 1, 9, 5, 0, 0, 0,
		0, 9, 8, 0, 0, 0, 0, 6, 0,
		8, 0, 0, 0, 6, 0, 0, 0, 3,
		4, 0, 0, 8, 0, 3, 0, 0, 1,
		7, 0, 0, 0, 2, 0, 0, 0, 6,
		0, 6, 0, 0, 0, 0, 2, 8, 0,
		0, 0, 0, 4, 1, 9, 0, 0, 5,
		0, 0, 0, 0, 8, 0, 0, 7, 9
	};
	
	solveSudoku(a,0,0);
	
	return 0;
}

