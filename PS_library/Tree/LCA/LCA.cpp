#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define MAX_N 100000 // 노드 최대 개수
using namespace std;

int N, M, maxPower = (int)floor(log2(MAX_N));
int ac[MAX_N+1][21]{};
int vi[MAX_N+1]{};
int dpt[MAX_N+1]{};
vector<int> adj[MAX_N+1]{};

void dfs(int now, int parent) {
    vi[now] = true;
    dpt[now] = dpt[parent] + 1;
    
    ac[now][0] = parent;
    for (int i = 1; i <= maxPower; i++) 
        ac[now][i] = ac[ac[now][i-1]][i-1];

    for (int next : adj[now]) {
        if (vi[next]) continue;
        dfs(next, now);
    }
}

int lca(int x, int y) {
    if (dpt[x] > dpt[y]) swap(x, y);
    for (int i = maxPower; i >= 0; i--) { 
        if (dpt[y] - dpt[x] >= (1 << i)) 
            y = ac[y][i];
    }
    if (x == y)return x; 
    for (int i = maxPower; i >= 0; i--) {
        if (ac[x][i] != ac[y][i]) {
            x = ac[x][i];
            y = ac[y][i];
        }
    }
    return ac[x][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    int x,y;
    for (int i = 0; i < N-1; i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    cin>>M;
    while (M--) {
        cin>>x>>y;
        cout<<lca(x, y)<<'\n';
    }
}