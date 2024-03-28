#include <bits/stdc++.h>
using namespace std;
int arr[51];
int N, K;
int res=0;
int bitshift[26];
void f(int k, int lev, int prev){
    if(lev>=K) {
        int cnt=0;
        for(int i=0; i<N; ++i){
            if((arr[i] & k) == arr[i]) cnt++;
        }
        res=max(res,cnt);
        return;
    }
    for(int i=prev+1; i<26; ++i){
        if(k&bitshift[i]) continue;
        f(k|bitshift[i], lev+1, i);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>K;
    if(K<5){
        cout << "0\n";
        return 0;
    }
    bitshift[0]=(1<<0);
    for(int i=1; i<26; ++i){
        bitshift[i]=(bitshift[i-1]<<1);
    }
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        int k=0;
        for(int j=0; j<str.size(); ++j){
            int r=str[j]-'a';
            k|=bitshift[r];
        }
        arr[i]=k;
    }
    int k=0;
    k|=bitshift[('a'-'a')];
    k|=bitshift[('n'-'a')];
    k|=bitshift[('t'-'a')];
    k|=bitshift[('i'-'a')];
    k|=bitshift[('c'-'a')];
    K-=5;
    f(k, 0, -1);
    cout << res << '\n';
}