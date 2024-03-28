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
pos K(0,0);
int ccw(pos A, pos B, pos C){
    ll c=A.x*B.y+B.x*C.y+C.x*A.y;
    c-=A.y*B.x+B.y*C.x+C.y*A.x;
    if(c<0) return -1;
    if(c>0) return 1;
    return 0;
}
ll dist(pos A, pos B){
    return (B.y-A.y)*(B.y-A.y)+(B.x-A.x)*(B.x-A.x);
}
bool cmp0(pos A, pos B){
    if(A.y==B.y) return A.x<B.x;
    return A.y<B.y;
}
bool cmp(pos A, pos B){
    int ab=ccw(K,A,B);
    if(ab==0) return dist(K,A)<dist(K,B);
    else if(ab==1) return true;
    return false;
}
vector<pos> convexHull(vector<pos> v){
    sort(v.begin(), v.end(), cmp0);
    K=v[0];
    sort(v.begin()+1, v.end(), cmp);
    vector<pos> st;
    st.push_back(v[0]);
    for(int i=1; i<v.size(); ++i){
        pos b=st.back(); st.pop_back();
        if(st.empty()){
            st.push_back(b);
            st.push_back(v[i]);
            continue;
        }
        pos a=st.back();
        if(ccw(a,b,v[i])>0){
            st.push_back(b);
            st.push_back(v[i]);
        }
        else{
            i--;
            continue;
        }
    }
    return st;
}
bool isCross(line A, line B){
    if(A.B < A.A) swap(A.A, A.B);
    if(B.B < B.A) swap(B.A, B.B);
    int a=ccw(A.A, A.B, B.A);
    int b=ccw(A.A, A.B, B.B);
    int ccwa=a*b;
    int c=ccw(B.A, B.B, A.A);
    int d=ccw(B.A, B.B, A.B);
    int ccwb=c*d;
    if(a==0 && b==0 && c==0 && d==0) {
        if(A.A<=B.B && B.A<=A.B) return true;
        if(B.A<=A.B && A.A<=B.B) return true;
        return false;
    }
    return (ccwa<=0) && (ccwb<=0);
}
bool isPosOnLine(line l2, pos T){
    if(l2.B<l2.A) swap(l2.A, l2.B);
    if(l2.A<=T && T<=l2.B && (l2.A.y-l2.B.y)*T.x+(l2.B.x-l2.A.x)*T.y+l2.A.x*l2.B.y-l2.B.x*l2.A.y==0){
        return true;
    }
    return false;
}
bool isInside(vector<pos> &v, pos T) {
    int cnt=0;
    line l1(T, pos(1000000001LL, T.y+1));
    for(int i=0; i<v.size(); ++i){
        line l2(v[i], pos(v[(i+1)%v.size()]));
        if(isPosOnLine(l2, T)){
            cnt=1;
            break;
        }
        if(isCross(l1, l2)) cnt++;
    }
    return cnt%2;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n,m; cin>>n>>m;
        vector<pos> white, black;
        for(int i=0; i<n; ++i){
            ll a,b; cin>>a>>b;
            white.push_back(pos(a,b));
        }
        for(int i=0; i<m; ++i){
            ll a,b; cin>>a>>b;
            black.push_back(pos(a,b));
        }
        vector<pos> convWhite=convexHull(white);
        vector<pos> convBlack=convexHull(black);
        bool flag=true;
        if(convBlack.size()==2){
            line temp(convBlack[0], convBlack[1]);
            for(int i=0; i<convWhite.size() && flag; ++i){
                // 1. convBlack 직선 위에 점이 있는지 판별
                if(isPosOnLine(temp, convWhite[i])) flag=false;
                // 2. 직선이 겹치는지 판별
                if(isCross(temp, line(convWhite[i], convWhite[(i+1)%convWhite.size()]))){
                    flag=false;
                }
            }
        }
        else{
            for(int i=0; i<convWhite.size() && flag; ++i){
                if(isInside(convBlack, convWhite[i])){
                    flag=false;
                    break;
                }
            }
        }
        if(convWhite.size()==2){
            line temp(convWhite[0], convWhite[1]);
            for(int i=0; i<convBlack.size() && flag; ++i){
                // 1. convBlack 직선 위에 점이 있는지 판별
                if(isPosOnLine(temp, convBlack[i])) flag=false;
                // 2. 직선이 겹치는지 판별
                if(isCross(temp, line(convBlack[i], convBlack[(i+1)%convBlack.size()]))){
                    flag=false;
                }
            }
        }
        else{
            for(int i=0; i<convBlack.size() && flag; ++i){
                if(isInside(convWhite, convBlack[i])){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}