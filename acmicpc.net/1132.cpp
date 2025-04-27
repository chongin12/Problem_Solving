#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<string> v;
vector<ll> alphaNums(10);
vector<ll> isNotZero(10);
int main(){
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        string str; cin>>str;
        v.push_back(str);
        for(ll j=0; j<str.size(); ++j){
            alphaNums[str[str.size()-1-j]-'A']+=pow(10, j);
        }
        isNotZero[str[0]-'A']=1;
    }
    vector<ll> nums; // [0] = 'A', [1] = 'B' , ...
    for(ll i=0; i<10; ++i){
        nums.push_back(i);
    }
    ll result=0;
    do {
        bool toContinue=false;
        for(ll i=0; i<10; ++i){
            if(nums[i]==0 && isNotZero[i]){
                toContinue=true;
            }
        }
        if(toContinue) continue;
        ll res=0;
        for(ll i=0; i<10; ++i){
            res+=alphaNums[i]*nums[i];
        }
        result=max(result, res);
    } while(next_permutation(nums.begin(), nums.end()));
    cout << result << '\n';
}