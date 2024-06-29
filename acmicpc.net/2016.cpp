#include <bits/stdc++.h>
using namespace std;
struct Node {
    char ch;
    Node *prev, *next;
};
Node * head = new Node({'#', NULL, NULL});
Node * cur = head;
void pushRight(char ch){
    Node * newNode = new Node({ch, cur, cur->next});
    if(cur->next != NULL) {
        cur->next->prev=newNode;
    }
    cur->next = newNode;
}
void goRight() {
    if(cur->next != NULL) cur = cur->next;
}
void goLeft() {
    if(cur->prev != NULL) cur = cur->prev;
}
void deleteCur(){
    if(cur->ch == '#') return;
    cur=cur->prev;
    Node * toFree = cur->next;
    cur->next=cur->next->next;
    if(cur->next != NULL) cur->next->prev=cur;
    free(toFree);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;
    for(auto it:str){
        if(head==NULL){
            head=new Node({it, NULL, NULL});
            cur=head;
        }
        else {
            pushRight(it);
            goRight();
        }
    }
    goRight();
    int M; cin>>M;
    while(M--){
        char ch; cin>>ch;
        if(ch=='P') {
            char c; cin>>c;
            pushRight(c);
            goRight();
        }
        else if(ch=='L'){
            goLeft();
        }
        else if(ch=='D'){
            goRight();
        }
        else{
            deleteCur();
        }
    }
    head=head->next;
    while(head!=NULL){
        cout << head->ch;
        head=head->next;
    }
    cout << '\n';
}