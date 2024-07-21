#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int ch; cin>>ch;
        if(ch==1) {
            int X; cin>>X;
            v.push_back(X);
        } else if(ch==2){
            if(v.empty()) cout << "-1\n";
            else {
                cout << v.back() << '\n';
                v.pop_back();
            }
        } else if(ch==3){
            cout << v.size() << '\n';
        } else if(ch==4){
            cout << (v.empty() ? "1" : "0") << '\n';
        } else {
            if(v.empty()) cout << "-1\n";
            else {
                cout << v.back() << '\n';
            }
        }
    }
}