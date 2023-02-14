#include <bits/stdc++.h>
using namespace std;
int A,B,C;
int visited[8200000];
int res[201];
queue<int> q;
int id(int a, int b, int c){
    return a*201*201+b*201+c;
}
tuple<int,int,int> ele(int k){
    int c=k%201;
    k/=201;
    int b=k%201;
    k/=201;
    int a=k;
    return {a,b,c};
}
void enqueue(int id){
    if(!visited[id]){
        visited[id]=1;
        q.push(id);
    }
}
void f(int na, int nb, int nc){
    q.push(id(na,nb,nc));
    visited[id(na,nb,nc)]=1;
    while(!q.empty()){
        auto cur=ele(q.front()); q.pop();
        int a=get<0>(cur);
        int b=get<1>(cur);
        int c=get<2>(cur);
        // cout << a << ", " << b << ", " << c << '\n';
        if(a==0) res[c]=1;
        // 1. a->b
        int temp = id(max(0,a+b-B),min(a+b,B),c);
        enqueue(temp);
        // 2. a->c
        temp = id(max(0,a+c-C),b,min(a+c,C));
        enqueue(temp);
        // 3. b->a
        temp = id(min(a+b,A),max(0,a+b-A),c);
        enqueue(temp);
        // 4. b->c
        temp = id(a,max(0,b+c-C),min(b+c,C));
        enqueue(temp);
        // 5. c->a
        temp = id(min(a+c,A),b,max(0,a+c-A));
        enqueue(temp);
        // 6. c->b
        temp = id(a,min(b+c,B),max(0,b+c-B));
        enqueue(temp);
    }
}
int main(){
    cin>>A>>B>>C;
    f(0,0,C);
    for(int i=0; i<=C; ++i){
        if(res[i]) cout << i << " ";
    }
    cout << '\n';
}