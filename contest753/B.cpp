#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll MN=800000000;
void fr(ll a, ll b, ll c, ll d, ll e, ll f){ // 첫번째 랜드마크를 꼭짓점(1,1)에 두기
	cout << a << " " << b << " "<< c << " "<< d << " "<< e << " "<< f << "\n";
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll T; cin>>T;
	while(T--){
		ll a,b,c; cin>>a>>b>>c;
		if(a+b==c){ // 첫 번째 랜드마크를 1,1로 두번째는 a만큼, 세번재는 c만큼
			ll x1,x2,x3;
			ll y1,y2,y3;
			x1=1;
			y1=1;
			x2=1+a/2;
			y2=1+a/2;
			if(a%2) {
				x2+=1;
				if(x2>MN){
					x2-=1;
					
				}
			}
			x3=1+c/2;
			y3=1+c/2;
			if(c%2) y3+=1;
			if(x1<=MN && y1<=MN && x2<=MN && y2<=MN && x3<=MN && y3<=MN) {
				fr(x1,y1,x2,y2,x3,y3);
				continue;
			}
		}
		if(a+c==b){ // 두 번재 랜드마크를 1,1로 첫번째는 a만큼, 세번째는 b만큼
			ll x1,x2,x3;
			ll y1,y2,y3;
			x2=1;
			y2=1;
			x1=1+a/2;
			y1=1+a/2;
			if(a%2) x1+=1;
			x3=1+b/2;
			y3=1+b/2;
			if(b%2) y3+=1;
			if(x1<=MN && y1<=MN && x2<=MN && y2<=MN && x3<=MN && y3<=MN) {
				fr(x1,y1,x2,y2,x3,y3);
				continue;
			}
		}
		if(b+c==a){ // 세 번째 랜드마크를 1,1로, 첫번째는 c만큼, 두번째는 b만큼
			ll x1,x2,x3;
			ll y1,y2,y3;
			x3=1;
			y3=1;
			x1=1+c/2;
			y1=1+c/2;
			if(c%2) x1+=1;
			x2=1+b/2;
			y2=1+b/2;
			if(b%2) y2+=1;
			if(x1<=MN && y1<=MN && x2<=MN && y2<=MN && x3<=MN && y3<=MN) {
				fr(x1,y1,x2,y2,x3,y3);
				continue;
			}
		}
		cout << "-1\n";
	}
}