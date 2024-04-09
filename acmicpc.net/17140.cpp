#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int arr[101][101];
int R=3, C=3;
void opR(){
    int newC=0;
    for(int i=0; i<R; ++i){
        int temp[101]={0,};
        for(int j=0; j<C; ++j){
            temp[arr[i][j]]++;
        }
        vector<pii> v; // {등장 횟수, 그 수}
        for(int j=1; j<=100; ++j){
            if(temp[j]){
                v.push_back({temp[j], j});
            }
        }
        sort(v.begin(), v.end());
        for(int j=0; j<101; ++j){
            arr[i][j]=0;
        }
        for(int j=0; j<v.size(); ++j){
            arr[i][j*2]=v[j].second;
            arr[i][j*2+1]=v[j].first;
        }
        newC=max(newC, (int)v.size()*2);
    }
    C=newC;
}
void opC(){
    int newR=0;
    for(int i=0; i<C; ++i){
        int temp[101]={0,};
        for(int j=0; j<R; ++j){
            temp[arr[j][i]]++;
        }
        vector<pii> v; // {등장 횟수, 그 수}
        for(int j=1; j<=100; ++j){
            if(temp[j]){
                v.push_back({temp[j], j});
            }
        }
        sort(v.begin(), v.end());
        for(int j=0; j<101; ++j){
            arr[j][i]=0;
        }
        for(int j=0; j<v.size(); ++j){
            arr[j*2][i]=v[j].second;
            arr[j*2+1][i]=v[j].first;
        }
        newR=max(newR, (int)v.size()*2);
    }
    R=newR;
}
int main(){
    int r, c, k; cin>>r>>c>>k;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            cin>>arr[i][j];
        }
    }
    for(int t=0; t<=100; ++t){
        if(arr[r-1][c-1]==k){
            cout << t << '\n';
            return 0;
        }
        if(R>=C) {
            opR();
        }
        else {
            opC();
        }
    }
    cout << "-1\n";
}