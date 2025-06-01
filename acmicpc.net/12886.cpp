#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y, z;
};
bool visited[1501][1501];
Node sortOf(Node a){
    int x=min({a.x, a.y, a.z});
    int z=max({a.x, a.y, a.z});
    int y=a.x+a.y+a.z-x-z;
    return {x,y,z};
}
queue<Node> q;
int main(){
    int A, B, C; cin>>A>>B>>C;
    Node s=sortOf({A,B,C});
    q.push(s);
    visited[s.x][s.y]=true;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int a=cur.x, b=cur.y, c=cur.z;
        // cout << "a="<<a<<", b="<<b<<", c="<<c<<'\n';
        if(a==b && b==c){
            cout << "1\n";
            return 0;
        }
        Node s1=sortOf({a*2,b-a,c});
        Node s2=sortOf({a*2,b,c-a});
        Node s3=sortOf({a,b*2,c-b});

        if(!visited[s1.x][s1.y]){
            visited[s1.x][s1.y]=true;
            q.push(s1);
        }
        if(!visited[s2.x][s2.y]){
            visited[s2.x][s2.y]=true;
            q.push(s2);
        }
        if(!visited[s3.x][s3.y]){
            visited[s3.x][s3.y]=true;
            q.push(s3);
        }
    }
    cout << "0\n";
}