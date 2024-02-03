#include <bits/stdc++.h>
using namespace std;
string L, K;
string increment(string a){
    string ret=a;
    int spare=1;
    for(int i=a.size()-1; i>=0;--i){
        if(spare){
            if(ret[i]=='0') ret[i]='1', spare=0;
            else ret[i]='0';
        }
    }
    if(spare) ret="1"+ret;
    return ret;
}
string decrement(string a){ // 0이 오면 안됨.
    string ret=a;
    int spare=1;
    for(int i=a.size()-1; i>=0;--i){
        if(spare){
            if(ret[i]=='0') ret[i]='1';
            else ret[i]='0', spare=0;
        }
    }
    if(ret[0]=='0') ret=string(ret.begin()+1, ret.end());
    return ret;
}
int main(){
    cin>>L>>K;
    map<string, int> visited;
    queue<pair<string, int> > q;
    q.push({L,0});
    visited[L]=1;
    while(!q.empty()){
        string cur = q.front().first;
        int curCnt = q.front().second; q.pop();
        if(cur==K) {
            cout << curCnt << '\n';
            return 0;
        }
        string incremented = increment(cur);
        if(cur!="0"){
            string decremented = decrement(cur);
            if(visited[decremented]==0){
                visited[decremented]=1;
                q.push({decremented, curCnt+1});
            }
        }
        if(visited[incremented]==0){
            visited[incremented]=1;
            q.push({incremented, curCnt+1});
        }
        for(int i=cur.size()-1; i>0; --i){
            string temp = cur;
            if(temp[i]=='0') temp[i]='1';
            else temp[i]='0';
            if(visited[temp]==0){
                visited[temp]=1;
                q.push({temp, curCnt+1});
            }
        }
    }
}