
#include <bits/stdc++.h>
using namespace std;
int arr[101]; // 0 : 사진 안걸려있음, i : 해당 시간에 들어옴
int vote_cnt[101]; // 추천 수
int main(){
    int N; cin>>N;
    int a; cin>>a;
    for(int t=1; t<=a; ++t){
        int num; cin>>num;
        // 0. 이미 걸려있는 친구인지?
        if(arr[num]) {
            vote_cnt[num]++;
            continue;
        }
        // 1. 걸린 사진 개수 파악하기. 동시에 추천 개수가 가장 적고 오래된 친구 기억하기
        int photo_cnt=0, min_vote_cnt=987654321, oldest=987654321, student_to_delete=0;
        for(int i=1; i<=100; ++i){
            if(arr[i]==0) continue;
            photo_cnt++;
            if(min_vote_cnt>vote_cnt[i]){
                min_vote_cnt=vote_cnt[i];
                oldest=arr[i];
                student_to_delete=i;
            }
            else if(min_vote_cnt==vote_cnt[i]){
                if(oldest>arr[i]){
                    student_to_delete=i;
                    oldest=arr[i];
                }
            }
        }
        // 2. 만약 꽉 찼으면 위에서 파악한 친구 삭제하고 새로운 친구 넣기
        if(photo_cnt==N){
            arr[student_to_delete]=0;
            vote_cnt[student_to_delete]=0;
        }
        // 3. 사진 추가
        arr[num]=t;
        vote_cnt[num]=1;
    }
    for(int i=1; i<=100; ++i){
        if(arr[i]){
            cout << i << ' ';
        }
    }
    cout << '\n';
}
