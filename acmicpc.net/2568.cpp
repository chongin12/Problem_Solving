#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<int> idx[1000001];
pii arr[1000001];
int mask[1000001];
bool comp(pii a, pii b){
	if(a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
    vector<int> v;
	for(int i=0; i<N; ++i){
		int a,b; cin>>a>>b;
		arr[i]={b,a};
	}
	sort(arr,arr+N,comp);
	for(int i=0; i<N; ++i){
		int b=arr[i].first;
		int a=arr[i].second;
		if(i==0) {
			v.push_back(b);
			idx[0].push_back(i);
			//cout << "idx["<<0<<"].push_back("<<t<<")\n";
		}
		else {
            auto it = lower_bound(v.begin(), v.end(), b) - v.begin();
            if(v.size()==it) {
				v.push_back(b);
				idx[it].push_back(i);
				//cout << "idx["<<it<<"].push_back("<<t<<")\n";
			}
            else if(v[it]>b) {
				v[it]=b;
				idx[it].push_back(i);
				//cout << "idx["<<it<<"].push_back("<<t<<")\n";
			}
        }
    }
    cout << N-v.size() << '\n';
	int kidx=idx[v.size()-1][0];
	stack<pii> st;
	st.push(arr[kidx]);
	for(int i=v.size()-2; i>=0; --i){
		sort(idx[i].begin(),idx[i].end()); // index기준 정렬 후 upper bound
		auto it=lower_bound(idx[i].begin(),idx[i].end(),kidx)-idx[i].begin();
		st.push(arr[idx[i][it-1]]);
		kidx=idx[i][it-1];
	}
	while(!st.empty()){
		//cout << st.top().first << ", " << st.top().second << '\n';
		mask[st.top().second]=1;
		st.pop();
	}
	for(int i=0; i<N; ++i){
		if(mask[arr[i].second]) continue;
		cout << arr[i].second << '\n';
	}
}