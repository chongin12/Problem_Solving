#include <cmath>
#include <iostream>
#include <vector>
typedef long long int ll;
using namespace std;
const ll MAX_PRIME = 2000001;
//bool sieve[MAX_PRIME];//소수 판별
bool isErased[MAX_PRIME];//제곱ㄴㄴ수 판별
vector<ll> prime;
int main(){
    ll min, max;
    cin >> min >> max;
	ll n = max-min+1;
	for(ll i=2; ; ++i){
		ll d = i*i;
		if(d>max) break;
		//cout << d << " <-d\n";
		/*
		min~max 구간의 d의 배수들을 지워야 함.
		100~200 구간의 9의 배수 지우기
		(min/d)*d 이 min이 아니면 하나 통과시키고 시작
		총 n/d만큼 반복.
		*/
		ll m = (min/d);
		m*=d;
		for(ll j=0; ; ++j){
			if(m+j*d-min<0) continue;
			if(m+j*d-min >= MAX_PRIME) break;
			isErased[m+j*d-min]=true;
			//cout << m+j*d-min << " <- m+j*d-min\n";
		}
	}
	int cnt =0;
	for(int i=0; i<n; ++i){
		if(!isErased[i]) cnt++;
	}
	cout << cnt << '\n';
}
/*
제곱ㄴㄴ수는 소수들만의 곱으로 이루어진 수이다.
1. 에라토스테네스의 체로 1~1,000,000까지 소수를 찾는다. // 100000000의 배수도 포함이므로 이렇게 하믄 안댐. 
2. min~max까지의 수들이 제곱ㄴㄴ수인지 판별한다.
3. 판별과정에서도 에라토스테네스의 체를 이용한다.
4. 0+min ~ 1,000,000+min 의 범위를 배열로 만들어고, 소수의 제곱의 배수 다 지우기.

*/
