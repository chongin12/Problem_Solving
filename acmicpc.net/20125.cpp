#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        string str; cin>>str; v.push_back(str);
    }
    int heartx, hearty;
    for(int i=0; i<N-1; ++i){
        for(int j=1; j<N-1; ++j){
            if(v[i][j]=='*' && v[i+1][j-1]=='*' && v[i+1][j]=='*' && v[i+1][j+1]=='*'){
                // v[i+1][j] 가 심장
                heartx=i+1;
                hearty=j;
                break;
            }
        }
    }
    cout << heartx+1 << " " << hearty+1 << '\n';
    int len=0;
    for(int i=hearty-1; i>=0; --i){
        if(v[heartx][i]!='*') break;
        len++;
    }
    cout << len << " ";
    len=0;
    for(int i=hearty+1; i<N; ++i){
        if(v[heartx][i]!='*') break;
        len++;
    }
    cout << len << " ";
    len=0;
    for(int i=heartx+1; i<N; ++i){
        if(v[i][hearty]!='*') break;
        len++;
    }
    cout << len << " ";
    int legStart = heartx+len+1;
    len=0;
    for(int i=legStart; i<N; ++i){
        if(v[i][hearty-1]!='*') break;
        len++;
    }
    cout << len << " ";
    len=0;
    for(int i=legStart; i<N; ++i){
        if(v[i][hearty+1]!='*') break;
        len++;
    }
    cout << len << " ";
}