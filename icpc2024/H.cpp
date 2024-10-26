#include <bits/stdc++.h>
using namespace std;
int chk[14];
vector<int> v;
int d,h,l,m;
int A,B,C,D,E,F,G,H;
int res;
void f(int phase) {
    if(phase==3) {
        if(E!=v[0]+v[1]+v[2]+d) return;
    }
    else if(phase==6){
        if(F!=v[3]+v[4]+v[5]+h) return;
    }
    else if(phase==7){
        if(A!=v[0]+v[3]+v[6]+l) return;
    }
    else if(phase==8){
        if(B!=v[1]+v[4]+v[7]+m) return;
    }
    else if(phase==9){
        if(C==v[2]+v[5]+v[8] && G==v[6]+v[7]+v[8]) {
            res++;
        }
        return;
    }
    for(int i=1; i<=13; ++i){
        if(chk[i]) continue;
        v.push_back(i);
        chk[i]=1;
        f(phase+1);
        chk[i]=0;
        v.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>A>>B>>C>>D>>E>>F>>G>>H;
    for(d=max(D-13,1); d<=min(D-1,13); ++d){
        h=D-d;
        if(d==h) continue;
        chk[d]=1;
        chk[h]=1;
        for(l=max(H-13,1); l<=min(H-1,13); ++l){
            m=H-l;
            if(chk[l] || chk[m]) continue;
            if(l==m) continue;
            chk[l]=1;
            chk[m]=1;

            f(0);

            chk[l]=0;
            chk[m]=0;
        }
        chk[d]=0;
        chk[h]=0;
    }
    cout << res << '\n';
}