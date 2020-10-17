// <게임 개발> - BOJ_1516
// 위상정렬

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

// 위상정렬
void topology() {
	queue<int> q;
	for (int i = 1; i <= N; i++) { // 각 노드의 선행노드(부모노드) 개수 초기화
		if (deg[i] == 0) { 
			q.push(i); // 선행노드가 없는 경우 큐에 삽입
			ans[i] += ct[i];
		}
	}

	for (int i = 1; i <= N; i++) { // 큐pop개수는 노드개수와 같음
		int cn = q.front();
		q.pop();

        // 큐에서 degree가 0인노드 빼기 위해 그 노드가 가리키는 차수 하나씩 빼줌
		for (auto nn : adj[cn]) {
			ans[nn] = max(ans[nn], ans[cn]); // 위상정렬 응용(BOJ_1516)

			if (--deg[nn] == 0) { // 다음노드의 차수를 뺀값이 0이면 큐에 삽입 
				q.push(nn);
				ans[nn] += ct[nn]; // 위상정렬 응용
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