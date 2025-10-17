#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<string> v;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        string t;
        for(auto it:str){
            if(it>='0' && it<='9'){
                if(t=="0"){
                    t.clear();
                }
                t+=it;
            }
            else{
                if(!t.empty()){
                    v.push_back(t);
                }
                t.clear();
            }
        }
        if(!t.empty()) v.push_back(t);
    }
    sort(v.begin(), v.end(), [](string a, string b){
        if(a.size()==b.size()) return a<b;
        return a.size()<b.size();
    });
    for(auto it:v){
        cout << it << '\n';
    }
}