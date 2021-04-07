#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;
int visit[MAX + 1001];
int main(){
    int N, K; cin >> N >> K;
    queue<pair<int, int> > q;
    visit[N]=1;
    q.push({N, 0});
    while(!q.empty()){
        pair<int, int> t = q.front();
        q.pop();
        if(t.first == K){
            cout << t.second << '\n';
            return 0;
        }
        if(t.first+1<=MAX && !visit[t.first+1]) {
            q.push({t.first+1, t.second+1});
            visit[t.first+1] = 1;
        }
        if(t.first-1>=0 && !visit[t.first-1]) {
            q.push({t.first-1, t.second+1});
            visit[t.first-1] = 1;
        }
        if(t.first*2<=MAX+1000 && !visit[t.first*2]) {
            q.push({t.first*2, t.second+1});
            visit[t.first*2]=1;
        }
    }
}