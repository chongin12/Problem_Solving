#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll arr[1000001];
ll x[1000001];
bool res[30];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
    }
    for(ll B=29; B>=0; --B){
        // cout << "\nB : " << B << '\n';
        ll k=1<<(B+1);
        if(B==29){
            for(int i=1; i<=N; ++i){
                x[i]=arr[i]%k;
            }
            sort(x+1, x+1+N);
        }
        else{
            auto pos=lower_bound(x+1, x+1+N, k)-x;
            vector<ll> temp;
            int l=1, r=pos;
            while(1){
                if(l>=pos && r>N){
                    break;
                }
                else if(l>=pos){
                    temp.push_back(x[r]-k);
                    r++;
                }
                else if(r>N){
                    temp.push_back(x[l]);
                    l++;
                }
                else{
                    if(x[l]<x[r]-k){
                        temp.push_back(x[l]);
                        l++;
                    }
                    else{
                        temp.push_back(x[r]-k);
                        r++;
                    }
                }
            }
            for(int i=1; i<=N; ++i){
                x[i]=temp[i-1];
                // cout << x[i] << " ";
            }
            // cout << '\n';
        }
        int p1,p2,p3;
        for(int xpos=1; xpos<=N; ++xpos){
            // cout << "xpos : " << xpos << '\n';
            if(xpos==1){
                p1=lower_bound(x+1, x+1+N, (1<<B)-x[xpos])-x;
                p2=lower_bound(x+1, x+1+N, 2*(1<<B)-x[xpos])-x;
                p3=lower_bound(x+1, x+1+N, 3*(1<<B)-x[xpos])-x;
            }
            else{
                while(p1>xpos){
                    if(x[xpos]+x[p1-1]<(1<<B)){
                        break;
                    }
                    p1--;
                }
                while(p2>xpos){
                    if(x[xpos]+x[p2-1]<(1<<B)*2){
                        break;
                    }
                    p2--;
                }
                while(p3>xpos){
                    if(x[xpos]+x[p3-1]<(1<<B)*3){
                        break;
                    }
                    p3--;
                }
                if(p1<xpos) p1=xpos;
                if(p2<xpos) p2=xpos;
                if(p3<xpos) p3=xpos;
            }
            // cout << "p1 : " << p1 << ", p2 : " << p2 << ", p3 : " << p3 << '\n';
            int num=p2-p1+N+1-p3;
            if(num%2==1) res[B]=!res[B];
            // cout << "num : " << num << '\n';
        }
        // cout << "bit in "<< B << " : " << res[B] << '\n';
    }
    ll resnum=0;
    for(int i=0; i<30; ++i){
        if(res[i]) resnum+=1<<i;
    }
    cout << resnum << '\n';
}