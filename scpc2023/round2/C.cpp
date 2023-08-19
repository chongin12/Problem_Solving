// #include <bits/stdc++.h>
// using namespace std;
// int dp[5005][5005]; // dp[i][j] : i번을 j번째 stick으로 선택했을 때 최대 너비
// struct stick {
//     int l, r, lhalf, rhalf;
//     stick(int l, int r, int lhalf, int rhalf):l(l),r(r),lhalf(lhalf),rhalf(rhalf){}
// };
// int countOfHalfs(stick s){
//     int ret=0;
//     if(s.lhalf) ret++;
//     if(s.rhalf) ret++;
//     return ret;
// }
// // s1이 s2를 포함하면 1, s2가 s1을 포함하면 2, 별개면 3
// int stickContains(stick s1, stick s2){
//     if(s1.l < s2.l && s2.r < s1.r) return 1;
//     if(s2.l < s1.l && s1.r < s2.r) return 2;
//     if(s1.l == s2.l && s1.lhalf==s2.lhalf && s2.r < s1.r) return 1;
//     if(s2.l == s1.l && s2.lhalf==s1.lhalf && s1.r < s2.r) return 2;
//     if(s1.l < s2.l && s2.r == s1.r && s2.rhalf == s1.rhalf) return 1;
//     if(s2.l < s1.l && s1.r == s2.r && s1.rhalf == s2.rhalf) return 1;

//     if(s1.l==s2.l && s1.lhalf==s2.lhalf && s1.r==s2.r && s1.rhalf == s2.rhalf) return 1;
//     return 3;
// }
// int main(){
//     ios::sync_with_stdio(0); cin.tie(0);
//     int T; cin>>T;
//     for(int t_=1; t_<=T; ++t_){
//         cout << "Case #" << t_ << "\n";
//         int N; cin>>N;
//         vector<stick> sticks;
//         vector<int> v;
//         int temp=0;
//         for(int i=0; i<N; ++i){
//             int a; cin>>a; v.push_back(a);
//         }
//         int M,t; cin>>M>>t;
//         for(int i=0; i<N; ++i){
//             stick now={i,i,0,0};
//             for(int j=1; j<=t; ++j){
//                 if(i-j<0) break;
//                 if(v[i-j]==2){
//                     now.lhalf=1;
//                     break;
//                 }
//                 now.l=i-j;
//             }
//             for(int j=1; j<=t; ++j){
//                 if(i+j>=N) break;
//                 if(v[i+j]==2){
//                     now.rhalf=1;
//                     break;
//                 }
//                 now.r=i+j;
//             }
//             if(sticks.empty()) sticks.push_back(now);
//             int stickContainsRes = stickContains(sticks.back(), now);
//             if(stickContainsRes==1){
//                 continue;
//             }
//             else if(stickContainsRes==2){
//                 sticks.pop_back();
//                 sticks.push_back(now);
//             }
//             else{
//                 sticks.push_back(now);
//             }
//         }
//         // for(auto it:sticks){
//         //     cout << "<- " << it.l << ", " << it.r << " -> \n";
//         // }
//         for(int i=0; i<sticks.size(); ++i){
//             // 막대기 N개가 있을 때 이중 M개를 선택해서 최대한 많은 좌표를 커버해야 함. 겹쳐도 상관 없음.
//             for(int j=0; j<=i; ++j){ // i번 막대를 j번째로 선택할 때
//                 dp[i][j]=0;
//                 if(j==0){
//                     // i번 막대를 처음으로 선택할 때
//                     dp[i][j]=sticks[i].r-sticks[i].l+1;
//                 }
//                 else{
//                     for(int k=j-1; k<i; ++k){ // 이전에 k번 막대를 j-1번째로 선택했을 때
//                         if(sticks[k].r+1==sticks[i].l-1 && sticks[k].rhalf && sticks[i].lhalf){ // 하나 꽁으로 얻기 가능?
//                             dp[i][j]=max(dp[i][j], dp[k][j-1]+sticks[i].r-sticks[i].l+2);
//                         }
//                         else {
//                             dp[i][j]=max(dp[i][j], dp[k][j-1]+sticks[i].r-max(sticks[i].l,sticks[k].r+1)+1);
//                         }
//                     }
//                 }
//                 // cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<'\n';
//             }
//         }
//         int res=0;
//         for(int i=0; i<M; ++i){
//             res=max(res,dp[sticks.size()-1][i]);
//         }
//         cout << res << '\n';
//     }
// }