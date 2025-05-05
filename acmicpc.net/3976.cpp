#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        int l1, l2, s1, s2; cin>>l1>>l2>>s1>>s2;
        vector<int> v1, v2, pass1, pass2;
        int k1=l1, k2=l2;
        for(int i=0; i<N-1; ++i){
            int a; cin>>a; pass1.push_back(a);
        }
        for(int i=0; i<N-1; ++i){
            int a; cin>>a; v1.push_back(a);
        }
        for(int i=0; i<N-1; ++i){
            int a; cin>>a; pass2.push_back(a);
        }
        for(int i=0; i<N-1; ++i){
            int a; cin>>a; v2.push_back(a);
        }
        // cout << "k1 = " << k1 << ", k2 = " << k2 << '\n';
        for(int i=0; i<N-1; ++i){
            int t1=min(k1+v1[i], k2+pass2[i]);
            int t2=min(k2+v2[i], k1+pass1[i]);
            k1=t1;
            k2=t2;
            // cout << "k1 = " << k1 << ", k2 = " << k2 << '\n';
        }
        cout << min(k1+s1, k2+s2) << '\n';
    }
}
/*
3 - 9 , 13 - 7

5 - 60 , 5 - 999

1->2 : 60, 5
2->1 : 22, 6
*/