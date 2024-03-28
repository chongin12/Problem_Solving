#include <bits/stdc++.h>
using namespace std;
vector<int> suffixArray(string s){
    int n=s.size();
    vector<int> sa(n), rank(n+1), nextRank(n+1);
    for(int i=0; i<n; ++i){
        sa[i] = i;
        rank[i] = s[i];
    }
    for(int d=1; d<n; d<<=1){
        auto cmp = [&](int i, int j){ // [&]를 사용하면 바깥에 있는 지역변수를 사용 할 수 있음.
            return rank[i]<rank[j] || (rank[i]==rank[j] && rank[i+d]<rank[j+d]);
        }; // pair(rank[i], rank[i+d]) 과 pair(rank[j], rank[j+d]) 를 비교.
        sort(sa.begin(), sa.end(), cmp);

        nextRank[sa[0]] = 1;
        for(int i=1; i<n; ++i){
            nextRank[sa[i]] = nextRank[sa[i-1]] + cmp(sa[i-1], sa[i]);
        }
        rank = nextRank;
    }
    return sa;
}
vector<int> buildLCP(string s){
    int n = s.size();
    vector<int> sa = suffixArray(s), lcp(n), isa(n);
    for(int i=0; i<n; ++i){
        isa[sa[i]]=i;
    }
    for(int k=0, i=0; i<n; ++i){
        if(isa[i]) {
            for(int j=sa[isa[i]-1]; s[i+k]==s[j+k]; ++k);
            lcp[isa[i]] = (k ? k-- : 0);
        }
    }
    return lcp;
}
int main(){
    int n; cin>>n;
    string str; cin>>str;
    vector<int> r1 = buildLCP(str);
    int r=0;
    for(auto it:r1) r=max(r,it);
    cout << r << '\n';
}