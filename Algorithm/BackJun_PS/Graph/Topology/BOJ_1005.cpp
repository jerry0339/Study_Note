#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;

int T, N=0, M, W;
int deg[1002]{};
vector<int> adj[1002]{};
int ct[1002]{};
int dp[1002]{};

int topology() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0) {
			if (i == W) return ct[i];
			q.push(i);
			dp[i] = ct[i];
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (q.empty()) return -1;
		int cn = q.front();
		q.pop();
		
		for (auto nn : adj[cn]) {
			dp[nn] = max(dp[nn], dp[cn]);
			if (--deg[nn] == 0) {
				q.push(nn);
				dp[nn] += ct[nn];
				if (nn == W) return dp[nn];
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		memset(deg, 0, sizeof(deg));
		memset(ct, 0, sizeof(ct));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= N; i++) adj[i].clear();

		cin >> N >> M;
		for (int i = 1; i <= N; i++) cin >> ct[i];
		int a, b;
		while (M--) {
			cin >> a >> b;
			adj[a].push_back(b);
			deg[b]++;
		}
		cin >> W;

		cout << topology()<<'\n';
	}
}