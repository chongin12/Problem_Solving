#include <bits/stdc++.h>
using namespace std;
int patterns[2001][2001];
struct Trie1 {
    Trie1 * go[2];
    Trie1 * fail;
    bool chk;
    int pattern;

    Trie1() {
        fill(go, go+2, nullptr);
        fail = nullptr;
        chk=false;
        pattern=0;
    }
    ~Trie1() {
        for(int i=0; i<2; ++i){
            if(go[i]) delete go[i];
        }
    }
    void insert(const char * key, int targetPattern) {
        if(*key=='\0'){
            chk=true;
            pattern = targetPattern;
            return;
        }
        int idx;
        if(*key == 'o') idx=0;
        else idx=1;
        if(!go[idx]) {
            go[idx] = new Trie1();
        }
        go[idx]->insert(key+1, targetPattern);
    }
};
int kmp(vector<int> src, vector<int> targetPattern){
    // pi 구하기
    int targetPatternSize = targetPattern.size();
    int tempIdx=0;
    vector<int> pi(targetPatternSize, 0);
    for(int i=1; i<targetPatternSize; ++i){
        while(tempIdx>0 && targetPattern[i] != targetPattern[tempIdx]){
            tempIdx = pi[tempIdx-1];
        }
        if(targetPattern[i] == targetPattern[tempIdx]){
            pi[i] = ++tempIdx;
        }
    }

    int ret=0;

    // 패턴 매칭 수행
    int srcSize = src.size();
    tempIdx=0;
    for(int i=0; i<srcSize; ++i){
        while(tempIdx>0 && src[i] != targetPattern[tempIdx]){
            tempIdx = pi[tempIdx-1];
        }
        if(src[i] == targetPattern[tempIdx]){
            if(tempIdx == targetPatternSize-1) {
                ret++;
                tempIdx = pi[tempIdx];
            }
            else {
                tempIdx++;
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int hp, wp, hm, wm; cin>>hp>>wp>>hm>>wm;
    Trie1 * root = new Trie1();
    map<string, int> m;
    int cnt=0;
    vector<int> targetPattern;
    for(int i=0; i<hp; ++i){
        string str; cin>>str;
        if(!m[str]) {
            m[str]=++cnt;
            root->insert(str.c_str(), cnt);
        }
        targetPattern.push_back(m[str]);
    }

    root->fail = root;
    queue<Trie1 *> q;
    q.push(root);
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<2; ++i){
            auto nxt = cur->go[i];
            if(!nxt) continue;
            if(cur == root) {
                nxt->fail = root;
            }
            else {
                auto dest = cur->fail;
                while(dest != root && !dest->go[i]){
                    dest=dest->fail;
                }
                if(dest->go[i]) dest=dest->go[i];
                nxt->fail = dest;
            }
            if(nxt->fail->chk) {
                nxt->chk = true;
                nxt->pattern = nxt->fail->pattern;
            }
            q.push(nxt);
        }
    }
    
    for(int i=0; i<hm; ++i){
        string str; cin>>str;
        Trie1 * current = root;
        for(int j=0; j<wm; ++j){
            int idx;
            if(str[j]=='o') idx=0;
            else idx=1;
            
            while(current!=root && !current->go[idx]){
                current = current->fail;
            }
            if(current->go[idx]){
                current = current->go[idx];
            }
            if(current->chk) {
                patterns[i][j]=current->pattern;
            }
            else {
                patterns[i][j]=0;
            }
        }
    }

    // for(int i=0; i<hm; ++i){
    //     for(int j=0; j<wm; ++j){
    //         cout << patterns[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    //kmp로 찾기
    

    int res=0;

    for(int j=0; j<wm; ++j){
        vector<int> src;
        for(int i=0; i<hm; ++i){
            src.push_back(patterns[i][j]);
        }

        // src에서 targetPattern을 찾기
        res+=kmp(src, targetPattern);
    }
    cout << res << '\n';
}