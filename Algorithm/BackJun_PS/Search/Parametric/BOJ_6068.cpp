// <시간 관리하기> - BOJ_6068
// Parametric search

#include<bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
typedef pair<int, int> pii;

int N;
vector<pii> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int t, s, max_ = 0;
	for (int i = 0; i < N; i++) {
		cin >> t >> s;
		v.push_back({ s,t });
		max_ = max(max_, s);
	}
	sort(v.begin(), v.end());
	int l, r, mid;
	l = 0; r = max_;
	bool chk2 = false;
	while (l <= r) {
		mid = (l + r) / 2;
		int cnt = mid;
		bool chk = true;
		for (int i = 0; i < N; i++) {
			cnt += v[i].yy;
			if (cnt > v[i].xx) {chk = false; break;}
		}
		if (chk) l = mid + 1;
		else r = mid - 1;
	}

	cout << r;
}