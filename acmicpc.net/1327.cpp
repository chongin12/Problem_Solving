#include <bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
    int K,N; cin>>N>>K;
    string str="";
    for(int i=0; i<N; ++i){
        char ch; cin>>ch;
        str+=ch;
    }
    string goal=str;
    sort(goal.begin(), goal.end());
    queue<pair<string,int> > q;
    q.push({str,0});
    s.insert(str);
    while(!q.empty()){
        pair<string,int> cur=q.front(); q.pop();
        if(cur.first==goal){
            cout << cur.second << '\n';
            return 0;
        }
        for(int i=0; i<=N-K; ++i){
            // i, i+1, i+2, ... i+K-1 순서 바꾸기
            string newStr=cur.first;
            for(int j=0; j<K/2; ++j){
                char temp=newStr[i+j];
                newStr[i+j]=newStr[i+K-1-j];
                newStr[i+K-1-j]=temp;
            }
            if(s.find(newStr)==s.end()){
                s.insert(newStr);
                q.push({newStr, cur.second+1});
            }
        }
    }
    cout << "-1\n";
}