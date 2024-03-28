#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
struct pos{
    ll x, y;
    pos(ll x, ll y):x(x),y(y){}
};
vector<pos> v;
pos standard(0,0);
ll dist(pos A, pos B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}
int ccw(pos A, pos B, pos C){
    ll k=A.x*B.y+B.x*C.y+C.x*A.y-(A.y*B.x+B.y*C.x+C.y*A.x);
    if(k>0) return 1;
    if(k<0) return -1;
    return 0;
}
bool cmp1(pos A, pos B){
    if(A.y==B.y) return A.x>B.x;
    return A.y<B.y;
}
bool cmp2(pos A, pos B){
    ll cc=ccw(standard, A, B);
    if(cc==0) return dist(standard, A)<dist(standard, B);
    if(cc==1) return true;
    return false;
}
vector<pos> convexHull(){
    sort(v.begin(), v.end(), cmp1);
    standard=v[0];
    sort(v.begin()+1, v.end(), cmp2);
    vector<pos> st;
    st.push_back(standard);
    for(int i=1; i<v.size(); ++i){
        pos p2=st.back();
        st.pop_back();
        if(st.empty()){
            st.push_back(p2);
            st.push_back(v[i]);
            continue;
        }
        pos p1=st.back();
        if(ccw(p1, p2, v[i])>0){
            st.push_back(p2);
            st.push_back(v[i]);
        }
        else{
            i-=1;
        }
    }
    return st;
}
pair<pos, pos> rotatingCalipers(){
    vector<pos> hull=convexHull();
    ll n=hull.size();

    ll l=0, r=0;
    for(int i=1; i<n; ++i){
        if(hull[l].x > hull[i].x) l=i;
        if(hull[r].x < hull[i].x) r=i;
    }
    pos resl=hull[l], resr=hull[r];
    ll d=dist(resl, resr);
    for(int i=0; i<n; ++i){
        pos a(hull[(l+1)%n].x-hull[l].x, hull[(l+1)%n].y-hull[l].y);
        pos b(hull[r].x-hull[(r+1)%n].x, hull[r].y-hull[(r+1)%n].y);
        if(a.x*b.y-a.y*b.x>0){
            l=(l+1)%n;
        }
        else{
            r=(r+1)%n;
        }
        if(d<dist(hull[l],hull[r])){
            d=dist(hull[l],hull[r]);
            resl=hull[l];
            resr=hull[r];
        }
    }
    return {resl, resr};
}
void init(){
    v.clear();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        ll x, y; cin>>x>>y;
        v.push_back(pos(x,y));
    }
    pair<pos, pos> res = rotatingCalipers();
    cout << dist(res.first, res.second) << '\n';
}