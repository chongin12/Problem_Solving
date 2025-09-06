#include <bits/stdc++.h>
using namespace std;
/*
퍼시스턴트 세그먼트 트리 구성하기
새로 구성할 때 마다 root는 항상 새로운 것으로 추가된다.
업데이트 되는 노드 개수는 항상 트리의 높이와 같다.
*/
struct Node {
    int l, r, val, leftChild, rightChild;
};
vector<Node> nodes;
int root[100001];
// 가장 처음 모든 노드를 한번씩 빈 값으로 전부 생성.
int init(int s, int e) {
    int nodeNum = nodes.size();
    nodes.push_back({s, e, 0, -1, -1});
    if(s!=e) {
        int mid = (s+e)/2;
        int leftChild = init(s, mid);
        int rightChild = init(mid+1, e);
        nodes[nodeNum].leftChild = leftChild;
        nodes[nodeNum].rightChild = rightChild;
    }
    return nodeNum;
}
// 기존 노드 기반으로 새로운 노드 발행하기
// return : 발행한 노드 번호
int newNode(Node &shadow) {
    int nodeNum = nodes.size();
    nodes.push_back({shadow.l, shadow.r, shadow.val, shadow.leftChild, shadow.rightChild});
    return nodeNum;
}

// 트리 높이만큼의 노드 생성하면서 업데이트하기
// 현재 구간에서 노드 생성이 필요하지 않다면 그냥 리턴.
// 현재 노드에서 자식 노드들을 만들어주기 때문에 루트는 만들어서 넣어줘야 함.
void Update(int idx, int delta, int nodeNum, int s, int e) {
    if(idx<s || e<idx){
        return;
    }
    if(s==e){
        nodes[nodeNum].val += delta;
        return;
    }
    int mid = (s+e)/2;
    if(idx<=mid){ // 왼쪽 자식 노드 생성, 오른쪽 노드 재사용
        int newLeftNode = newNode(nodes[nodes[nodeNum].leftChild]);
        Update(idx, delta, newLeftNode, s, mid);
        nodes[nodeNum].leftChild = newLeftNode;
    }
    else { // 오른쪽 자식 노드 생성, 왼쪽 노드 재사용
        int newRightNode = newNode(nodes[nodes[nodeNum].rightChild]);
        Update(idx, delta, newRightNode, mid+1, e);
        nodes[nodeNum].rightChild = newRightNode;
    }

    nodes[nodeNum].val = nodes[nodes[nodeNum].leftChild].val + nodes[nodes[nodeNum].rightChild].val;
}

int Query(int query_l, int query_r, int nodeNum, int s, int e){
    if(query_r<s || e<query_l){
        return 0;
    }
    if(query_l<=s && e<=query_r){
        return nodes[nodeNum].val;
    }
    int mid = (s+e)/2;
    return Query(query_l, query_r, nodes[nodeNum].leftChild, s, mid) + Query(query_l, query_r, nodes[nodeNum].rightChild, mid+1, e);
}

map<int, int> zippedToOriginal;
map<int, int> originalToZipped;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // 퍼시스턴트 세그먼트 트리를 구상한다.
    // 각 인덱스가 x좌표, 값이 y좌표로 구성.
    // i~j 의 x좌표 구간에서 
    // 0~y좌표를 쿼리로 구한다. (해당 구간에 몇 개의 값이 있는지) -> 이걸 이분탐색으로 K에 맞춘다.

    root[0] = init(1, 100000);
    int N, M; cin>>N>>M;
    vector<int> v, oriv;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a); oriv.push_back(a);
    }
    sort(v.begin(), v.end());
    int cnt=1;
    zippedToOriginal[cnt]=v[0];
    originalToZipped[v[0]]=cnt;
    for(int i=1; i<N; ++i){ // 1~N까지 좌표 압축
        if(v[i-1]!=v[i]){
            ++cnt;
            zippedToOriginal[cnt]=v[i];
            originalToZipped[v[i]]=cnt;
        }
    }
    for(int i=0; i<N; ++i){
        int newRoot = newNode(nodes[root[i]]);
        // cout << "insert : " << originalToZipped[oriv[i]] << '\n';
        Update(originalToZipped[oriv[i]], 1, newRoot, 1, 100000);
        nodes[newRoot].val = nodes[nodes[newRoot].leftChild].val + nodes[nodes[newRoot].rightChild].val;
        root[i+1]=newRoot;
    }

    // for(int i=0; i<=7; ++i){
    //     cout << '\n';
    //     for(int j=1; j<=10; ++j){
    //         cout << "Query(1, "<<j<<", root["<<i<<"], 1, 100000)="<<Query(1, j, root[i], 1, 100000)<<'\n';
    //     }
    //     cout << '\n';
    // }

    while(M--){
        int i, j, k; cin>>i>>j>>k;

        // Query(1, x, root[j], 1, 100000) - Query(1, x, root[i-1], 1, 100000) 이 K가 되어야 함
        int lo=0, hi=100000;
        while(lo<hi-1){
            int mid = (lo+hi)/2;
            int temp = Query(1, mid, root[j], 1, 100000) - Query(1, mid, root[i-1], 1, 100000);
            // cout << "\nQuery(1, "<<mid<<", root["<<j<<"], 1, 100000)="<<Query(1, mid, root[j], 1, 100000)<<'\n';
            // cout << "Query(1, "<<mid<<", root["<<i-1<<"], 1, 100000)="<<Query(1, mid, root[i-1], 1, 100000)<<'\n';
            if(temp>=k){
                hi=mid;
            }
            else {
                lo=mid;
            }
        }
        // cout << "lo="<<lo<<", hi="<<hi<<'\n';
        cout << zippedToOriginal[hi] << '\n';
    }
}