#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pdd=pair<double,double>;
double dist(pdd a, pdd b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	double x1,y1,x2,y2,x3,y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;
	pdd A(x1,y1),B(x2,y2),C(x3,y3);
	if(B.y-A.y!=0 && C.y-B.y!=0 && (B.x-A.x)/(B.y-A.y) == (C.x-B.x)/(C.y-B.y)) cout << "-1\n";
	else if(B.y-A.y==0 && C.y-B.y==0) cout << "-1\n";
	else{
		cout.precision(20);
		cout << fixed;
		double d1=dist(A,B)*2, d2=dist(B,C)*2, d3=dist(C,A)*2;
		double rmin, rmax;
		rmin=min({d1+d2,d1+d3,d2+d3});
		rmax=max({d1+d2,d1+d3,d2+d3});
		cout << rmax-rmin << '\n';
	}
}