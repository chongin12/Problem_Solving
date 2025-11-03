#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; char d; cin>>N>>d;
    int cnt=0;
    for(int i=1; i<=N; ++i){
        string t=to_string(i);
        for(auto it:t){
            if(d==it) cnt++;
        }
    }
    cout << cnt << '\n';
}