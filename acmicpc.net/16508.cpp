#include <bits/stdc++.h>
using namespace std;
int arr[16][26];
int res[26];
int C[16];
string W[16];
int visited[16];
int r=987654321;
int T;
void f(int t, int phase, int prev){
    if(t==phase) {
        int cnt=0;
        vector<int> temp(26, 0);
        for(int i=0; i<T; ++i){
            if(visited[i]){
                cnt+=C[i];
                for(int j=0; j<26; ++j){
                    temp[j]+=arr[i][j];
                }
            }
        }
        for(int i=0; i<26; ++i){
            if(res[i]>temp[i]) return;
        }
        r=min(r,cnt);
        return;
    }
    for(int i=prev+1; i<T; ++i){
        if(visited[i]) continue;
        visited[i]=1;
        f(t, phase+1, i);
        visited[i]=0;
    }
}
int main(){
    string str; cin>>str;
    for(auto it:str){
        res[it-'A']++;
    }
    cin>>T;
    for(int i=0; i<T; ++i){
        cin>>C[i]>>W[i];
        for(auto it:W[i]){
            arr[i][it-'A']++;
        }
    }
    for(int i=1; i<=min(T,int(str.size())); ++i){
        f(i, 0, -1);
    }
    if(r==987654321){
        cout << "-1\n";
    }
    else {
        cout << r << '\n';
    }
}