#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
typedef complex<double> cpx;

// n-1차 다항식 f를 n개의 복소수로 DFT함. 이 때 x = w
void FFT(vector<cpx> &v, bool inv) {
    int S = v.size();

    for(int i=1, j=0; i<S; i++) {
        int bit = S/2;

        while(j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if(i < j) swap(v[i], v[j]);
    }

    for(int k=1; k<S; k*=2) {
        double angle = (inv ? PI/k : -PI/k);
        cpx w(cos(angle), sin(angle));

        for(int i=0; i<S; i+=k*2) {
            cpx z(1, 0);

            for(int j=0; j<k; j++) {
                cpx even = v[i+j];
                cpx odd = v[i+j+k];

                v[i+j] = even + z*odd;
                v[i+j+k] = even - z*odd;

                z *= w;
            }
        }
    }

    if(inv)
        for(int i=0; i<S; i++) v[i] /= S;
}

// 두 다항식 a, b를 곱한 c를 계산해 돌려주는 함수, i번째 원소는 x^i의 계수
vector<int> mul(vector<int> &v, vector<int> &u) {
    // 다항식의 길이보다 큰 최소의 2의 거듭 제곱수를 찾아 n으로 둔다
    vector<cpx> vc(v.begin(), v.end());
    vector<cpx> uc(u.begin(), u.end());

    int S = 2;
    while(S < v.size() + u.size()) S *= 2;

    vc.resize(S); FFT(vc, false);
    uc.resize(S); FFT(uc, false);

    // 역변환 : c의 DFT 값으로부터 c의 다항식 형태를 복원한다.
    for(int i=0; i<S; i++) vc[i] *= uc[i];
    FFT(vc, true);

    vector<int> w(S);
    for(int i=0; i<S; i++) w[i] = round(vc[i].real());

    return w;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(NULL);

    string str1, str2; cin>>str1>>str2;
    vector<int> v1,v2;
    for(int i=str1.size()-1; i>=0; --i){
        v1.push_back(str1[i]-'0');
    }
    for(int i=str2.size()-1; i>=0; --i){
        v2.push_back(str2[i]-'0');
    }

    vector<int> w = mul(v1, v2);
    vector<int> res;
    int MN=v1.size()+v2.size()-2;
    for(int i=0; i<=MN; ++i){
        if(w[i]>=10){
            w[i+1]+=w[i]/10;
            MN=max(MN,i+1);
            w[i]%=10;
        }
        res.push_back(w[i]);
    }
    for(int i=res.size()-1; i>=0; --i){
        cout << res[i];
    }
    cout << '\n';
}