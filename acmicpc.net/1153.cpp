#include <bits/stdc++.h>
using namespace std;
const int MN=1000001;
int isErased[MN];
vector<int> primes;
int main(){
    int N; cin>>N;
    for(int i=2; i*i<MN; ++i){
        for(int j=i*i; j<MN; j+=i){
            isErased[j]=1;
        }
    }
    for(int i=2; i<MN; ++i){
        if(!isErased[i]) primes.push_back(i);
    }
    if(N<8) cout << "-1\n";
    else if(N==8){
        cout << "2 2 2 2\n";
    }
    else {
        int a = primes[lower_bound(primes.begin(), primes.end(), N-6)-primes.begin()-1];
        int b = primes[lower_bound(primes.begin(), primes.end(), N-a-4)-primes.begin()-1];
        int c = primes[lower_bound(primes.begin(), primes.end(), N-a-b-2)-primes.begin()-1];
        int d = N-a-b-c;
        cout << d << " " << c << " " << b << " " << a << '\n';
    }
}