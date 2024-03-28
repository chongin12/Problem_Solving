#include <bits/stdc++.h>
using namespace std;
struct node {
    int command; // type : 1 , undo : 2
    char ch;
    int time;
    int undoTime;
    node(int command, char ch, int time, int undoTime):command(command),ch(ch),time(time),undoTime(undoTime){}
};
string res="";
vector<node> v;
bool toggle[51];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int T=0; T<N; ++T){
        toggle[T]=true;
        string str; cin>>str;
        if(str[0]=='t'){
            char ch; cin>>ch;
            int t; cin>>t;
            v.push_back(node(1,ch,t,0));
        }
        else{
            int c, t; cin>>c>>t;
            v.push_back(node(2,0,t,c));
        }
    }
    for(int i=N-1; i>=0; --i){
        if(!toggle[i]) continue;
        if(v[i].command==2){
            for(int j=i-1; j>=0; --j){
                if(v[j].time<v[i].time-v[i].undoTime) break;
                toggle[j]=!toggle[j];
            }
        }
    }
    for(int i=0; i<N; ++i){
        if(toggle[i] && v[i].command==1) res+=v[i].ch;
    }
    cout << res << '\n';
}