#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool isEnd() {
    for(auto it:v){
        if(it!=0) return false;
    }
    return true;
}
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    int res=0;
    while(!isEnd()){
        for(auto &it:v){
            if(it%2) {
                res++;
                it-=1;
            }
        }
        bool flag=false;
        for(auto &it:v){
            if(it>0) {
                flag=true;
                it/=2;
            }
        }
        if(flag) res++;
    }
    cout << res << '\n';
}