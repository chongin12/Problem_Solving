#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;
int visit[110100];
int bfs(int N, int K){
    deque<pair<int, int> > dq;
    dq.push_front({N, 0});
    visit[N] = 0;
    while(!dq.empty()) {
        pair<int, int> cur = dq.front(); dq.pop_front();
        int coor = cur.first;
        int count = cur.second;
        //cout << "coor : " << coor << ", count : " << count << '\n';
        if(coor == K) return count;
        for(int i=coor; i!=0 && i<101000; i*=2){
            if(visit[i]>count){
                dq.push_front({i, count});
                visit[i]=count;
            }
        }
        if(coor != 0 && coor > K && visit[coor-1] > count+1) {
            dq.push_back({coor-1, count+1});
            visit[coor-1]=count+1;
            continue;
        }
        if(coor != 0 && visit[coor-1] > count+1){
            dq.push_back({coor-1, count+1});
            visit[coor-1]=count+1;
        }
        if(visit[coor+1]>count+1){
            dq.push_back({coor+1, count+1});
            visit[coor+1] = count+1;
        }
    }
    return 0;
}
int main(){
    int N, K; cin >> N >> K;
    for(int i=0; i<=101000; ++i) visit[i] = INF;
    cout << bfs(N, K) << '\n';
}