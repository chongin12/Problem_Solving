#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int N;
int choices[20];
vector<ll> v;
ll res=0;
void f(int phase, int previdx){
    if(phase==N/2){
        ll a=0, b=0;
        for(int i=0; i<N; ++i){
            if(choices[i]){
                a=a*10+v[i];
            }
            else {
                b=b*10+v[i];
            }
        }
        res=max(res,a*b);
        return;
    }
    for(int i=previdx+1; i<N; ++i){
        choices[i]=1;
        f(phase+1, i);
        choices[i]=0;
    }
}
int main(){
    int T; cin>>T;
    while(T--){
        string str; cin>>str;
        N=str.size();
        res=0;
        for(int i=0; i<20; ++i) choices[i]=0;
        v.clear();
        for(auto it:str){
            if(it=='6') v.push_back(9);
            else v.push_back(it-'0');
        }
        sort(v.begin(), v.end(), greater<int>());
        f(0, -1);
        cout << res << '\n';
    }
}