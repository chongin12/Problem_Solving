#include <bits/stdc++.h>
using namespace std;
int used[26];
int arr[26];
int cur=0;
int main(){
    for(int i=0; i<26; ++i){
        arr[i]=-1;
    }
    int N, K; cin>>N>>K;
    for(int i=0; i<K; ++i){
        int a; char ch; cin>>a>>ch;
        int num=ch-'A';
        cur=(cur+a)%N;
        if(arr[cur]==num) continue;
        if(used[num]){
            cout << "!\n";
            return 0;
        }
        used[num]=1;
        if(arr[cur]!=-1){
            cout << "!\n";
            return 0;
        }
        arr[cur]=num;
    }
    for(int i=0; i<N; ++i){
        if(arr[(cur-i+N)%N]==-1) cout << "?";
        else cout << (char)(arr[(cur-i+N)%N]+'A');
    }
    cout << '\n';
}