#include <bits/stdc++.h>
using namespace std;
int cnt[11][11][11][11];
vector<vector<int> > v;
int arr[4]={0,};
void init(int cur, int idx){
    if(cur==4){
        //cout << arr[0]<<", "<<arr[1]<<", "<<arr[2]<<", "<<arr[3]<<'\n';
        cnt[arr[0]][arr[1]][arr[2]][arr[3]]++;
        return;
    }
    arr[cur]=v[idx][cur];
    init(cur+1, idx);
    arr[cur]=10;
    init(cur+1, idx);
}
int solve(int i, int j, int cur){
    if(cur==4){
        return cnt[arr[0]][arr[1]][arr[2]][arr[3]];
    }
    int ret=0;
    arr[cur]=v[i][cur];
    ret+=solve(i,j,cur+1);
    if(v[i][cur]!=v[j][cur]){
        arr[cur]=v[j][cur];
        ret+=solve(i,j,cur+1);

        arr[cur]=10;
        ret=solve(i,j,cur+1)-ret;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        string a; cin>>a;
        vector<int> temp;
        for(int j=0; j<4; ++j){
            temp.push_back(a[j]-'0');
        }
        v.push_back(temp);
        init(0,i);
    }
    int res=0;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            res+=solve(i, j, 0);
        }
    }
    cout << res/3 << '\n';
}