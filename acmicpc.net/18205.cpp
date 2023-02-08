#include <bits/stdc++.h>
using namespace std;
vector<int> v(10011);
vector<vector<int> > idx(10011);
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N,M; cin>>N>>M;
    vector<pair<int,int> > V;
    for(int i=0; i<N; ++i){
        int k=0;
        string str; cin>>str;
        k=str[0]-'0';
        for(int j=2; j<str.size(); ++j){
            k=k*10+str[j]-'0';
        }
        V.push_back({k,i});
    }
    sort(V.begin(), V.end());
    int k=0;
    for(int i=0; i<V.size(); ++i){
        if(i && V[i].first != V[i-1].first){
            ++k;
        }
        v[V[i].second]=k;
        idx[k].push_back(V[i].second);
    }
    sort(idx.begin(), idx.end(), [](const vector<int> &a, const vector<int> &b){
        return a.size()>b.size();
    });
    while(M--){
        int l, r; cin>>l>>r; l--, r--;
        int goal = (r-l+1)/2+1;
        bool pass=false;
        for(int i=0; i<10011; ++i){
            if(idx[i].size()<goal) break;
            if(upper_bound(idx[i].begin(), idx[i].end(), r)-lower_bound(idx[i].begin(), idx[i].end(), l)>=goal){
                pass=true;
                break;
            }
        }
        if(pass){
            cout << "usable\n";
        }
        else{
            cout << "unusable\n";
        }
    }
}