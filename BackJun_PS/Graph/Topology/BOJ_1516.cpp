// 3:45
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int N;
vector<int> adj[501]{};
int deg[501]{};
int ct[501]{};
int ans[501]{};

void topology() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0) { 
			q.push(i);
			ans[i] += ct[i];
		}
	}

	for (int i = 1; i <= N; i++) {
		int cn = q.front();
		q.pop();

		for (auto nn : adj[cn]) {
			ans[nn] = max(ans[nn], ans[cn]);
			if (--deg[nn] == 0) {
				q.push(nn);
				ans[nn] += ct[nn];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int n;
	for (int i = 1; i <= N; i++) {
		cin >> ct[i];
		while (1) {
			cin >> n;
			if (n == -1) break;
			adj[n].push_back(i);
			deg[i]++;
		}
	}

	topology();
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
}