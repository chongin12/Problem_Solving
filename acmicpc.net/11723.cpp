#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    set<int> s;
    string str;
    int M; cin >> M;
    while(M--){
        cin >> str;
        if(str=="add"){
            int n; cin >> n;
            s.insert(n);
        } else if(str=="remove"){
            int n; cin >> n;
            s.erase(n);
        } else if(str=="check"){
            int n; cin >> n;
            if(s.find(n)!=s.end()) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if(str=="toggle"){
            int n; cin >> n;
            if(s.find(n)!=s.end()) s.erase(n);
            else s.insert(n);
        } else if(str=="all"){
            s = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        } else {
            s = {};
        }
    }
}