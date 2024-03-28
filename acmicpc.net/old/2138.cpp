#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
int greedy(vector<int> v, int offset){
    int ret = offset;
    for(int i=1; i<v.size(); ++i){
        if(i==v.size()-1){
            if(v[i-1]==v[i]){
                if(v[i-1]==1) ret++;
            }
            else{
                ret=INF;
            }
        }
        else{
            if(v[i-1]==1){
                v[i-1]^=1;
                v[i]^=1;
                v[i+1]^=1;
                ret+=1;
            }
        }
    }
    return ret;
}
int main(){
    int N; cin>>N;
    string s1, s2; cin>>s1>>s2;
    vector<int> v1;
    for(int i=0; i<N; ++i){
        if(s1[i]==s2[i]) v1.push_back(0);
        else v1.push_back(1);
    }
    vector<int> v2(v1);
    v1[0]^=1;
    v1[1]^=1;
    int res=greedy(v1, 1);
    res=min(res,greedy(v2, 0));
    if(res==INF) cout << "-1\n";
    else cout << res << '\n';
}