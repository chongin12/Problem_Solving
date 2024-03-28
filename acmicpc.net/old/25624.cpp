#include <bits/stdc++.h>
using namespace std;
int cnt[30];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M; cin>>N>>M;
    set<int> s[30];
    vector<string> input;
    
    for(int i=0; i<M; ++i){
        string str; cin>>str;
        input.push_back(str);
    }
    sort(input.begin(), input.end());
    bool flag=true;
    for(int i=1; i<M; ++i){
        if(input[i]==input[i-1]) flag=false;
    }
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            s[j].insert(input[i][j]-'A');
        }
    }
    int expected=1;
    vector<string> res;
    for(int i=0; i<N; ++i){
        string temp="";
        expected*=s[i].size();
        for(auto it:s[i]){
            if(cnt[it]) {
                flag=false;
                break;
            }
            else{
                cnt[it]=1;
                temp+=(it+'A');
            }
        }
        if(!flag) break;
        sort(temp.begin(), temp.end());
        res.push_back(temp);
    }
    if(expected!=M) flag=false;
    if(flag){
        cout << "YES\n";
        for(auto it:res){
            cout << it << '\n';
        }
    }
    else{
        cout << "NO\n";
    }
}