#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    queue<int> q;
    vector<int> v, qv;
    int res=0;
    for(int i=0; i<str.size(); ++i){
        auto it=str[i];
        if(it=='A') v.push_back(i);
        else if(it=='B') q.push(i);
        else {
            if(!q.empty()){
                q.pop();
                res++;
            }
        }
    }
    while(!q.empty()){
        qv.push_back(q.front());
        q.pop();
    }
    for(int i=v.size()-1; i>=0; --i){
        if(!qv.empty() && v[i]<qv.back()){
            res++;
            qv.pop_back();
        }
    }
    cout << res << '\n';
}