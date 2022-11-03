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
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        ll a, b, c, d, e, f, g, h; cin>>a>>b>>c>>d>>e>>f>>g>>h;
        Point A(a,b), B(c,d);
        bool flag=false;
        for(int i=min(f,h); i<=max(f,h); ++i){
            Point C(min(e,g),i), D(max(e,g),i);
            if(Cross(A,B,C,D)){
                flag=true;
                break;
            }
        }
        if(flag) cout << "T\n";
        else cout << "F\n";
    }
}