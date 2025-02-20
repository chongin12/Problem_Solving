#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
map<string, pii> m;
pii operator+ (pii a, pii b){
    return {a.first+b.first, a.second+b.second};
}
int main(){
    m["R"]={0,1};
    m["L"]={0,-1};
    m["B"]={-1,0};
    m["T"]={1,0};
    m["RT"]={1,1};
    m["LT"]={1,-1};
    m["RB"]={-1,1};
    m["LB"]={-1,-1};
    string s1, s2; cin>>s1>>s2;
    int N; cin>>N;
    pii king={0,0}, stone={0,0};
    king.second=s1[0]-'A';
    king.first=s1[1]-'1';
    stone.second=s2[0]-'A';
    stone.first=s2[1]-'1';
    for(int i=0; i<N; ++i){
        string q; cin>>q;
        int newRow = (king+m[q]).second;
        int newCol = (king+m[q]).first;
        if(newRow<0 || newRow>=8 || newCol<0 || newCol>=8){
            continue;
        }
        if((king+m[q])==stone){
            int newStoneRow = (stone+m[q]).second;
            int newStoneCol = (stone+m[q]).first;
            if(newStoneRow<0 || newStoneRow>=8 || newStoneCol<0 || newStoneCol>=8){
                continue;
            }
        }
        king=king+m[q];
        if(king==stone){
            stone=stone+m[q];
        }
    }
    cout << (char)(king.second+'A') << (char)(king.first+'1') << '\n';
    cout << (char)(stone.second+'A') << (char)(stone.first+'1') << '\n';
}