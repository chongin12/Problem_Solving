#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<string> v;
    set<string> s;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    int res=0;
    for(int i=0; i<N; ++i){
        int flag=false;
        string t=v[i];
        for(int offset=0; offset<t.size(); ++offset){
            string tt="";
            for(int k=0; k<t.size(); ++k){
                tt+=t[(offset+k)%t.size()];
            }
            if(s.find(tt)!=s.end()){
                flag=true;
                break;
            }
        }
        if(!flag) s.insert(t);
    }
    cout << s.size() << '\n';
}