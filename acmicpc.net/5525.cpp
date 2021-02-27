#include <iostream>
#include <string>
using namespace std;
int arr[1000101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N;
    cin >> M;
    string str; cin >> str;
    int stck=0; // OI가 몇개 쌓였는지 카운트
    int state=0; // 1일때 2로, 2일때 카운트 on, 아니면 I찾을때까지 0으로 대기
    for(int i=0; i<M; ++i){
        if(!state && str[i]=='I') state=1;
        else if(state==1 && str[i]=='O') state=2;
        else if(state==2 && str[i]=='I') {
            stck++;
            state=1;
        }
        else {
            if(state && stck) {
                arr[stck]++;
                //cout << "stck : " << stck << ", arr[stck] : " << arr[stck] << '\n';
                stck=0;
            }
            if(str[i]=='I') state=1;
            else state=0;
        }
    }
    if(stck) arr[stck]++;
    int res=0;
    for(int i=N; i<=1000001; ++i){
        if(arr[i]) res+=(i-N+1)*arr[i];
    }
    if(res<0) cout << 0 << '\n';
    else cout << res << '\n';
}