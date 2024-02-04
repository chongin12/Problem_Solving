#include <bits/stdc++.h>
using namespace std;
vector<int> v; // v[i] : i-1번째 짝수 수부터 i번째 짝수 수까지 사이에 있는 홀수 수 개수
int main(){
    ios::sync_with_stdio(0); cin.tie();
    int N, K; cin>>N>>K;
    int temp=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(a%2) temp++;
        else v.push_back(temp), temp=0;
    }
    if(v.size()==0){
        cout << "0\n";
        return 0;
    }
    if(v.size()==1){
        cout << "1\n";
        return 0;
    }
    int l=0, r=2; // l~r의 홀수 개수는 항상 K보다 작거나 같음을 보장.
    int cnt=v[1]; // 홀수 개수
    for(;r<v.size();++r){
        if(cnt+v[r]>K){
            break;
        }
        cnt+=v[r];
    }
    int res=r-l;
    while(l<v.size()){
        if(l>=r-1){
            l++;
            r++;
            cnt=0;
            continue;
        }
        l++;
        cnt-=v[l];
        for(;r<v.size();++r){
            if(cnt+v[r]>K){
                break;
            }
            cnt+=v[r];
        }
        res=max(res,r-l);
    }

    cout << res << '\n';
}