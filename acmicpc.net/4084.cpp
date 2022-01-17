#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	while(1){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		if(a+b+c+d==0) break;
		ll cnt=0;
		while(1){
			if(a==b && c==d&&a==c) break;
			ll q,w,e,r;
			q=abs(a-b);
			w=abs(b-c);
			e=abs(c-d);
			r=abs(d-a);
			a=q;
			b=w;
			c=e;
			d=r;
			cnt++;
		}
		cout << cnt << '\n';
	}
}