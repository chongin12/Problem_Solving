#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> v;
int main(){
    int N, R; cin>>N>>R;
    for(int i=0; i<N; ++i){
        int x, y; cin>>x>>y;
        v.push_back({x,y});
    }
    int res=-1;
    int rx,ry;
    for(int x=-100; x<=100; ++x){
        for(int y=-100; y<=100; ++y){
            int cnt=0;
            for(auto it:v){
                if((it.first-x)*(it.first-x)+(it.second-y)*(it.second-y)<=R*R) cnt++;
            }
            if(cnt>res){
                res=cnt;
                rx=x, ry=y;
            }
        }
    }
    cout << rx << " " << ry << '\n';
    
}