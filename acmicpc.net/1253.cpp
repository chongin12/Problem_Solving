#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int cnt=0;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(i==j) continue;
            int to_find=v[i]-v[j];
            int count=upper_bound(v.begin(), v.end(), to_find)-lower_bound(v.begin(), v.end(), to_find);
            if(to_find==v[i] && to_find==v[j]){
                count-=2;
            }
            else if(to_find==v[i] || to_find==v[j]){
                count-=1;
            }
            if(count>=1) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';
}