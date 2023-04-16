#include <iostream>
#include <vector>
using namespace std;

int arr[9][9];
vector<pair<int, int> > v;
bool chk(int r, int c, int val) {
	for (int i = 0; i < 9; ++i) {
		if (c == i) continue;
		if (arr[r][i] == val) return false;
	}
	for (int i = 0; i < 9; ++i) {
		if (r == i) continue;
		if (arr[i][c] == val) return false;
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if ((r / 3) * 3 + i == r && (c / 3) * 3 + j == c) continue;
			if (arr[(r / 3) * 3 + i][(c / 3) * 3 + j] == val) return false;
		}
	}
	return true;
}
bool f(int n) {
	if (n == v.size()) return true;
	for (int k = 1; k <= 9; ++k) {
		if (chk(v[n].first, v[n].second, k)) {
			arr[v[n].first][v[n].second] = k;
			if(!f(n+1)) arr[v[n].first][v[n].second] = 0;
		}
	}
	if (arr[v[n].first][v[n].second] == 0) return false;
	
	else return true;
}
int main() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) v.push_back({ i, j });
		}
	}
	if(v.size()!=0)
		f(0);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}