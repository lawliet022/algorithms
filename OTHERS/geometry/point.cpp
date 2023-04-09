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



typedef int ftype;

struct point2d{
	ftype x, y;
	point2d() {}
	point2d(ftype x, ftype y): x(x), y(y) {}
	point2d& operator+= (const point2d &t){
		x += t.x;
		y += t.y;
		return *this;
	}
	point2d& operator-= (const point2d &t){
		x -= t.x;
		y -= t.y;
		return *this;
	}
	point2d& operator*= (ftype t){
		x *= t;
		y *= t;
		return *this;
	}
	point2d& operator/= (ftype t){
		x /= t;
		y /= t;
		return *this;
	}
	point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }
    point2d operator*(ftype t) const {
        return point2d(*this) *= t;
    }
    point2d operator/(ftype t) const {
        return point2d(*this) /= t;
    }
};

point2d operator*(ftype a, point2d b){
	return b * a;
}


struct point3d {
    ftype x, y, z;
    point3d() {}
    point3d(ftype x, ftype y, ftype z): x(x), y(y), z(z) {}
    point3d& operator+=(const point3d &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d& operator*=(ftype t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(ftype t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d &t) const {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const {
        return point3d(*this) -= t;
    }
    point3d operator*(ftype t) const {
        return point3d(*this) *= t;
    }
    point3d operator/(ftype t) const {
        return point3d(*this) /= t;
    }
};
point3d operator*(ftype a, point3d b) {
    return b * a;
}

ftype dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}
ftype dot(point3d a, point3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}



int32_t main(){
	point2d p(2,3), q(3,4);
	p = 5 * p;
	
	cout << p.x << " " << p.y << endl;
	
	p += q;
	
	cout << p.x << " " << p.y << endl;
	point2d r(2,3);
	cout << dot(r,q) << endl;
	

	return 0;
}

