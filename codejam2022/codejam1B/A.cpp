#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int i=1; i<=T; ++i){
        int N; cin>>N;
        deque<int> d;
        for(int i=0; i<N; ++i){
            int a; cin>>a; d.push_back(a);
        }
        int prv=-1;
        int res=0;
        while(!d.empty()){
            if(d.size()==1){
                if(d.back()>=prv) res++;
                d.pop_back();
            }
            else{
                if(d.front()>d.back()){
                    if(d.back()>=prv) {
                        res++;
                        prv=d.back();
                    }
                    d.pop_back();
                }
                else{
                    if(d.front()>=prv) {
                        res++;
                        prv=d.front();
                    }
                    d.pop_front();
                }
            }
        }
        cout << "Case #"<<i<<": "<<res << '\n';
    }
}