#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	map<ll, queue<int>> idx;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (!idx.count(arr[i]))
		{
			queue<int> Q;
			Q.push(i);
			idx.insert({ arr[i], Q });
		}
		else idx[arr[i]].push(i);
	}
	vector<ll> sorted(arr);
	sort(sorted.begin(), sorted.end());
	bool can = true;
	for (int i = 0; i < n; i++)
	{
		if (sorted[i] != arr[i])
		{
			queue<int> Q = idx[sorted[i]];
			int arridx = Q.front(); Q.pop();

			ll prevnum = arr[arridx], tonum = arr[i];
			// ll mul = prevnum * tonum;
			// ll sq = (ll)sqrt(mul);
            ll gcd_=gcd(prevnum, tonum);
            ll a=max(prevnum, tonum)/gcd_, b=min(prevnum, tonum)/gcd_;
            if(a%b==0){
                ll mul = a/b;
                ll sq=(ll)sqrt(mul);
                if(mul!=sq*sq){
                    can=false;
                    break;
                }
            }
            else{
                ll sq1=(ll)sqrt(a);
                ll sq2=(ll)sqrt(b);
                if(a!=sq1*sq1 || b!=sq2*sq2){
                    can=false;
                    break;
                }
            }

			swap(arr[arridx], arr[i]);
		}
	}
	if (can) cout << "YES";
	else cout << "NO";



	return 0;
}