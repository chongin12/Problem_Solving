#include <bits/stdc++.h>
using namespace std;
struct stu {
    int q,w,e,idx, total=0;
    stu(int q, int w, int e, int idx):q(q),w(w),e(e),idx(idx){}
    stu(int idx):q(0),w(0),e(0),idx(idx){}
    void up(int a){
        if(a==3) q+=1;
        else if(a==2) w+=1;
        else e+=1;
        total+=a;
    }
};
int main(){
    int N; cin>>N;
    stu stus[3] = {stu(0), stu(1), stu(2)};
    for(int i=0; i<N; ++i){
        int a,b,c; cin>>a>>b>>c;
        stus[0].up(a);
        stus[1].up(b);
        stus[2].up(c);
    }
    bool flag=false;
    stu k=stus[0];
    for(int i=1; i<3; ++i){
        if(stus[i].total > k.total) {
            k=stus[i];
            flag=false;
        }
        else if(stus[i].total == k.total) {
            if(stus[i].q > k.q){
                k=stus[i];
                flag=false;
            }
            else if(stus[i].q==k.q){
                if(stus[i].w > k.w){
                    k=stus[i];
                    flag=false;
                }
                else if(stus[i].w == k.w){
                    flag=true;
                }
            }
        }
    }
    if(flag){
        cout << "0 " << k.total << '\n';
    }
    else{
        cout << k.idx+1 << " " << k.total << '\n';
    }
}