#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int ori[100001];
struct query {
    int l, r;
    int idx;
    query(int l, int r, int idx):l(l),r(r),idx(idx){}
};
vector<query> queries;
int qres[100001];
set<int> cnt[100001];
int n, q;
int k;
int acc[100001];
bool cmp(query a, query b){
    if(a.l/k != b.l/k){
        return a.l<b.l;
    }
    return a.r<b.r;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    k=sqrt(n);
    vector<pair<int,int> > temp;
    for(int i=1; i<=n; ++i){
        int a; cin>>a;
        temp.push_back({a,i});
    }
    sort(temp.begin(), temp.end());
    int tempn=1;
    arr[temp[0].second]=tempn;
    for(int i=1; i<n; ++i){
        if(temp[i-1].first!=temp[i].first) tempn+=1;
        arr[temp[i].second]=tempn;
        ori[tempn]=temp[i].first;
    }
    for(int i=0; i<q; ++i){
        int a,b; cin>>a>>b;
        queries.push_back(query(a,b,i));
    }

    sort(queries.begin(), queries.end(), cmp);
    int l=queries[0].l;
    int r=queries[0].r;
    int res=0; // cnt의 idx 위를 움직임.
    int resnum=0;
    for(int i=1; i<=100000; ++i){
        cnt[0].insert(i);
    }
    for(int i=l; i<=r; ++i){
        cnt[acc[arr[i]]].erase(arr[i]);
        acc[arr[i]]++;
        cnt[acc[arr[i]]].insert(arr[i]);
        if(acc[arr[i]]>res) {
            res=acc[arr[i]];
            resnum=arr[i];
        }
        else if(acc[arr[i]]==res) {
            resnum=max(resnum, arr[i]);
        }
    }
    qres[queries[0].idx]=resnum;
    for(int i=1; i<queries.size(); ++i){
        int nl=queries[i].l;
        int nr=queries[i].r;
        int nidx=queries[i].idx;
        while(nl<l){
            --l;
            cnt[acc[arr[l]]].erase(arr[l]);
            acc[arr[l]]++;
            cnt[acc[arr[l]]].insert(arr[l]);
            if(acc[arr[l]]>res) {
                res=acc[arr[l]];
                resnum=arr[l];
            }
            else if(acc[arr[l]]==res){
                resnum=max(resnum, arr[l]);
            }
        }
        while(nl>l){
            cnt[acc[arr[l]]].erase(arr[l]);
            acc[arr[l]]--;
            cnt[acc[arr[l]]].insert(arr[l]);
            if(cnt[res].size()==0) {
                res--;
                resnum=0;
                if(res==0) continue;
            }
            for(auto it=cnt[res].begin(); it!=cnt[res].end(); ++it){
                resnum=max(resnum, *it);
            }
            ++l;
        }
        while(nr>r){
            ++r;
            cnt[acc[arr[r]]].erase(arr[r]);
            acc[arr[r]]++;
            cnt[acc[arr[r]]].insert(arr[r]);
            if(acc[arr[r]]>res) {
                res=acc[arr[r]];
                resnum=arr[r];
            }
            else if(acc[arr[r]]==res){
                resnum=max(resnum, arr[r]);
            }
        }
        while(nr<r){
            cnt[acc[arr[r]]].erase(arr[r]);
            acc[arr[r]]--;
            cnt[acc[arr[r]]].insert(arr[r]);
            if(cnt[res].size()==0) {
                res--;
                resnum=0;
                if(res==0) continue;
            }
            for(auto it=cnt[res].begin(); it!=cnt[res].end(); ++it){
                resnum=max(resnum, *it);
            }
            --r;
        }
        qres[nidx]=resnum;
    }
    for(int i=0; i<q; ++i){
        cout << ori[qres[i]] << '\n';
    }
}