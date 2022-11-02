#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using Point=pair<int,int>;
int ccw(const Point &p1, const Point &p2, const Point &p3){
	int t=(p2.x-p1.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p2.y-p1.y);
	if(t>0) return 1;
	if(t<0) return -1;
	return 0;
}
int main(){
	int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
	cout << ccw({a,b},{c,d},{e,f}) << '\n';
}