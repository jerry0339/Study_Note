// LCA, 오일러투어테크닉, 세그트리

#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int N, M, maxPower = (int)floor(log2(MAX));
int ac[MAX+1][21]{};
int dpt[MAX+1]{};
vector<int> adj[MAX+1]{};
int st[MAX+1]{}, ed[MAX+1]{};
int tree[MAX<<2]{};

int num = 0;
void dfs(int now, int parent) {
    st[now] = ++num;
    dpt[now] = dpt[parent] + 1;
    ac[now][0] = parent;

    for (int i = 1; i <= maxPower; i++)
        ac[now][i] = ac[ac[now][i-1]][i-1];

    for (auto next : adj[now]) {
        if (next == parent) continue;
        dfs(next, now);
    }
    ed[now] = num;
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

void modify(int n, int s, int e, int idx, int diff){
    if(idx<s || idx>e) return;
    tree[n] += diff;
    if(s==e) return;
    int mid = (s+e)>>1;
    modify(n<<1, s, mid, idx, diff);
    modify(n<<1|1, mid+1, e, idx, diff);
}

int query(int n, int s, int e, int l, int r){
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[n];
    int mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) + query(n<<1|1, mid+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b;
    for(int i=2; i<=N; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);

    char ch;
    while(M--){
        cin>>ch;
        cin>>a>>b;
        int next;
        if(ch=='P') {
            next = lca(a,b);
            modify(1,1,N, st[next],-2);
            modify(1,1,N, st[a],1);
            modify(1,1,N, st[b],1);
        } else {
            if(st[a] < st[b]) next = b;
            else next = a;
            cout<<query(1,1,N, st[next], ed[next])<<'\n';
        }
    }
}