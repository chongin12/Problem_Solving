#include <bits/stdc++.h>
using namespace std;
int res=0;
int N;
vector<int> v;
void f(int cnt, int visited[]){
    if(cnt>N) {
        vector<int> arr(N);
        for(int i=0; i<N; ++i){
            arr[visited[i]-1]=v[i];
        }
        int temp=0;
        int tempres=0;
        for(int i=0; i<N; ++i){
            temp+=arr[i];
            if(temp==50) {
                int x=0, y=i+1;
                int vx=0, vy=0;
                while(x<=i && y<N){
                    if(vx==vy){
                        tempres++;
                        vx+=arr[++x];
                        vy+=arr[++y];
                    }
                    else if(vx>vy){
                        vy+=arr[++y];
                    }
                    else{
                        vx+=arr[++x];
                    }
                }
                break;
            }
        }
        res=max(res,tempres);
    }
    for(int i=0; i<v.size(); ++i){
        if(visited[i]) continue;
        visited[i]=cnt;
        f(cnt+1, visited);
        visited[i]=0;
    }
}
int main(){
    cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    int visited[8]={};
    f(1, visited);
    cout << res << '\n';
}