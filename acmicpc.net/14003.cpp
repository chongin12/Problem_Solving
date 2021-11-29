#include <bits/stdc++.h>
using namespace std;
vector<int> idx[1000001];
int arr[1000001];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
    vector<int> v;
	for(int i=0; i<N; ++i){
        int t; cin >> t;
		arr[i]=t;
		if(i==0) {
			v.push_back(t);
			idx[0].push_back(i);
			//cout << "idx["<<0<<"].push_back("<<t<<")\n";
		}
		else {
            auto it = lower_bound(v.begin(), v.end(), t) - v.begin();
            if(v.size()==it) {
				v.push_back(t);
				idx[it].push_back(i);
				//cout << "idx["<<it<<"].push_back("<<t<<")\n";
			}
            else if(v[it]>t) {
				v[it]=t;
				idx[it].push_back(i);
				//cout << "idx["<<it<<"].push_back("<<t<<")\n";
			}
        }
    }
    cout << v.size() << '\n';
	int kidx=idx[v.size()-1][0];
	stack<int> st;
	st.push(arr[kidx]);
	for(int i=v.size()-2; i>=0; --i){
		sort(idx[i].begin(),idx[i].end()); // index기준 정렬 후 upper bound
		auto it=lower_bound(idx[i].begin(),idx[i].end(),kidx)-idx[i].begin();
		st.push(arr[idx[i][it-1]]);
		kidx=idx[i][it-1];
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	cout << '\n';
}