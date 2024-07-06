#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int available[10];
vector<int> avail;
vector<int> a1, a2;
int res=0;
void f2(int phase){
    if(phase==v[1]) {
        int a=0;
        for(auto it:a1) a=a*10+it;
        int b=0;
        for(auto it:a2) b=b*10+it;
        for(int i=0; i<a2.size(); ++i){
            string a_str = to_string(a*a2[i]);
            if(a_str.size() != v[1+a2.size()-i]){
                return;
            }
            for(auto it:a_str) {
                if(available[it-'0']==0) return;
            }
        }
        string a_str = to_string(a*b);
        if(a_str.size() != v.back()){
            return;
        }
        for(auto it:a_str) {
            if(available[it-'0']==0) return;
        }
        res++;
        return;
    }
    for(auto it:avail){
        a2.push_back(it);
        f2(phase+1);
        a2.pop_back();
    }
}
void f1(int phase){
    if(phase==v[0]) {
        f2(0);
        return;
    }
    for(auto it:avail){
        a1.push_back(it);
        f1(phase+1);
        a1.pop_back();
    }
}
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    int K; cin>>K;
    for(int i=0; i<K; ++i){
        int a; cin>>a; 
        available[a]=1;
        avail.push_back(a);
    }
    f1(0);
    cout << res << '\n';
}