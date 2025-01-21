#include <bits/stdc++.h>
using namespace std;
using pci=pair<char,int>;
int main(){
    vector<string> v;
    vector<int> cur;
    for(int i=0; i<4; ++i){
        string str; cin>>str;
        v.push_back(str);
        cur.push_back(0);
    }
    int K; cin>>K;
    while(K--){
        int num, dir; 
        cin>>num>>dir;
        num--; dir=-dir;
        pci prev = {v[num][(cur[num]+2)%8],dir}; // 이전 {극, 방향}

        for(int i=num+1; i<4; ++i){
            // 현재 톱니의 9시방향 정보
            char left=v[i][(cur[i]+6)%8];
            if(prev.first==left){
                break;
            }
            int toRotateDir=-prev.second;
            prev={v[i][(cur[i]+2)%8],toRotateDir};
            cur[i]=(cur[i]+toRotateDir+8)%8;
        }
        prev={v[num][(cur[num]+6)%8],dir};
        for(int i=num-1; i>=0; --i){
            char right = v[i][(cur[i]+2)%8];
            if(prev.first==right) break;
            int toRotateDir=-prev.second;
            prev={v[i][(cur[i]+6)%8],toRotateDir};
            cur[i]=(cur[i]+toRotateDir+8)%8;
        }
        cur[num]=(cur[num]+dir+8)%8;

        // for(int i=0; i<4; ++i){
        //     cout << i+1 << " : " << cur[i] << '\n';
        // }
    }
    int res=0;
    for(int i=0; i<4; ++i){
        if(v[i][cur[i]]=='1') res+=(1<<i);
    }
    cout << res << '\n';
}