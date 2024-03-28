#include <bits/stdc++.h>
using namespace std;
string MBTI[16]={"ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP", "ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ"};
int dist(string s1, string s2){
    int res=0;
    for(int i=0; i<4; ++i) if(s1[i]!=s2[i]) res++;
    return res;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        int res=987654321;
        map<string, int> m;
        for(int i=0; i<16; ++i){
            m[MBTI[i]]=0;
        }
        for(int i=0; i<N; ++i){
            string str; cin >> str;
            m[str]++;
        }
        for(int i=0; i<16; ++i){
            if(m[MBTI[i]]>=3){
                res=0;
                break;
            }
            if(m[MBTI[i]]>=2){
                for(int j=i+1; j<16; ++j){
                    if(m[MBTI[j]]!=0) res=min(res, dist(MBTI[i], MBTI[j])*2);
                }
            }
            if(m[MBTI[i]]>=1){
                for(int j=i+1; j<16; ++j){
                    if(m[MBTI[j]]>=2){
                        res=min(res, dist(MBTI[i], MBTI[j])*2);
                    }
                    if(m[MBTI[j]]>=1){
                        for(int k=j+1; k<16; ++k){
                            if(m[MBTI[k]]>=1) res=min(res, dist(MBTI[i], MBTI[j])+dist(MBTI[i], MBTI[k])+dist(MBTI[j], MBTI[k]));
                        }
                    }
                }
            }
        }
        cout << res << '\n';
    }
}