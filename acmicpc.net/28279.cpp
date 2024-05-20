#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    deque<int> dq;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(a==1){
            int X; cin>>X;
            dq.push_front(X);
        } else if(a==2){
            int X; cin>>X;
            dq.push_back(X);
        } else if(a==3){
            if(dq.empty()){
                cout << "-1\n";
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if(a==4){
            if(dq.empty()){
                cout << "-1\n";
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if(a==5){
            cout << dq.size() << '\n';
        } else if(a==6){
            cout << dq.empty() << '\n';
        } else if(a==7){
            if(dq.empty()){
                cout << "-1\n";
            } else {
                cout << dq.front() << '\n';
            }
        } else {
            if(dq.empty()){
                cout << "-1\n";
            } else {
                cout << dq.back() << '\n';
            }
        }
    }
}