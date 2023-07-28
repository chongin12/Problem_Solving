#include <bits/stdc++.h>
using namespace std;

vector<int> G[250001];
int visited[250001];
string R, P;
void init(int n){
    for(int i=0; i<=n; ++i){
        G[i].clear();
        visited[i]=0;
    }
}
vector<int> getFail(const string &p){
	int m = p.size();
	vector<int> fail(m);
	for(int i=1, j=0; i<m; ++i){
		while(j>0 && p[i]!=p[j]) j=fail[j-1];
		if(p[i]==p[j]) fail[i]=++j;
	}
	return fail;
}
vector<int> KMP(const string &s, const string &p){
	int n=s.size();
	int m=p.size();
	vector<int> fail = getFail(p), res;
	for(int i=0, j=0; i<n; ++i){
		while(j>0 && s[i]!=p[j]) j=fail[j-1];
		if(s[i]==p[j]){
			if(j==m-1) res.push_back(i-m+1), j=fail[j];
			else j++;
		}
	}
	return res;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        cout << "Case #"<<t<<"\n";
        cin>>R>>P;
        if(R.size()>16 && P.size()>16){
            cout << "-1\n";
            continue;
        }
        init(R.size());
        while(P.size()){
            vector<int> pos = KMP(R, P);
            for(auto it:pos){
                G[it].push_back(it+P.size());
                //cout << it << " -> " << it+P.size()  << '\n';
            }
            P.pop_back();
        }
        queue<pair<int,int> > q;
        q.push({0, 0});
        visited[0]=1;
        int res=-1;
        while(!q.empty()){
            pair<int,int> cur = q.front(); q.pop();
            if(cur.first == R.size()){
                res=cur.second;
                break;
            }
            for(auto nxt:G[cur.first]){
                if(!visited[nxt]){
                    q.push({nxt, cur.second+1});
                }
            }
        }
        cout << res << '\n';
    }
}