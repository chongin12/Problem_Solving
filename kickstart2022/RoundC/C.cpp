#include <bits/stdc++.h>
using namespace std;
struct path {
    int p, d, ant, id;
    path(int p, int d, int ant, int id):p(p),d(d),ant(ant),id(id){}
    bool operator<(path a){
        return p < a.p;
    }
};
int dist(int L, int p, int d){
    if(d==0){
        return p;
    }
    else{
        return L-p;
    }
}
vector<path> v; // 남은 거리 기준
vector<path> v2; // 포지션 기준
vector<path> paths;
bool visited[100001]={0,};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        memset(visited, 0, sizeof(visited));
        v.clear();
        v2.clear();
        paths.clear();
        int N, L; cin>>N>>L;
        for(int i=0; i<N; ++i){
            int p,d; cin>>p>>d;
            v.push_back(path(p,d,i+1,i));
            v2.push_back(path(p,d,i+1,i));
            paths.push_back(path(p,d,i+1,i));
        }
        sort(v.begin(), v.end(), [&](path a, path b){
            return dist(L,a.p,a.d)<dist(L,b.p,b.d);
        });
        sort(v2.begin(), v2.end(), [](path a, path b){
            return a.p<b.p;
        });
        vector<pair<int,int> > res;
        for(int i=0; i<v.size(); ++i){
            int pos = lower_bound(v2.begin(), v2.end(), v[i])-v2.begin();
            int curid=v[i].id;
            if(v[i].d==0){
                for(int j=pos; j>=0; --j){
                    int targetId=v2[j].id;
                    if(visited[targetId]) continue;
                    int temp = paths[curid].ant;
                    paths[curid].ant = paths[targetId].ant;
                    paths[targetId].ant = temp;
                }
            }
            else{
                for(int j=pos; j<v.size(); ++j){
                    int targetId=v2[j].id;
                    if(visited[targetId]) continue;
                    int temp = paths[curid].ant;
                    paths[curid].ant = paths[targetId].ant;
                    paths[targetId].ant = temp;
                }
            }
            visited[curid]=1;
            res.push_back({paths[curid].ant, dist(L,paths[curid].p,paths[curid].d)});
        }
        sort(res.begin(), res.end(), [](pair<int,int> a, pair<int,int> b){
            if(a.second==b.second) return a.first<b.first;
            return a.second<b.second;
        });
        cout << "Case #"<<t<<": ";
        for(int i=0; i<res.size(); ++i){
            cout << res[i].first << ' ';
        }
        cout << '\n';
    }
}