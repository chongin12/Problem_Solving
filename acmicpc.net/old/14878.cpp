#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const double PI = acos(-1);
typedef complex<double> cpx;

// n-1차 다항식 f를 n개의 복소수로 DFT함. 이 때 x = w
void FFT(vector<cpx> &v, bool inv) {
    ll S = v.size();

    for(ll i=1, j=0; i<S; i++) {
        ll bit = S/2;

        while(j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if(i < j) swap(v[i], v[j]);
    }

    for(ll k=1; k<S; k*=2) {
        double angle = (inv ? PI/k : -PI/k);
        cpx w(cos(angle), sin(angle));

        for(ll i=0; i<S; i+=k*2) {
            cpx z(1, 0);

            for(ll j=0; j<k; j++) {
                cpx even = v[i+j];
                cpx odd = v[i+j+k];

                v[i+j] = even + z*odd;
                v[i+j+k] = even - z*odd;

                z *= w;
            }
        }
    }

    if(inv)
        for(ll i=0; i<S; i++) v[i] /= S;
}

void XORFFT(vector<ll> &v, bool inv) {
    ll S = v.size();

    for(ll i=1, j=0; i<S; i++) {
        ll bit = S/2;

        while(j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if(i < j) swap(v[i], v[j]);
    }

    for(ll k=1; k<S; k*=2) {
        for(ll i=0; i<S; i+=k*2) {
            for(ll j=0; j<k; j++) {
                ll even = v[i+j];
                ll odd = v[i+j+k];

                v[i+j] = even + odd;
                v[i+j+k] = even - odd;
            }
        }
    }

    if(inv)
        for(ll i=0; i<S; i++) v[i] /= S;
}

// 두 다항식 a, b를 곱한 c를 계산해 돌려주는 함수, i번째 원소는 x^i의 계수
vector<ll> mul(vector<ll> &v, vector<ll> &u) {
    // 다항식의 길이보다 큰 최소의 2의 거듭 제곱수를 찾아 n으로 둔다
    vector<cpx> vc(v.begin(), v.end());
    vector<cpx> uc(u.begin(), u.end());

    ll S = 2;
    while(S < v.size() + u.size()) S *= 2;

    vc.resize(S); FFT(vc, false);
    uc.resize(S); FFT(uc, false);

    // 역변환 : c의 DFT 값으로부터 c의 다항식 형태를 복원한다.
    for(ll i=0; i<S; i++) vc[i] *= uc[i];
    FFT(vc, true);

    vector<ll> w(S);
    for(ll i=0; i<S; i++) w[i] = round(vc[i].real());

    return w;
}

vector<ll> XORmul(vector<ll> &v, vector<ll> &u) {
    // 다항식의 길이보다 큰 최소의 2의 거듭 제곱수를 찾아 n으로 둔다
    vector<ll> vc(v.begin(), v.end());
    vector<ll> uc(u.begin(), u.end());

    ll S = 2;
    while(S < v.size() + u.size()) S *= 2;

    vc.resize(S); XORFFT(vc, false);
    uc.resize(S); XORFFT(uc, false);

    // 역변환 : c의 DFT 값으로부터 c의 다항식 형태를 복원한다.
    for(ll i=0; i<S; i++) vc[i] *= uc[i];
    XORFFT(vc, true);

    vector<ll> w(S);
    for(ll i=0; i<S; i++) w[i] = vc[i];

    return w;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(NULL);

    /*
    1. 먼저 누적합을 구한다.
    2. 00을 포함해서 나오는 모든 비트의 개수를 센다.
    3. 그대로 배열에 집어넣고 XOR FFT를 돌린다.
    4. 00은 n+1을 빼준다.(자기 자신 xor하면 0이 나옴 이 경우는 제외해야함)
    5. FFT한 후 나온 모든 차항에 대해 가장 큰 인덱스의 수가 정답이다. 개수는 /2해야 함.
    */

    ll n; cin>>n;
    vector<ll> s, arr(65536);
    s.push_back(0);
    arr[0]++;
    for(ll i=1; i<=n; ++i){
        ll a; cin>>a;
        s.push_back(a^s[i-1]);
        arr[s[i]]++;
    }
    vector<ll> r=XORmul(arr,arr);
    r[0]-=n+1;
    ll residx=0;
    for(ll i=0; i<r.size(); ++i){
        // if(i<5) cout << "r["<<i<<"]="<<r[i]<<'\n';
        if(r[residx]<r[i]) residx=i;
    }
    cout << residx << " " << r[residx]/2 << '\n';

}