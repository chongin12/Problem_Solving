#include <bits/stdc++.h>
using namespace std;
vector<string> v;
set<string> res;
int visited[5][5];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int p[7];
void init(){
    for(int i=0; i<7; ++i){
        p[i]=i;
    }
}
int Find(int x){
    if(p[x]==x) return x;
    return p[x]=Find(p[x]);
}
void Union(int x, int y){
    int X = Find(x);
    int Y = Find(y);
    p[X]=Y;
}
int main(){
    vector<int> c;
    for(int i=0; i<5; ++i){
        string s; cin>>s; v.push_back(s);
    }
    for(int i=0; i<25; ++i) {
        c.push_back(0);
    }
    for(int i=18; i<25; ++i){
        c[i]=1;
    }
    int res=0;
    do {
        init();
        int temp[25]={0,};
        vector<int> nums;
        for(int i=0; i<c.size(); ++i){
            if(c[i]==1) {
                nums.push_back(i);
                temp[i]=1;
            }
        }
        bool flag=true;
        int accS=0;
        int accY=0;
        for(int i=0; i<nums.size(); ++i){
            int px1=nums[i]/5, py1=nums[i]%5;
            if(v[px1][py1]=='S') accS++;
            else accY++;
            if(accY>=4) break;
            for(int j=i+1; j<nums.size(); ++j){
                int px2=nums[j]/5, py2=nums[j]%5;
                if(px1==px2 && abs(py1-py2)==1){
                    Union(i, j);
                }
                else if(py1==py2 && abs(px1-px2)==1){
                    Union(i, j);
                }
            }
        }
        if(accS<4) continue;
        for(int i=1; i<7; ++i){
            if(Find(i)!=Find(0)) break;
            if(i==6){
                res++;
            }
        }
    } while(next_permutation(c.begin(), c.end()));
    cout << res << '\n';
}