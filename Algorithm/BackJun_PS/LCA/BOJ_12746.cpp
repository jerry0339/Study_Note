#include<bits/stdc++.h>
#define MAX 222222
using namespace std;

int N, M;
int ac[MAX+1][21]{};
int dpt[MAX+1]{};
vector<int> adj[MAX+1]{};
int cnt[MAX+1]{};

void dfs(int now, int parent) {
    dpt[now] = dpt[parent] + 1;
    ac[now][0] = parent;

    for (int i = 1; i <= 20LL; i++)
        ac[now][i] = ac[ac[now][i-1]][i-1];

    for (auto next : adj[now]) {
        if (next == parent) continue;
        dfs(next, now);
    }
}

int lca(int x, int y) {
    if (dpt[x] > dpt[y]) swap(x, y);
    for (int i = 20LL; i >= 0; i--) { 
        if (dpt[y] - dpt[x] >= (1 << i)) 
            y = ac[y][i];
    }
    if (x == y)return x;
    for (int i = 20LL; i >= 0; i--) {
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
        cnt[l]-=2;
    }

    dfs2(1, 0);
    int ans = 0;
    a=0, b=1;
	for(int i=2; i<=N; i++){
        if(ans < cnt[i]){
            ans = cnt[i];
            a = ac[i][0];
            b = i;
        } else if(ans == cnt[i]){
            int j = ac[i][0];
            if(i<a || j<a) a = i, b = j;
        } else continue;
        if(a>b) swap(a,b);
    }
    cout<<a<<' '<<b<<' '<<ans;
}
