#include <bits/stdc++.h>
using namespace std;
const int note[12]={1,0,1,0,1,1,0,1,0,1,0,1};//c : 0
const char noteCh[12]={'C','.','D','.','E','F','.','G','.','A','.','B'};
int main(){
    int N; cin>>N;
    vector<int> v(N);
    vector<pair<char,char> > res;
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    for(int i=0; i<12; ++i){
        if(!note[i]) continue;
        int now=i;
        bool flag=true;
        for(int j=0; j<v.size(); ++j){
            now+=v[j]+24;
            now%=12;
            if(!note[now]){
                flag=false;
                break;
            }
        }
        if(flag){
            res.push_back({noteCh[i], noteCh[now]});
        }
    }
    sort(res.begin(), res.end());
    for(auto it:res){
        cout << it.first << ' ' << it.second << '\n';
    }
}