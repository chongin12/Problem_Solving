#include <bits/stdc++.h>
using namespace std;
const int MN=500001;
const int INF=987654321;
struct Student {
    int id; // 몇번째 학생?
    int a,b,c; // 1번째, 2번째, 3번째 시험 등수
    Student(int id, int a, int b, int c):id(id),a(a),b(b),c(c){}
};
vector<Student> students;
int seg[MN*4+1];
int Update(int idx, int val, int n, int l, int r) {
    if(idx<l || r<idx) return seg[n];
    if(l==r) return seg[n]=val;
    int mid=(l+r)/2;
    return seg[n]=min(Update(idx, val, n*2, l, mid), Update(idx, val, n*2+1, mid+1, r));
}
int Query(int L, int R, int n, int l, int r) {
    if(r<L || R<l) return INF;
    if(L<=l && r<=R) return seg[n];
    int mid=(l+r)/2;
    return min(Query(L, R, n*2, l, mid), Query(L, R, n*2+1, mid+1, r));
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        students.push_back(Student(i,0,0,0));
        Update(i+1, INF, 1, 1, N);
    }
    for(int i=1; i<=N; ++i){
        int a; cin>>a; students[a-1].a=i;
    }
    for(int i=1; i<=N; ++i){
        int a; cin>>a; students[a-1].b=i;
    }
    for(int i=1; i<=N; ++i){
        int a; cin>>a; students[a-1].c=i;
    }
    sort(students.begin(), students.end(), [](Student a, Student b){return a.a<b.a;});
    // for(auto it:students){
    //     cout << it.id+1 << "th student : " << it.a << ", " << it.b << ", " << it.c << '\n';
    // }
    int res=0;
    for(int i=0; i<N; ++i){
        if(Query(1, students[i].b-1, 1, 1, N) > students[i].c){
            res++;
            Update(students[i].b, students[i].c, 1, 1, N);
        }
    }
    cout << res << '\n';
}