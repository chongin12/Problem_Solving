#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
vector<int> v1;
vector<int> v2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, H; cin>>N>>H;
    vector<int> res(H+1);
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(i%2==0){
            v1.push_back(a);
        } else {
            v2.push_back(a);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int l=0, r=1;
    int minVal = 987654321;
    int cnt=0;
    int idx=0;
    for(int h=1; h<=H; ++h){
        while(idx < v1.size() && v1[idx]<h) idx++;
        res[h]=v1.size()-idx;
        // cout << "res["<<h<<"]="<<res[h]<<'\n';
    }
    idx=0;
    for(int h=1; h<=H; ++h){
        while(idx < v2.size() && v2[idx]<h) idx++;
        int resIdx = H-h+1;
        res[resIdx]+=v2.size()-idx;
        // cout << "res["<<resIdx<<"]="<<res[resIdx]<<'\n';
        if(minVal>res[resIdx]) minVal = res[resIdx], cnt=1;
        else if(minVal==res[resIdx]) cnt++;
    }
    cout << minVal << " " << cnt << '\n';
}