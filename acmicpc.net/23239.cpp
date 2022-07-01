#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll overW[200010];

int main(){
    ll w,h,L; cin>>w>>h>>L;
    // 1. 쿼터 개수 구하기
    ll q=0;
    for(ll i=0; i<=L; ++i){
        q+=sqrt(L*L-i*i)+1;
    }
    // 2. 왼쪽 절반 먼저 구하기
    ll res=q-min(h,L)-1+q-L-1;

    // 3. 아래쪽
    overW[0]=max(0LL,L-w);
    for(ll i=1; i<L; ++i){
        res+=sqrt(L*L-i*i);
    }
    // 3-1 아래쪽에서 남은거
    if(L>w){
        for(ll i=1; i<=L-w; ++i){
            overW[i]=sqrt((L-w)*(L-w)-i*i);
        }
    }

    // 4. 위쪽
    overW[h]=max(overW[h], L-h-w);
    for(ll i=1; i<L-h; ++i){
        ll temp=sqrt((L-h)*(L-h)-i*i);
        if(temp>w){
            res+=w;
            overW[h+i]=max(overW[h+i],temp-w);
        }
        else{
            res+=temp;
        }
    }
    // 4-1. 위쪽에서 남은거
    if(L-h>w){
        for(ll i=1; i<min(L-h-w, h); ++i){
            overW[h-i]=max(overW[h-i], (ll)sqrt((L-h-w)*(L-h-w)-i*i));
        }
    }
    for(ll i=0; i<=L; ++i){
        res+=overW[i];
    }
    cout << res << '\n';
}