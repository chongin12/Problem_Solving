#include <bits/stdc++.h>
using namespace std;
int arr[51];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int M; cin>>M;
    vector<int> box;
    for(int i=0; i<M; ++i){
        int a; cin>>a;
        box.push_back(a);
    }
    sort(box.begin(), box.end());
    if(box.back()>v.back()){
        cout << "-1\n";
        return 0;
    }
    int prev=-1;
    for(int i=0; i<N; ++i){
        auto pos1=lower_bound(box.begin(), box.end(), prev)-box.begin();
        auto pos2=upper_bound(box.begin(), box.end(), v[i])-box.begin();
        arr[i]=max((int)(pos2-pos1),0);
        prev=v[i]+1;
        // cout << "arr["<<i<<"]="<<arr[i]<<'\n';
    }
    int t=0;
    while(1){
        bool flag=true;
        int cnt=0;
        for(int i=N-1; i>=0; --i){
            while(arr[i] && cnt){
                flag=false;
                arr[i]--;
                cnt--;
            }
            if(arr[i]) {
                arr[i]--;
                flag=false;
            }
            else cnt++;
        }
        if(flag) break;
        ++t;
    }
    cout << t << '\n';
}