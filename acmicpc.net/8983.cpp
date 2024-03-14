#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int arr[100012];
int main(){
    int M, N, L; cin>>M>>N>>L;
    for(int i=0; i<M; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    int res=0;
    for(int i=0; i<N; ++i){
        int x, y; cin>>x>>y;
        // 잡을 수 있는 사로들을 lower_bound, upper_bound로 계산하고, lower_bound에 +1, upper_bound에 -1 해서 누적합 구하기
        if(y>L) continue;
        int lo=x+y-L, hi=x-y+L;
        auto loIdx=lower_bound(v.begin(), v.end(), lo)-v.begin();
        auto hiIdx=upper_bound(v.begin(), v.end(), hi)-v.begin();
        if(hiIdx!=loIdx) res++;
        arr[loIdx]+=1;
        arr[hiIdx]-=1;
    }
    cout << res << '\n';
}