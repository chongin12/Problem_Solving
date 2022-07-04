#include <bits/stdc++.h>
using namespace std;
int arr[100011];
struct query {
    int l, r;
    int idx;
    query(int l, int r, int idx):l(l),r(r),idx(idx){}
};
vector<query> queries;
int qres[100011];
set<int> cnt[100011];
map<int,int> m;
int n, q;
int k;
bool cmp(query a, query b){
    if(a.l/k != b.l/k){
        return a.r<b.r;
    }
    return a.l/k<b.l/k;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    k=sqrt(n);
    for(int i=1; i<=n; ++i){
        cin>>arr[i];
        m[arr[i]]=0;
    }
    for(int i=0; i<q; ++i){
        int a,b; cin>>a>>b;
        queries.push_back(query(a,b,i));
    }

    sort(queries.begin(), queries.end(), cmp);
    // for(auto it:queries) cout << it.l << ", " << it.r << '\n';
    int l=queries[0].l;
    int r=queries[0].r;
    int res=0; // cnt의 idx 위를 움직임.
    int resnum=0;
    for(int i=l; i<=r; ++i){
        cnt[m[arr[i]]].erase(arr[i]);
        m[arr[i]]++;
        cnt[m[arr[i]]].insert(arr[i]);
        if(m[arr[i]]>res) {
            res=m[arr[i]];
            resnum=arr[i];
        }
        else if(m[arr[i]]==res) {
            resnum=max(resnum, arr[i]);
        }
    }
    // for(int j=0; j<=3; ++j){
    //     cout << "j : " << j << '\n';
    //     for(auto it=cnt[j].begin(); it!=cnt[j].end(); ++it){
    //         cout << *it << '\n';
    //     }
    // }
    qres[queries[0].idx]=resnum;
    for(int i=1; i<queries.size(); ++i){
        int nl=queries[i].l;
        int nr=queries[i].r;
        int nidx=queries[i].idx;
        while(nr>r){
            ++r;
            cnt[m[arr[r]]].erase(arr[r]);
            m[arr[r]]++;
            cnt[m[arr[r]]].insert(arr[r]);
            if(m[arr[r]]>res) {
                res=m[arr[r]];
                resnum=arr[r];
            }
            else if(m[arr[r]]==res){
                resnum=max(resnum, arr[r]);
            }
        }
        while(nr<r){
            cnt[m[arr[r]]].erase(arr[r]);
            m[arr[r]]--;
            cnt[m[arr[r]]].insert(arr[r]);
            if(cnt[res].size()==0) {
                res--;
                if(res==0) continue;
            }
            resnum=0;
            for(auto it=cnt[res].begin(); it!=cnt[res].end(); ++it){
                resnum=max(resnum, *it);
            }
            --r;
        }
        while(nl<l){
            --l;
            cnt[m[arr[l]]].erase(arr[l]);
            m[arr[l]]++;
            cnt[m[arr[l]]].insert(arr[l]);
            if(m[arr[l]]>res) {
                res=m[arr[l]];
                resnum=arr[l];
            }
            else if(m[arr[l]]==res){
                resnum=max(resnum, arr[l]);
            }
        }
        while(nl>l){
            cnt[m[arr[l]]].erase(arr[l]);
            m[arr[l]]--;
            cnt[m[arr[l]]].insert(arr[l]);
            if(cnt[res].size()==0) {
                res--;
                if(res==0) continue;
            }
            resnum=0;
            for(auto it=cnt[res].begin(); it!=cnt[res].end(); ++it){
                resnum=max(resnum, *it);
            }
            ++l;
        }
        qres[nidx]=resnum;
        // for(int j=0; j<=3; ++j){
        //     cout << "j : " << j << '\n';
        //     for(auto it=cnt[j].begin(); it!=cnt[j].end(); ++it){
        //         cout << *it << '\n';
        //     }
        // }
        // cout << "qres["<<nidx<<"]="<<resnum<<'\n';
    }
    for(int i=0; i<q; ++i){
        cout << qres[i] << '\n';
    }
}