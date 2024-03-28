#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using Point=pair<ll,ll>;
int CCW(const Point &p1, const Point &p2, const Point &p3){
	ll t=(p2.x-p1.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p2.y-p1.y);
	if(t>0) return 1;
	if(t<0) return -1;
	return 0;
}
bool Cross(Point a, Point b, Point c, Point d){
	int ab = CCW(a, b, c) * CCW(a, b, d);
	int cd = CCW(c, d, a) * CCW(c, d, b);
	if(ab==0 && cd==0){
		if(a>b) swap(a,b);
		if(c>d) swap(c,d);
		return !(b<c||d<a);
	}
	return ab<=0 && cd<=0;
}
int main(){
	ll a, b, c, d; cin>>a>>b>>c>>d;
	Point A(a,b), B(c,d);
	cin>>a>>b>>c>>d;
	Point C(a,b), D(c,d);
	cout << Cross(A,B,C,D) << '\n';
}