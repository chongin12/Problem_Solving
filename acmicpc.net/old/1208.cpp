#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<ll> Left;
vector<ll> Right;
vector<ll> arr;
int main(){
	ll n,s;cin>>n>>s;
	for(ll i=0; i<n; ++i){
		ll a;cin>>a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	ll ls=n/2;
	ll pls=pow(2,ls);
	ll rs=n-n/2;
	ll prs=pow(2,rs);
	for(ll i=1; i<pls; ++i){
		ll temp=0;
		for(int j=0; j<ls; ++j){
			if(i&(1<<j)) {
				temp+=arr[j];
			}
		}
		Left.push_back(temp);
	}
	for(int i=1; i<prs; ++i){
		ll temp=0;
		for(int j=0; j<rs; ++j){
			if(i&(1<<j)) {
				temp+=arr[j+ls];
			}
		}
		Right.push_back(temp);
	}
	sort(Left.begin(), Left.end());
	sort(Right.begin(), Right.end());
	// for(auto it:Left){
	// 	cout << it << " ";
	// }
	// cout << '\n';
	// for(auto it:Right){
	// 	cout << it << " ";
	// }
	// cout << '\n';
	ll res=0;
	for(int i=0; i<Left.size(); ++i){
		if(Left[i]==s) res+=1;
	}
	for(int i=0; i<Right.size(); ++i){
		if(Right[i]==s) res+=1;
	}
	for(int i=0; i<Left.size(); ++i){
		ll pos1=lower_bound(Right.begin(), Right.end(), s-Left[i])-Right.begin();
		ll pos2=upper_bound(Right.begin(), Right.end(), s-Left[i])-Right.begin();
		res+=pos2-pos1;
	}
	cout << res << '\n';
}
/*
정렬한다.
배열을 둘로 쪼갠다.
둘로 쪼갠 배열 각각 나올 수 있는 값을 다 구한다.
다 구한 값을 배열에 넣어두고 (최대 1024*1024)
왼쪽 배열을 순회하면서 s-그값의 lowerbound, upperbound를 구하고 그 사이 개수를 더함,

*/