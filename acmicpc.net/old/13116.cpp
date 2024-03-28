#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int T;  cin >> T;
    while(T--){
        int n1, n2; cin >> n1 >> n2;
        set<int> s;
        while(1){
            s.insert(n1);
            if(n1/2==0) break;
            n1/=2;
        }
        while(1){
            if(s.find(n2) != s.end()){
                cout << 10*n2 << '\n';
                break;
            }
            n2/=2;
        }
    }
}