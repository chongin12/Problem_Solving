#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int M_S = 50000;
const ll MAX = 2e9;
vector<ll> prime;
vector<ll> primeSq; //  소수^2의 값을 저장한다.
bool isErased[M_S];
ll calStack;
ll X;
void s(int f, int l, int cnt, ll N, ll cal){ // f~l까지 cnt만큼 택한
	
	if(cnt<=0) return;
	for(int i=f; i<=l; ++i){
		ll temp=cal*primeSq[i];
		if(temp > N) return;
		if(cnt==1){
			//cout << (N/(cal*primeSq[i])) << " <- + calStack in s()\n";
			//cout << cal*primeSq[i] << " <- cal*primeSq[" << i << "]\n";
			calStack+=(N/temp);
		}
		else{
			s(i+1, l, cnt-1, N, temp);
		}
	}
}
bool isNonosu(ll a){
	for(int i=0; i<primeSq.size(); ++i){
		if(a<primeSq[i]) break;
		if(a%primeSq[i]==0) return false;
	}
	return true;
}
int main(){
	for(ll p=2; p<M_S; ++p){
		if(isErased[p]) continue;
		prime.push_back(p);
		primeSq.push_back(p*p);
		for(ll i=p*p; i<M_S; i+=p){
			isErased[i]=true;
		}
	}
	ll K; cin >> K;
	ll low=1;
	ll high=MAX+1;
	ll mid=0;
	while(low<high){
		mid = (low+high)/2;
		for(ll i=0; ; ++i){
			if(isNonosu(mid+i)){
				mid=mid+i;
				break;
			}
			if(mid-i>0 && isNonosu(mid-i)){
				mid=mid-i;
				break;
			}
		}
		//cout << mid << " <- mid\n";
		//int n = lower_bound(prime.begin(), prime.end(), sqrt(mid)) - prime.begin();
		int n = 7;
		//cout << n << " <- n\n";
		ll x=0;
		for(int i=1; i<n; ++i){
			//cout << i << " <- i\n";
			calStack=0;
			s(0,prime.size()-1,i,mid,1);
			//cout << calStack << " <-calStack in s(0,"<<n-1<<","<<i<<")\n";
			if(i%2){
				//cout << calStack << " <- x-=calStack\n";
				x+=calStack;
			}
			else {
				//cout << calStack << " <- x+=calStack\n";
				x-=calStack;
			}
		}
		//cout << x << " <- x\n";
		if(mid-x==K) {
			low=high=mid;
		}
		else if(mid-x>K){
			high = mid-1;
		}
		else {
			low = mid+1;
		}
	}
	cout << low << '\n';
}

/*
중간값을 기준으로 찾지 말고
중간값까지 제곱ㄴㄴ수가 아닌게 몇개 있는지 세고, 
그 개수를 중간값에서 뺀 값이 k와 같음을 확인한다.
근데 중간값이 제곱ㄴㄴ수가 아니라면? 가장 가까운 다음 제곱ㄴㄴ수를 찾고, 그 값을 리턴한다.
*/