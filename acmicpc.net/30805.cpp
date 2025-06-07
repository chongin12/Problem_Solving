#include <bits/stdc++.h>
using namespace std;
vector<int> A,B;
int N, M; 
vector<int> operator +(vector<int> a, vector<int> b){
    vector<int> res;
    for(auto it:a) res.push_back(it);
    for(auto it:b) res.push_back(it);
    return res;
}
vector<int> f(int x, int y){
    if(x>=N || y>=M) return vector<int>();
    for(char ch=100; ch>=0; --ch){
        int chkA=-1, chkB=-1;
        for(int i=x; i<N; ++i){
            if(A[i]==ch){
                chkA=i;
                break;
            }
        }
        for(int i=y; i<M; ++i){
            if(B[i]==ch){
                chkB=i;
                break;
            }
        }
        if(chkA!=-1 && chkB!=-1){
            vector<int> temp = {A[chkA]};
            return temp + f(chkA+1, chkB+1);
        }
    }
    return vector<int>();
}
int main(){
    cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; A.push_back(a);
    }
    cin>>M;
    for(int i=0; i<M; ++i){
        int a; cin>>a; B.push_back(a);
    }
    auto res = f(0,0);
    cout << res.size() << '\n';
    for(auto it:res){
        cout << it << " ";
    }
    cout << '\n';
}