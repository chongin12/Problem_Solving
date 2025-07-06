#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<string> v;
    for(int i=0; i<N; ++i){
        string s; cin>>s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), [](string a, string b){
        if(a.size()==b.size()){
            int r1=0, r2=0;
            for(auto it:a){
                if(it>='0' && it<='9'){
                    r1+=it-'0';
                }
            }
            for(auto it:b){
                if(it>='0' && it<='9'){
                    r2+=it-'0';
                }
            }
            if(r1==r2){
                return a<b;
            }
            else {
                return r1<r2;
            }
        }
        else {
            return a.size()<b.size();
        }
    });
    for(auto it:v){
        cout << it << '\n';
    }
}