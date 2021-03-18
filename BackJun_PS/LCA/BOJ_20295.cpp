// <사탕 배달> - BOJ_20295
// LCA, Bitmask

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define MAX_N 100000 // 노드 최대 개수
using namespace std;

int N, M, maxPower = (int)floor(log2(MAX_N));
int store[MAX_N+1]{};
int ac[MAX_N+1][21]{};
int candy[MAX_N+1][21]{};
int dpt[MAX_N+1]{};
vector<int> adj[MAX_N+1]{};

void dfs(int now, int parent) {
    dpt[now] = dpt[parent] + 1;
    ac[now][0] = parent;

    for (int i = 1; i <= maxPower; i++){
        ac[now][i] = ac[ac[now][i-1]][i-1];
        candy[now][i] = (candy[now][i-1] | candy[ac[now][i-1]][i-1]);
    }

    for (int next : adj[now]) {
        if (next == parent) continue;
        candy[next][0] = (1<<store[next]) | (1<<store[now]);
        dfs(next, now);
    }
}

bool lca(int x, int y, int need) {
    if(x==y) return store[x]==need;
    need = (1<<need);
    int can = 0;
    if (dpt[x] > dpt[y]) swap(x, y);
    for (int i = maxPower; i >= 0; i--) { 
        if (dpt[y] - dpt[x] >= (1 << i)){
            can |= candy[y][i];
            if(can & need) return true;
            y = ac[y][i];
        }
    }
    if (x == y)return false;
    for (int i = maxPower; i >= 0; i--) {
        if (ac[x][i] != ac[y][i]) {
            can |= (candy[x][i] | candy[y][i]);
            if(can & need) return true;
            x = ac[x][i];
            y = ac[y][i];
        }
    }
    can |= (candy[x][0] | candy[y][0]);
    return can & need;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>store[i];
        store[i]--;
    }

    int x,y;
    for (int i = 0; i < N-1; i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    candy[1][0] = (1<<store[1]);
    dfs(1, 0);

    cin>>M; M--;
    int pre;
    cin>>pre>>y;
    bool chk=false;
    for(int i=1; i<=N; i++) {
        if(store[i]==y-1){
            cout<<"PLAY"<<'\n';
            chk = true;
            break;
        }
    }
    if(!chk) cout<<"CRY"<<'\n';

    while (M--) {
        cin>>x>>y;
        y--;
        if(lca(pre, x, y)) cout<<"PLAY"<<'\n';
        else cout<<"CRY"<<'\n';
        pre = x;
    }
}