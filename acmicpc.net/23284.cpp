#include <bits/stdc++.h>
using namespace std;
set<string> s;
int N;
void f(int phase, string nowStack, string acc){
    if(phase==N){
        reverse(nowStack.begin(), nowStack.end());
        acc+=nowStack;
        s.insert(acc);
        return;
    }
    if(!nowStack.empty()) {
        string newStack = nowStack, newAcc = acc;
        newAcc.push_back(nowStack.back());
        newStack.pop_back();
        f(phase, newStack, newAcc);
    }
    string newAcc=acc, newStack=nowStack;
    newAcc.push_back(phase+'0');
    f(phase+1, nowStack, newAcc);

    newStack.push_back(phase+'0');
    f(phase+1, newStack, acc);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N;
    f(0, "", "");
    for(auto it:s){
        for(auto itt:it){
            if(itt=='9') cout << "10 ";
            else cout << (char)(itt+1) << " ";
        }
        cout << '\n';
    }
}