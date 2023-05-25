#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        string str; cin>>str;
        string str2=str;
        reverse(str2.begin(), str2.end()); 
        int l=0,r=0;
        for(auto it:str){
            if(it=='(') l++;
            else r++;
        }
        if(l!=r){
            cout << "-1\n";
            continue;
        }
        vector<int> mask(N+1);
        vector<int> v;
        int flag=0;
        for(int i=0; i<N; ++i){
            if(v.size()==0){
                if(str[i]=='('){
                    v.push_back(i);
                }
            }
            else{
                if(str[i]=='('){
                    v.push_back(i);
                }
                else{
                    mask[i]=1;
                    mask[v.back()]=1;
                    flag=1;
                    v.pop_back();
                }
            }
        }
        int res=1;
        for(int i=0; i<N; ++i){
            if(mask[i]==0) mask[i]=flag+1;
            res=max(res,mask[i]);
        }

        vector<int> mask2(N+1);
        vector<int> v2;
        int flag2=0;
        for(int i=0; i<N; ++i){
            if(v2.size()==0){
                if(str2[i]=='('){
                    v2.push_back(i);
                }
            }
            else{
                if(str2[i]=='('){
                    v2.push_back(i);
                }
                else{
                    mask2[i]=1;
                    mask2[v2.back()]=1;
                    flag2=1;
                    v2.pop_back();
                }
            }
        }
        int res2=1;
        for(int i=0; i<N; ++i){
            if(mask2[i]==0) mask2[i]=flag2+1;
            res2=max(res2,mask2[i]);
        }


        if(res<=res2){
            cout << res << '\n';
            for(int i=0; i<N; ++i){
                cout << mask[i] << ' ';
            }
        }
        else{
            cout << res2 << '\n';
            for(int i=0; i<N; ++i){
                cout << mask2[N-i-1] << ' ';
            }
        }
        cout << '\n';
    }
}