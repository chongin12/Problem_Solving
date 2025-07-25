#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    string name;
    int cnt;
    Node(int id, string name, int cnt):id(id),name(name),cnt(cnt){}
};

string customRound(double value) {
    double rounded = floor(value * 100 + 0.5) / 100.0;
    stringstream ss;
    ss << fixed << setprecision(2) << rounded;
    return ss.str();
}

int main(){
    int N, M; cin >> N >> M;
    vector<Node> cand;
    for(int i = 0; i < N; ++i){
        string str; cin >> str;
        cand.push_back(Node(i, str, 0));
    }
    int inv = 0;
    for(int i = 0; i < M; ++i){
        string s; cin >> s;
        int idx = -1;
        for(int j = 0; j < N; ++j){
            if(s[j] == 'X'){
                if(idx == -1) idx = j;
                else {
                    idx = -1;
                    break;
                }
            }
        }
        if(idx != -1){
            cand[idx].cnt++;
        } else {
            inv++;
        }
    }
    sort(cand.begin(), cand.end(), [](Node a, Node b){
        if(a.cnt == b.cnt) return a.id < b.id;
        return a.cnt > b.cnt;
    });
    
    for(int i = 0; i < cand.size(); ++i){
        double percentage = (double)cand[i].cnt * 100.0 / (double)M;
        cout << cand[i].name << " " << customRound(percentage) << "%\n";
    }
    double invalidPercentage = (double)inv * 100.0 / (double)M;
    cout << "Invalid " << customRound(invalidPercentage) << "%\n";
    
    return 0;
}