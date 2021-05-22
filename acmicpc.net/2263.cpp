#include <iostream>
using namespace std;
int io[100001];
int po[100001];
void f(int ioS, int ioE, int poS, int poE){
    if(ioE<ioS) return;
    if(ioS==ioE) {
        cout << io[ioS] << " ";
        return;
    }
    int root = po[poE]; // root number
    cout << root << " ";
    int ioRootLoc;
    for(int i=ioS; i<=ioE; ++i){
        if(io[i] == root) {
            ioRootLoc = i;
            break;
        }
    }
    f(ioS, ioRootLoc-1, poS, poS+(ioRootLoc-ioS-1));
    f(ioRootLoc+1, ioE, poS+(ioRootLoc-ioS), poE-1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; ++i){
        cin >> io[i];
    }
    for(int i=0; i<n; ++i){
        cin >> po[i];
    }
    f(0, n-1, 0, n-1);
    cout << '\n';
}