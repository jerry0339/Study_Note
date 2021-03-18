// 트쿼2 - BOJ_13511
// LCA , sparse table를 이용한 노드의 k번째 조상 구하기

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define xx first
#define yy second
#define MAX_N 100000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll N, M, maxPower = (ll)floor(log2(MAX_N));
ll ac[MAX_N+1][21]{};
ll dist[MAX_N+1]{};
ll dpt[MAX_N+1]{};
vector<pll> adj[MAX_N+1]{};

void dfs(ll now, ll parent, ll nd) {
    dpt[now] = dpt[parent] + 1;
    ac[now][0] = parent;
    dist[now] = nd;

    for (ll i = 1; i <= maxPower; i++)
        ac[now][i] = ac[ac[now][i-1]][i-1];

    for (auto next : adj[now]) {
        if (next.xx == parent) continue;
        dfs(next.xx, now, nd + next.yy);
    }
}

ll lca(ll x, ll y) {
    if (dpt[x] > dpt[y]) swap(x, y);
    for (ll i = maxPower; i >= 0; i--) { 
        if (dpt[y] - dpt[x] >= (1 << i)) 
            y = ac[y][i];
    }
    if (x == y)return x; 
    for (ll i = maxPower; i >= 0; i--) {
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

    ll x,y,c;
    for (ll i = 0; i < N-1; i++) {
        cin>>x>>y>>c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    dfs(1, 0, 0);

    cin>>M;
    ll u,k;
    while (M--) {
        cin>>u>>x>>y;
        if(u==1){ // x,y거리
            ll common = lca(x, y);
            // y + x - lca*2 -> 간선개수 라고 생각
            cout<<dist[x] + dist[y] - dist[common]*2<<'\n';
        } else { // x,y 경로중 k번째 노드 구하기
            cin>>k;
            ll lcaN = lca(x, y);
            ll next;
            // 조건문 : x 또는 y에서부터 목적노드까지의 거리 k구하기
            if (dpt[x]-dpt[lcaN]+1 >= k) next=x, k--;
            else {
                next=y;
                // y + x - lca*2 -> 간선개수 라고 생각
                k = (dpt[y]+dpt[x] - dpt[lcaN]*2) - k + 1;
            }
            // sparse table 이용하여 노드next의 k번째 조상 구하기
            for (int i = maxPower; i >= 0; i--) {
                if ((1LL << i) <= k) {
                    k -= (1 << i);
                    next = ac[next][i];
                }
            }
            cout<<next<<'\n';
        }
    }

}