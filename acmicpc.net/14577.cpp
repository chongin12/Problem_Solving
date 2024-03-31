#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll arr[100001];
struct Node {
    Node *lNode, *rNode;
    ll l, r; // 구간
    int v; // 해당 구간 값
};
ll Query4(Node * now, ll k){ // now 구간에서 k번째로 적은 도시에 쌓인 눈의 양
    // cout << "now : " << now->l << " ~ " << now->r << ", v : " << now->v << ", k : "<< k << '\n';
    if(now->l == now->r){
        return now->l;
    }
    if(now->lNode!=NULL){
        if(now->lNode->v>=k){
            return Query4(now->lNode, k);
        }
        else {
            return Query4(now->rNode, k-now->lNode->v);
        }
    }
    return Query4(now->rNode, k);
}
int Query3(ll L, ll R, Node * now){ // 적설량이 L 이랑 R 이하인 지역의 수
    if(L <= now->l && now->r <= R){
        return now->v;
    }
    if(R<now->l || now->r<L){
        return 0;
    }
    ll mid = (now->l+now->r)/2;
    int ret = 0;
    if(now->lNode != NULL){
        ret += Query3(L, R, now->lNode);
    }
    if(now->rNode != NULL){
        ret += Query3(L, R, now->rNode);
    }
    return ret;
}
ll Update(ll idx, ll val, Node * now){
    if(idx < now->l || now->r < idx) {
        return now->v;
    }
    if(now->l == now->r) {
        now->v += val;
        return now->v;
    }
    ll mid = (now->l + now->r) / 2;
    int ret=0;
    if(idx<=mid){
        if(now->lNode == NULL){
            now->lNode = new Node({NULL, NULL, now->l, mid, 0});
        }
        ret+=Update(idx, val, now->lNode);
        if(now->rNode != NULL){
            ret+=now->rNode->v;
        }
    }
    else {
        if(now->rNode == NULL){
            now->rNode = new Node({NULL, NULL, mid+1, now->r, 0});
        }
        ret+=Update(idx, val, now->rNode);
        if(now->lNode != NULL){
            ret+=now->lNode->v;
        }
    }
    now->v = ret;
    return now->v;
}
void display(Node * node, int phase){
    for(int i=0; i<2*phase; ++i){
        cout << " ";
    }
    cout << "{"<<node->l<<" ~ " << node->r << "} = " << node->v << '\n';
    if(node->lNode!=NULL){
        display(node->lNode, phase+1);
    }
    if(node->rNode!=NULL){
        display(node->rNode, phase+1);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, M; cin>>N>>M;
    // Node * root = new Node({NULL, NULL, 0, (ll)1e2, 0});
    Node * root = new Node({NULL, NULL, 0, (ll)1e18, 0});
    for(ll i=1; i<=N; ++i){
        cin>>arr[i];
        Update(arr[i], 1, root);
    }
    while(M--){
        // cout << "---------\n";
        // display(root, 0);
        // cout << "---------\n";
        ll ch; cin>>ch;
        if(ch==1){
            ll i, x; cin>>i>>x;
            Update(arr[i], -1, root);
            arr[i]+=x;
            Update(arr[i], 1, root);
        }
        else if(ch==2){
            ll i, y; cin>>i>>y;
            Update(arr[i], -1, root);
            arr[i]-=y;
            Update(arr[i], 1, root);
        }
        else if(ch==3){
            ll Li, Ri; cin>>Li>>Ri;
            cout << Query3(Li, Ri, root) << '\n';
        }
        else {
            ll T; cin>>T;
            cout << Query4(root, N-T+1) << '\n';
        }
    }
}