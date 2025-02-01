#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int H, W; cin>>H>>W;
    for(int i=0; i<W; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    int res=0;
    int left=-1;
    for(int h=1; h<=H; ++h){
        // cout << "h : " << h << '\n';
        for(int w=0; w<W; ++w){
            if(v[w]>=h){
                if(left==-1) left=w;
                else{
                    for(int i=left+1; i<w; ++i){
                        // cout << "v["<<i<<"]++\n";
                        v[i]++;
                        res++;
                    }
                    left=w;
                }
            }
        }
    }
    cout << res << '\n';
}