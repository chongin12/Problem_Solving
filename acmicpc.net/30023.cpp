#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int tmp[100001];
int N; 
void init(){
    for(int i=0; i<N; ++i){
        tmp[i]=arr[i];
    }
}
int main(){
    cin>>N;
    string str; cin>>str;
    for(int i=0; i<N; ++i){
        if(str[i]=='R') arr[i]=0;
        else if(str[i]=='G') arr[i]=1;
        else arr[i]=2;
    }
    int res=987654321;
    for(int target=0; target<3; ++target){
        init();
        int cnt=0;
        for(int i=0; i<N-2; ++i){
            if(tmp[i]!=target){
                cnt++;
                tmp[i]=(tmp[i]+1)%3;
                tmp[i+1]=(tmp[i+1]+1)%3;
                tmp[i+2]=(tmp[i+2]+1)%3;
                --i;
                continue;
            }
        }
        if(tmp[N-2]==tmp[N-1] && tmp[N-1]==target) res=min(res,cnt);
    }
    if(res==987654321) cout << "-1\n";
    else cout << res << '\n';
}