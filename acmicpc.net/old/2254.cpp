#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
struct pos {
    ll x, y;
    int idx;
    pos(ll x, ll y, int idx):x(x),y(y),idx(idx){}
};
vector<pos> v;
int chk[1001];
pos standard(0,0,0);
ll dist(pos a, pos b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
ll ccw(pos a, pos b, pos c){
    ll k=a.x*b.y+b.x*c.y+c.x*a.y-(a.y*b.x+b.y*c.x+c.y*a.x);
    if(k>0) return 1;
    if(k<0) return -1;
    return 0;
}
bool comp1(pos a, pos b){
    if(a.y==b.y) return a.x>b.x;
    return a.y<b.y;
}
bool comp2(pos a, pos b){
    ll cc=ccw(standard, a, b);
    if(cc==0){
        return dist(standard,a)<dist(standard,b);
    }
    else if(cc==1){
        return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, Px, Py; cin>>N>>Px>>Py;
    ll res=0;
    pos jail(Px,Py,-1);
    for(int i=0; i<N; ++i){
        ll x, y; cin>>x>>y;
        v.push_back(pos(x, y, i));
    }
    ll left=N;
    while(left){
        sort(v.begin(), v.end(), comp1);
        int w=0;
        for(int i=0; i<v.size(); ++i){
            if(chk[v[i].idx]==0){
                standard=v[i];
                w=i;
                break;
            }
        }
        sort(v.begin()+w+1, v.end(), comp2);
        vector<pos> st;
        st.push_back(standard);
        for(int i=0; i<v.size(); ++i){
            if(chk[v[i].idx]) continue;
            if(v[i].idx==standard.idx) continue;
            pos p2=st.back();
            st.pop_back();
            if(st.empty()){
                st.push_back(p2);
                st.push_back(v[i]);
                continue;
            }
            pos p1=st.back();
            st.push_back(p2);
            if(ccw(p1, p2, v[i])>0){
                st.push_back(v[i]);
            }
            else{
                st.pop_back();
                i-=1;
            }
        }
        // cout << "stack found!\n";
        for(auto it:st){
            // cout << "("<<it.x<<","<<it.y<<")\n";
            chk[it.idx]=1;
        }
        left-=st.size();
        if(st.size()<=2) break;
        bool flag=true;
        ll cc1=ccw(st.back(), jail, st[0]);
        for(int i=1; i<st.size(); ++i){
            if(cc1!=ccw(st[i-1], jail, st[i])){
                flag=false;
                break;
            }
        }
        if(!flag){
            break;
        }
        else{
            res++;
        }
        
    }
    cout << res << '\n';
}