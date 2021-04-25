#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<pair<string, string> > v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i=0; i<N; ++i){
        string str1, str2; cin >> str1 >> str2;
        v.push_back({str1, str2});
    }
    sort(v.begin(), v.end(), [](pair<string,string> a, pair<string,string> b) {
        return a.first<b.first;
    });
    while(M--){
        string str; cin >> str;
        int s=0, l=N;
        while(s<=l) {
            int mid = (s+l)/2;
            if(v[mid].first == str) {
                cout << v[mid].second << '\n';
                break;
            }
            if(v[mid].first < str) s=mid+1;
            else l=mid-1;
        }
    }
}