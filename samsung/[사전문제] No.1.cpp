#include <bits/stdc++.h>
using namespace std;
int down[20001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int cnt=1;
    for(int i=1;;++i){
        if(cnt>20000) break;
        for(int j=0; j<i; ++j){
            if(cnt>20000) break;
            down[cnt]=cnt+i;
            cnt++;
        }
    }
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        int s, e; cin>>s>>e;
        if(s>e) swap(s,e);
        int l=s, r=s;
        int cnt=0;
        while(1){
            if(l<=e && e<=r){
                break;
            }
            else if(down[l]-l == down[e]-e){ // 같은 레벨에 있는지?
                if(e<l) cnt+=l-e;
                else cnt+=e-r;
                break;
            }
            cnt+=1;
            l=down[l], r=down[r]+1;
        }
        cout << "#" << t << " " << cnt << '\n';
    }
}