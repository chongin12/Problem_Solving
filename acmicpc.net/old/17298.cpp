#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<int> v(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    vector<int> st;
    vector<int> res(N);
    for(int i=N-1; i>=0; --i){
        while(!st.empty() && st.back()<=v[i]) st.pop_back();
        res[i]=st.empty()?-1:st.back();
        st.push_back(v[i]);
    }
    for(int i=0; i<N; ++i){
        cout << res[i] << " ";
    }
    cout << '\n';
}