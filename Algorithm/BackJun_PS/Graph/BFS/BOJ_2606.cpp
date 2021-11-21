// <바이러스> - BOJ_2606
// 실버 기본문제
// adj를 이용한 그래프탐색 - BFS

#include<bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define aa first
#define bb second
using namespace std;

int N, M;
vector<vector<int>> adj;
bool vi[101]{};

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vi[start] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<adj[cur].size(); i++){
            if(vi[adj[cur][i]])continue;
            q.push(adj[cur][i]);
            vi[adj[cur][i]] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    adj.resize(N + 1);

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);
    int n = 0;
    for (int i = 1; i <= N; i++) {
        if (vi[i])n++;
    }
    cout << n-1;
}