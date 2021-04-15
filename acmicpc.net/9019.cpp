#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
struct node {
    int n;
    string command;
    node(int n, string v) : n(n), command(v){};
};
int D(int n){
    int k = n*2;
    return k%10000;
}
int S(int n){
    int k = n+10000-1;
    return k%10000;
}
int L(int n){
    int k = n*10;
    k+=k/10000;
    return k%10000;
}
int R(int n){
    int k = n%10;
    k=k*1000+n/10;
    return k%10000;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        queue<node> q;
        int visit[10000] = {};
        int A, B; cin >> A >> B;
        q.push(node(A, ""));
        visit[A] = 1;
        while(!q.empty()) {
            node temp = q.front();
            q.pop();
            if(temp.n == B){
                cout << temp.command << '\n';
                break;
            }
            else {
                // 만약 안되면 command의 가장 마지막 부분이랑 상반되는거 빼고 집어넣기
                if(!visit[D(temp.n)]) {
                    visit[D(temp.n)]=1;
                    string dv = temp.command;
                    dv.push_back('D');
                    q.push(node(D(temp.n), dv));
                }

                if(!visit[S(temp.n)]) {
                    visit[S(temp.n)]=1;
                    string sv = temp.command;
                    sv.push_back('S');
                    q.push(node(S(temp.n), sv));
                }

                if(!visit[L(temp.n)]) {
                    visit[L(temp.n)]=1;
                    string lv = temp.command;
                    lv.push_back('L');
                    q.push(node(L(temp.n), lv));
                }
                
                if(!visit[R(temp.n)]) {
                    visit[R(temp.n)]=1;
                    string rv = temp.command;
                    rv.push_back('R');
                    q.push(node(R(temp.n), rv));
                }
                
            }
        }
    }
}