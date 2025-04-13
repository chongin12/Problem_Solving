#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
struct Node {
    int num;
    Node *prev;
    Node *next;
};
int main(){
    int K, N; cin>>N>>K;
    string str; cin>>str;
    Node * start = new Node({11, NULL, NULL});
    Node * end = new Node({-1, NULL, NULL});
    Node * cur = start;
    for(int i=0; i<N; ++i){
        auto it=stoi(string()+str[i]);

        Node * newNode = new Node({it, NULL, NULL});
        newNode->prev=cur;
        cur->next=newNode;
        cur = cur->next;
    }
    cur->next=end;
    end->prev=cur;
    cur = start->next;
    while(cur != end && K>0){
        if(cur->prev->num < cur->num){
            Node * temp = cur->prev;
            cur->prev=cur->prev->prev;
            cur->prev->next=cur;
            N--;
            K--;
            free(temp);
        }
        else {
            cur=cur->next;
        }
    }
    cur=start;
    for(int i=0; i<N-K; ++i){
        cur=cur->next;
        cout << cur->num;
    }
    cout << '\n';
}