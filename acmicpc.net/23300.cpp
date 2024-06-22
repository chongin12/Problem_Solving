#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int now = -1;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin>>N>>Q;
    deque<pii> back, front;
    while(Q--){
        char ch; cin>>ch;
        if(ch=='B'){
            if(back.size()==0) continue;
            auto content = back.back();
            if(now!=-1) {
                if(front.empty() || front.front().first != now) {
                    front.push_front({now, 1});
                }
                else {
                    front.front().second++;
                }
            }
            now = content.first;
            if(content.second>1){
                back.back().second--;
            }
            else {
                back.pop_back();
            }
        }
        else if(ch=='F'){
            if(front.size()==0) continue;
            auto content = front.front();
            if(now!=-1) {
                if(back.empty() || back.back().first != now) {
                    back.push_back({now, 1});
                }
                else {
                    back.back().second++;
                }
            }
            now = content.first;
            if(content.second>1){
                front.front().second--;
            }
            else {
                front.pop_front();
            }
        }
        else if(ch=='A'){
            front.clear();
            if(now!=-1){
                if(back.empty() || back.back().first != now) {
                    back.push_back({now, 1});
                }
                else {
                    back.back().second++;
                }
            }
            cin>>now;
        }
        else {
            for(int i=0; i<back.size(); ++i){
                back[i].second = 1;
            }
        }
    }
    cout << now << '\n';
    reverse(back.begin(), back.end());
    if(back.size()==0) cout << "-1";
    else for(auto it:back) for(int i=0; i<it.second; ++i) cout << it.first << " ";
    cout << '\n';
    if(front.size()==0) cout << "-1";
    else for(auto it:front) for(int i=0; i<it.second; ++i) cout << it.first << " ";
    cout << '\n';
}