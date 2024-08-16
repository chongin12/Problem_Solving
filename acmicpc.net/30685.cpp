#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<pii> v;
    for(int i=0; i<N; ++i){
        int a, b; cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    int res=2087654321;
    for(int i=1; i<v.size(); ++i){
        int a=v[i-1].first+v[i-1].second/2;
        int b=v[i].first-v[i].second/2;
        if(b<=a){
            // 만남
            int oria = v[i-1].first;
            int aw = v[i-1].second/2;
            int orib = v[i].first;
            int bw = v[i].second/2;
            if(oria+min(aw,bw)>=orib-min(aw,bw)){
                // 서로 2배씩 불어나서 가운데에서 만남
                res=min(res,(orib-oria-1)/2);
            } else {
                res=min(res,min(aw,bw)+orib-min(aw,bw)-(oria+min(aw,bw))-1);
            }
        }
    }
    if(res==2087654321) cout << "forever\n";
    else cout << res << '\n';
}