#include<bits/stdc++.h>
#define MAX 50000
using namespace std;

int N, M;
int ac[MAX+1][21]{};
int dpt[MAX+1]{};
vector<int> adj[MAX+1]{};
int cnt[MAX+1]{};

void dfs(int now, int parent) {
    dpt[now] = dpt[parent] + 1;
    ac[now][0] = parent;

    for (int i = 1; i <= 20; i++)
        ac[now][i] = ac[ac[now][i-1]][i-1];

    for (auto next : adj[now]) {
        if (next == parent) continue;
        dfs(next, now);
    }
}

int lca(int x, int y) {
    if (dpt[x] > dpt[y]) swap(x, y);
    for (int i = 20; i >= 0; i--) { 
        if (dpt[y] - dpt[x] >= (1 << i)) 
            y = ac[y][i];
    }
    if (x == y)return x;
    for (int i = 20; i >= 0; i--) {
        if (ac[x][i] != ac[y][i]) {
            x = ac[x][i];
            y = ac[y][i];
        }
    }
    return ac[x][0];
}

void dfs2(int now, int par){
	for(auto &i : adj[now]){
		if(i != par) dfs2(i, now), cnt[now] += cnt[i];
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b;
    for(int i=1; i<N; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);

    while(M--){
        cin>>a>>b;
        int l = lca(a,b);
        cnt[a]++;
        cnt[b]++;
        cnt[l]--;
        cnt[ac[l][0]]--;
    }

    dfs2(1, 0);
	cout << *max_element(cnt + 1, cnt + N + 1);
}
