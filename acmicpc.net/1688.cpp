#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct pos {
    ll x, y;
    pos(ll x, ll y):x(x),y(y){}
    bool operator<(pos other) {
        if(x==other.x) return y<other.y;
        return x<other.x;
    }
    bool operator<=(pos other) {
        if(x==other.x && y==other.y) return true;
        return *this<other;
    }
};
struct line {
    pos A, B;
    line(pos A, pos B):A(A),B(B){}
};
int ccw(pos A, pos B, pos C){
    ll c=A.x*B.y+B.x*C.y+C.x*A.y;
    c-=A.y*B.x+B.y*C.x+C.y*A.x;
    if(c<0) return -1;
    if(c>0) return 1;
    return 0;
}
bool isCross(line A, line B){
    int a=ccw(A.A, A.B, B.A);
    int b=ccw(A.A, A.B, B.B);
    int ccwa=a*b;
    int c=ccw(B.A, B.B, A.A);
    int d=ccw(B.A, B.B, A.B);
    int ccwb=c*d;
    if(a==0 && b==0 && c==0 && d==0) return false;
    return (ccwa<=0) && (ccwb<=0);
}
bool isInside(vector<pos> &v, pos T) {
    int cnt=0;
    line K(T, pos(1000000001LL, T.y+1));
    for(int i=0; i<v.size(); ++i){
        line H(v[i], pos(v[(i+1)%v.size()]));
        if(H.B<H.A) swap(H.A, H.B);
        if(H.A<=K.A && K.A<=H.B && (H.A.y-H.B.y)*K.A.x+(H.B.x-H.A.x)*K.A.y+H.A.x*H.B.y-H.B.x*H.A.y==0){
            cnt=1;
            break;
        }
        if(isCross(K, H)) cnt++;
    }
    return cnt%2;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<pos> v;
    for(int i=0; i<N; ++i){
        ll a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    for(int i=0; i<3; ++i){
        ll a,b; cin>>a>>b;
        if(isInside(v, pos(a,b))){
            cout << "1\n";
        } 
        else {
            cout << "0\n";
        }
    }
    
}