#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int main(){
    int N,M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    bool flag=false;
    int temp=0;
    for(int i=0; i<N; ++i){
        int cnt=1;
        for(int j=1; j<M; ++j){
            if(v[i][j]=='#' && v[i][j-1]=='#') {
                cnt++;
            }
        }
        if(cnt<=1) continue;
        if(!flag) {
            temp=cnt;
            flag=true;
        }
        else {
            if(temp!=cnt){
                if(temp<cnt) {
                    cout << "UP\n";
                }
                else {
                    cout << "DOWN\n";
                }
                return 0;
            }
        }
    }
    temp=0;
    flag=false;
    for(int i=0; i<M; ++i){
        int cnt=1;
        for(int j=1; j<N; ++j){
            if(v[j][i]=='#' && v[j-1][i]=='#'){
                cnt++;
            }
        }
        if(cnt<=1) continue;
        if(!flag) {
            temp=cnt;
            flag=true;
        }
        else {
            if(temp!=cnt){
                if(temp<cnt) {
                    cout << "LEFT\n";
                }
                else {
                    cout << "RIGHT\n";
                }
                return 0;
            }
        }
    }
}