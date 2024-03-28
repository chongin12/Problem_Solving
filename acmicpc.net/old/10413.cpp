#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
pair<vector<int>, vector<int> > SuffixArrayAndLCP(const string &str) {
    int n = str.size();
    vector<int> sa(n), pos(n), temp(n);
    for(int i=0; i<n; ++i){
        sa[i]=i;
        pos[i]=str[i];
    }
    for(int k=1; ; k<<=1){
        auto cmp = [&](int a, int b){
            if(pos[a]!=pos[b]) return pos[a]<pos[b]; // 그룹 번호가 같지 않을 때
            if(a+k<n && b+k<n) return pos[a+k]<pos[b+k]; // 같은 그룹 안에 있다면, 첫 k개가 같다는 말. 
            //같은 그룹안에 있지만 문자 개수가 k개보다 적은게 있음.
            return a>b; // 문자열 개수가 더 적은게 우선.
        };
        sort(sa.begin(), sa.end(), cmp);
        temp[0]=0;
        for(int i=1; i<n; ++i) temp[i]=temp[i-1]+cmp(sa[i-1], sa[i]); // 그룹번호 다시 정의
        for(int i=0; i<n; ++i) pos[sa[i]]=temp[i]; // 그룹번호 대입
        if(temp.back()+1==n) break; // 그룹번호가 n만큼 있다는 것은 모두 정렬된 것.
    }
    vector<int> lcp(n);
    for(int i=0, j=0; i<n; ++i, j=max(j-1,0)){
        if(pos[i]==0) continue;
        while(sa[pos[i]-1]+j<n && sa[pos[i]]+j<n && str[sa[pos[i]-1]+j] == str[sa[pos[i]]+j]) ++j;
        lcp[pos[i]]=j;
    }
    return {sa,lcp};
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        string str; cin>>str;
        vector<int> lcp = (SuffixArrayAndLCP(str).second);
        int res=0;
        for(int i=1; i<lcp.size(); ++i){
            if(lcp[i]>lcp[i-1]){
                res+=lcp[i]-lcp[i-1];
            }
        }
        cout << res << '\n';
    }
}