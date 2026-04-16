// BOJ 11002 - 까마귀의 길
//
// 접근법:
//  - y >= 0 위쪽, 그리고 산(단조 다각형) 내부가 아닌 영역이 유효 영역.
//  - 산의 윗 폴리라인은 x가 증가하는 단조 체인 (P_1, ..., P_N).
//  - A -> B (x_A <= x_B) 최단 경로는 집합
//        S = {A, B} ∪ { P_i : x_A <= x_i <= x_B }
//    의 upper convex hull 상의 에지 길이 합과 같다.
//    (고무줄이 S 위에 팽팽하게 걸쳐졌을 때의 길이)
//
// 전체 전략:
//  1. 산 정점에 대한 세그먼트 트리를 만들고, 각 노드에 해당 구간의
//     upper hull(정점들을 담은 배열)과 hull 에지 길이 누적합을 저장.
//     빌드 시 두 자식 hull을 "upper common tangent (bridge)"로 병합. O(N log N).
//  2. 질의 (A, B):
//     - [l, r] = { i : x_A <= x_i <= x_B } 를 이분 탐색으로 결정.
//     - 세그먼트 트리로 [l, r]을 O(log N)개 노드로 분해.
//     - 분해된 hull들을 왼쪽에서 오른쪽으로 bridge merge 하여
//       최종 upper hull을 얻고, 필요 시 A와 B를 양 끝에 포함.
//       각 merge는 두 오목 체인 사이의 공통 상접선을
//       O(log) 이진 탐색으로 찾고, 누적합으로 길이를 얻음. O(log^2 N) per query.
//  3. 모든 소비 길이를 더해 출력.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // TODO: 구현 예정
    return 0;
}
