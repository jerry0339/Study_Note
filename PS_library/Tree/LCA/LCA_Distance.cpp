// <정점들의 거리> - BOJ_1761
// LCA, 거리계산

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define xx first
#define yy second
#define MAX_N 40000 // Check
using namespace std;
typedef pair<int,int> pii;

int N, M, maxPower = (int)floor(log2(MAX_N));
int ac[MAX_N+1][21]{};
int dist[MAX_N+1][21]{};
int vi[MAX_N+1]{};
int dpt[MAX_N+1]{};
vector<pii> adj[MAX_N+1]{};

void dfs(int now, int parent) {
    vi[now] = true;
    dpt[now] = dpt[parent] + 1;
    
    ac[now][0] = parent;
    for (int i = 1; i <= maxPower; i++){
        ac[now][i] = ac[ac[now][i-1]][i-1];
        dist[now][i] = dist[now][i-1] + dist[ac[now][i-1]][i-1]; // 거리계산 추가
    }

    for (auto next : adj[now]) {
        if (vi[next.xx]) continue;
        dist[next.xx][0] = next.yy; // 거리계산 추가
        dfs(next.xx, now);
    }
}

pii lca(int x, int y) { // pii(lca, x,y간의 거리) 반환
    int res = 0; // long long 또는 MOD확인
    if (dpt[x] > dpt[y]) swap(x, y);
    for (int i = maxPower; i >= 0; i--) {
        if (dpt[y] - dpt[x] >= (1 << i)){
            res += dist[y][i]; // 거리계산 추가
            y = ac[y][i];
        }
    }
    if (x == y) return pii(x,res);
    for (int i = maxPower; i >= 0; i--) {
        if (ac[x][i] != ac[y][i]) {
            res += (dist[x][i] + dist[y][i]); // 거리계산 추가
            x = ac[x][i];
            y = ac[y][i];
        }
    }
    res += (dist[x][0] + dist[y][0]);
    int lcaN = ac[x][0];
    return pii(lcaN, res);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    int x,y,c;
    for (int i = 0; i < N-1; i++) {
        cin>>x>>y>>c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    dfs(1, 0);

    cin>>M;
    while (M--) {
        cin>>x>>y;
        cout<<lca(x, y).yy<<'\n';
    }

}