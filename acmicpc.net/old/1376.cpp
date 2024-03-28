#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout. (mmap ver.)
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
	char* p;
	bool __END_FLAG__, __GETLINE_FLAG__;
public:
	explicit operator bool() { return !__END_FLAG__; }
    INPUT() {
        struct stat st; fstat(0, &st);
        p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
    }
	bool IsBlank(char c) { return c == ' ' || c == '\n'; }
	bool IsEnd(char c) { return c == '\0'; }
	char _ReadChar() { return *p++; }
	char ReadChar() {
		char ret = _ReadChar();
		for (; IsBlank(ret); ret = _ReadChar());
		return ret;
	}
	template<typename T> T ReadInt() {
		T ret = 0; char cur = _ReadChar(); bool flag = 0;
		for (; IsBlank(cur); cur = _ReadChar());
		if (cur == '-') flag = 1, cur = _ReadChar();
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	string ReadString() {
		string ret; char cur = _ReadChar();
		for (; IsBlank(cur); cur = _ReadChar());
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return ret;
	}
	double ReadDouble() {
		string ret = ReadString();
		return stod(ret);
	}
	string getline() {
		string ret; char cur = _ReadChar();
		for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
		if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char write_buf[SZ];
	int write_idx;
public:
	~OUTPUT() { Flush(); }
	explicit operator bool() { return 1; }
	void Flush() {
        write(1, write_buf, write_idx);
		write_idx = 0;
	}
	void WriteChar(char c) {
		if (write_idx == SZ) Flush();
		write_buf[write_idx++] = c;
	}
	template<typename T> int GetSize(T n) {
		int ret = 1;
		for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
		return ret;
	}
	template<typename T> void WriteInt(T n) {
		int sz = GetSize(n);
		if (write_idx + sz >= SZ) Flush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz; i --> 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
		write_idx += sz;
	}
	void WriteString(string s) { for (auto& c : s) WriteChar(c); }
	void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
	if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
	else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in; }

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
	if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
	else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out; }

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////

const int MN=100001;
struct Node {
    int cnt, l;
    Node():Node(0,-1){}
    Node(int cnt, int l):cnt(cnt),l(l){}
};
int visited[MN];
int checked[MN];
vector<int> G[MN]; // G는 인덱스 0부터 시작.
vector<Node> seg[MN]; // seg는 인덱스 1부터 시작.
Node Update(int segidx, int idx, int val, int n, int l, int r){ // val이 0이면 G[segidx][idx]번 노드가 visit된 것.
    if(r<idx || idx<l) return seg[segidx][n];
    if(l==r) return seg[segidx][n] = val ? Node(1,idx) : Node();
    int mid = (l+r)/2;
    Node left=Update(segidx, idx, val, n*2, l, mid), right=Update(segidx, idx, val, n*2+1, mid+1, r);
    int leftmost=-1;
    if(left.cnt!=0) leftmost=left.l;
    else if(right.cnt!=0) leftmost=right.l;
    return seg[segidx][n]=Node(left.cnt+right.cnt,leftmost);
}
Node Query(int segidx, int L, int R, int n, int l, int r){
    if(r<L || R<l) return Node();
    if(L<=l && r<=R) return seg[segidx][n];
    int mid = (l+r)/2;
    Node left=Query(segidx, L, R, n*2, l, mid), right=Query(segidx, L, R, n*2+1, mid+1, r);
    int leftmost=-1;
    if(left.cnt!=0) leftmost=left.l;
    else if(right.cnt!=0) leftmost=right.l;
    return Node(left.cnt+right.cnt,leftmost);
}
int FindMiddle(int segidx, int val, int L, int R, int n, int l, int r){
    // val : 앞에서 val번째 원소 구하기
    Node left = seg[segidx][n*2];
    Node right = seg[segidx][n*2+1];
    return 0;
}

void dfs(int x){
    if(visited[x]) return;
    visited[x]=1;
    cout << x << ' ';
    // 1. 주변 인접 노드들에 대해 Update 수행.
    if(checked[x]==0) {
        checked[x]=1;
        for(auto nxt:G[x]){
            Update(nxt,lower_bound(G[nxt].begin(), G[nxt].end(),x)-G[nxt].begin()+1,0,1,1,G[nxt].size());
        }
    }
    
    while(1){
        Node k=Query(x,1,G[x].size(),1,1,G[x].size());
        // cout << "x : " << x << ", cnt : " << k.cnt << ", l : " << k.l << '\n';
        if(k.cnt==0) return;
        else if(k.cnt%2==0 || k.cnt==1){
            int nxt=G[x][k.l-1];
            Update(x,k.l,0,1,1,G[x].size());
            dfs(nxt);
        }
        else{
            int targetN=k.cnt/2;
            // 1부터 mid까지의 구간에 targetN개가 있어야 함.
            int l=1, r=G[x].size()+1;
            while(l<r-1){
                int mid=(l+r)/2;
                Node temp = Query(x,1,mid,1,1,G[x].size());
                if(temp.cnt <= targetN) l=mid;
                else r=mid;
            }
            int nxtidx=Query(x,r,G[x].size(),1,1,G[x].size()).l;
            Update(x,nxtidx,0,1,1,G[x].size());
            dfs(G[x][nxtidx-1]);
        }
    }
}
vector<pair<int,int>> edges;
int main(){
    fastio;
    int N,M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int u,v; cin>>u>>v;
        if(u==v) continue;
        if(u>v) swap(u,v);
        edges.push_back({u,v});
    }
    sort(edges.begin(), edges.end());
    for(int i=0; i<edges.size(); ++i){
        if(i>0 && edges[i]==edges[i-1]) continue;
        G[edges[i].first].push_back(edges[i].second);
        G[edges[i].second].push_back(edges[i].first);
    }
    for(int i=1; i<=N; ++i){
        seg[i] = vector<Node>(G[i].size()*4+1);
        for(int j=0; j<G[i].size(); ++j){
            Update(i,j+1,1,1,1,G[i].size());
        }
    }
    dfs(1);
}

/*
1 => 2 3 4
2 => 1 3 5
3 => 1 2 4
4 => 1 4
5 => 2
*/