//<DFS와 BFS> - 1260
// 인접행렬 (인접리스트로 구현하는것이 더 좋음)

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<bool>> &, vector<bool> &, int);
void bfs(vector<vector<bool>> &, vector<bool> &, int);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, v;
	cin >> n >> m >> v; // n : 정점개수 , m : 간선개수 , v : 시작노드인덱스
	v--; // 인덱스로 접근
	vector<vector<bool>> g(n); // graph adj_matrix
	for(int i=0; i<n; i++) g[i] = vector<bool>(n, 0);
	vector<bool> dfsVisited(n, 0); // dfs 그래프 방문여부
	vector<bool> bfsVisited(n, 0); // bfs 그래프 방문여부

	while (m--) {
		int a, b;
		cin >> a >> b; a--; b--; // 인덱스가 필요한경우 입력받을때 부터 --해주기
		g[a][b] = true;
		g[b][a] = true;
	}

	dfs(g,dfsVisited,v);
	cout << "\n";
	bfs(g,bfsVisited,v);
	
}

// 출력(실행)후 방문확인, 이후 연결된 노드중 방문안된 정점번호가 작은노드 부터 방문
void dfs(vector<vector<bool>> &g, vector<bool> &dfsVisited, int v) {
	cout << v+1 << " ";
	dfsVisited[v] = true;
	for(int i=0; i<g[v].size(); i++) {
		// 연결이 안되어 있을때
		if (!g[v][i]) continue;
		
		// 연결이 되어 있을때
		if (!dfsVisited[i]) dfs(g, dfsVisited, i); // 재귀
	}
}

// 큐에 먼저 넣고 방문확인, pop하기전 출력(실행), pop된 노드중 방문안된 정점번호가 작은노드부터 queue에 삽입.
void bfs(vector<vector<bool>> &g, vector<bool> &bfsVisited, int v){
	vector<int> queue;
	queue.push_back(v);  // 인덱스로 노드번호 큐에 넣기
	bfsVisited[v] = true;
	while (!queue.empty()) {
		int num = *(queue.begin());
		queue.erase(queue.begin());
		cout << num + 1 << " ";
		for(int i=0; i<g[num].size(); i++) {
			// 연결 안되어 있을때
			if (!g[num][i]) continue;
			
			//연결이 되어 있을때
			if (!bfsVisited[i]) {
				queue.push_back(i);
				bfsVisited[i] = true;
			}
		}
	}
}

/*
  1 2 3 4
1 0 0 0 0
2 0 0 0 0
3 0 0 0 0
4 0 0 0 0

*/
