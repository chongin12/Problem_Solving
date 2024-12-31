#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
    int T; cin>>T;
    while(T--){
        int N, M, R, C, S; cin>>N>>M>>R>>C>>S;
        pii up(max(1,R-S),C),left(R,max(1,C-S)),right(R,min(M,C+S)),down(min(N,R+S),C); 
        if((up.first==1 && left.second==1) || (down.first==N && right.second==M) || (up.first==1 && down.first==N) || (left.second==1 && right.second==M)){
            cout << "Tuzik\n";
        }
        else {
            cout << "Barsik\n";
        }
    }
}