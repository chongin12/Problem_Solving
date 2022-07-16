#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
vector<ll> Gx[100001];
vector<ll> Gy[100001];
vector<ll> x,y;
vector<pii> v;
map<ll,ll> X,Y;
ll originalX[100001], originalY[100001];
void init_() {
    for(int i=0; i<100001; ++i){
        Gx[i].clear();
        Gy[i].clear();
        originalX[i]=0;
        originalY[i]=0;
    }
    x.clear();
    y.clear();
    v.clear();
    X.clear();
    Y.clear();
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        init_();
        cout << "Case #"<<t<<endl;
        ll N; cin>>N;
        for(int i=0; i<N; ++i){
            ll a,b; cin>>a>>b;
            v.push_back({a,b});
            x.push_back(a);
            y.push_back(b);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        ll K=0;
        for(int i=0; i<x.size(); ++i){
            if(i && x[i-1]!=x[i]) K++;
            else if(i && x[i-1]==x[i]) continue;
            X[x[i]]=K;
            originalX[K]=x[i];
        }
        K=0;
        for(int i=0; i<y.size(); ++i){
            if(i && y[i-1]!=y[i]) K++;
            else if(i && y[i-1]==y[i]) continue;
            Y[y[i]]=K;
            originalY[K]=y[i];
        }
        for(int i=0; i<N; ++i){
            ll oriX=v[i].first;
            ll oriY=v[i].second;
            ll comX=X[oriX];
            ll comY=Y[oriY];
            Gx[comX].push_back(oriY);
            Gy[comY].push_back(oriX);
        }
        ll rx=-1, ry=-1;
        ll rcx=-1, rcy=-1;
        for(int i=0; i<100001; ++i){
            if(Gx[i].size()%2) {
                rx=i;
                rcx=originalX[i];
            }
            if(Gy[i].size()%2) {
                ry=i;
                rcy=originalY[i];
            }
        }
        ll res=0;
        for(ll i=0; i<100001; ++i){
            if(i==rx) {
                ll prev=-1;
                sort(Gx[i].begin(), Gx[i].end());
                for(ll j=0; j<Gx[i].size(); ++j){
                    if(Gx[i][j]==rcy) continue;
                    if(prev==-1) prev=Gx[i][j];
                    else{
                        res+=Gx[i][j]-prev;
                        prev=-1;
                    }
                }
            }
            else{
                ll prev=-1;
                sort(Gx[i].begin(), Gx[i].end());
                for(ll j=0; j<Gx[i].size(); ++j){
                    if(prev==-1) prev=Gx[i][j];
                    else{
                        res+=Gx[i][j]-prev;
                        prev=-1;
                    }
                }
            }
        }
        for(ll i=0; i<100001; ++i){
            if(i==ry) {
                ll prev=-1;
                sort(Gy[i].begin(), Gy[i].end());
                for(ll j=0; j<Gy[i].size(); ++j){
                    if(Gy[i][j]==rcx) continue;
                    if(prev==-1) prev=Gy[i][j];
                    else{
                        res+=Gy[i][j]-prev;
                        prev=-1;
                    }
                }
            }
            else{
                ll prev=-1;
                sort(Gy[i].begin(), Gy[i].end());
                for(ll j=0; j<Gy[i].size(); ++j){
                    if(prev==-1) prev=Gy[i][j];
                    else{
                        res+=Gy[i][j]-prev;
                        prev=-1;
                    }
                }
            }
        }
        cout << res << endl;
    }
}