//<DFS와 BFS> - 1260
// 인접리스트
#include <bits/stdc++.h>
using namespace std;
// ***인접리스트는 오름차순으로 정렬된 형태로 link되어 있음***


// 출력(실행)후 방문확인, 이후 방문안된 정점번호가 작은노드 부터 방문
void dfs(vector<list<int>> &v, vector<bool> &vi, int st){
    cout<<st<<' ';
    vi[st] = true;
    for(int val : v[st]){
        if (!vi[val]) dfs(v,vi,val);
    }
}

// 큐에 먼저 넣고 방문확인, pop하기전 출력(실행), pop된 노드와 연결된 노드중 방문안된 정점번호가 작은노드부터 queue에 삽입.
void bfs(vector<list<int>> &v, vector<bool> &vi, int st){
    queue<int> q;
    q.push(st);
    vi[st] = true;
    while(!q.empty()){
        int n = q.front();
        cout<<n<<' ';
        q.pop();

        for(int val : v[n]){
            if(!vi[val]) {
                q.push(val);
                vi[val] = true;
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, st;
	cin >> n >> m >> st; // n : 정점개수 , m : 간선개수 , st : 시작노드인덱스
    vector<list<int>> v(n+1);
    vector<bool> vi(n+1);

	while (m--) {
		int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
	}

    for(int i=1; i<=n; i++) // 인접리스트 정렬
        v[i].sort();

    dfs(v,vi,st);

    vi.clear(); // bfs를 위한 방문여부 초기화
    vi.assign(n+1,false);
    cout<<"\n";
    
    bfs(v,vi,st);
}