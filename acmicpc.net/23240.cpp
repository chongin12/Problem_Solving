#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct grp{
    ll n;
    int col; // R:0, G:1, B:2
    bool dir;
    grp(ll n, int col, bool dir):n(n),col(col),dir(dir){}
    void toggle(){
        dir=!dir;
    }
};
vector<grp> v;
ll cache[52]; // 그룹 0~i를 옮기는 횟수
ll res=0;
void takeOnlyOne(){
    int idx=v.size()-1; // v에서 현재 그룹 idx
    if(idx>0) res+=cache[idx-1];
    res+=v.back().n;
    if(idx>0) res+=cache[idx-1];
    v.back().toggle();
    v.back().n-=1;
    if(idx==0) cache[idx]=v[idx].n;
    else cache[idx]=cache[idx-1]*2+v[idx].n;
}
void takeAll() {
    int idx=v.size()-1; // v에서 현재 그룹 idx
    if(idx>0) res+=cache[idx-1];
    res+=v.back().n;
    v.pop_back();
    if(!v.empty()) v.back().toggle();
}
int main(){
    int m; cin>>m;
    for(int i=0; i<m; ++i){
        char ch;
        ll a;
        cin>>ch>>a;
        if(ch=='R') v.push_back(grp(a,0,true));
        else if(ch=='G') v.push_back(grp(a,1,true));
        else v.push_back(grp(a,2,true));
    }
    cache[0]=v[0].n;
    for(int i=1; i<v.size(); ++i){
        cache[i]=cache[i-1]*2+v[i].n;
    }
    while(!v.empty()){
        int idx=v.size()-1; // v에서 현재 그룹 idx
        bool flag=true;
        if(v[idx].col==0 && !v[idx].dir) flag=false;
        else if(v[idx].col==2 && v[idx].dir) flag=false; 
        for(int i=idx-1; i>=0 && flag; --i){
            if(v[i].col==0 && v[idx].dir) flag=false;
            else if(v[idx].col==2 && !v[idx].dir) flag=false;
        }
        if(flag){
            res+=cache[idx];
            break;
        }
        if(v.back().n==1) {
            takeAll();
        }
        else if(v.back().col==2) {
            if(v.back().dir) {
                takeOnlyOne();
            } 
            else{
                takeAll();
            }
        }
        else if(v.back().col==0) {
            if(!(v.back().dir)) {
                takeOnlyOne();
            } 
            else{
                takeAll();
            }
        }
        else{
            takeAll();
        }
    }
    cout << res << '\n';
}