#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int,int>;
int ccw(pii a, pii b, pii c){
	int t=(a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);
	if(t>0) return 1;
	if(t<0) return -1;
	return 0;
}
int main(){
	int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
	cout << ccw({a,b},{c,d},{e,f}) << '\n';
}