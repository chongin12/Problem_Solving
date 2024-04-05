#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin>>N>>K;
    vector<pii> c(K); //회의실
    for(int i=0; i<N; ++i){
        int a, b; cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), [](pii a, pii b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    int res=0;
    for(auto it:v){
        // cout << "now : " << it.first << ", " << it.second << '\n';
        // for(int i=0; i<K; ++i) {
        //     cout << "c["<<i<<"]="<<c[i].first << ", " << c[i].second << '\n';
        // }
        // 더 빡센거에 먼저 넣기
        int idx = 0; // 선택되는 회의실 인덱스
        for(int i=1; i<K; ++i){
            if(it.first<=c[idx].second) idx=i;
            else if(c[i].second > c[idx].second && c[i].second < it.first) idx=i;
        }
        // cout << "c[idx] = " << c[idx].first << ", " << c[idx].second << '\n';
        if(c[idx].second < it.first){
            // cout << "success!\n";
            res++;
            c[idx] = it;
        }
    }
    cout << res << '\n';
}
/*
1 2 4 4
1 3

3 5
1 6
*/