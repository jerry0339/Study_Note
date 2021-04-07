// 주식회사 승범이네 - BOJ_16404
// segTree Lazy Propagation , euler_tour_technique : 오일러 경로 테크닉

#include<bits/stdc++.h>
#define MAX_N 100000
#define MAX 100000
using namespace std;
typedef long long ll;

ll N,M;
vector<ll> adj[MAX_N+1]{};
ll parent[MAX_N+1]{};
ll st[MAX_N+1]{}, ed[MAX_N+1]{};
ll tree[(MAX+1)<<2]{};
ll lazy[(MAX+1)<<2]{};

void propagate(ll n, ll s, ll e) { 
    if(lazy[n]){
        tree[n] += (e-s+1)*lazy[n];
        if(s!=e){
            lazy[n<<1] += lazy[n];
            lazy[n<<1|1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

void lazyUpdate(ll n, ll s, ll e, ll l, ll r, ll diff) {
    propagate(n, s, e);
    if(r<s || e<l) return;
    if(l<=s && e<=r){
        tree[n] += (e-s+1)*diff;
        if(s!=e) {
            lazy[n<<1] += diff;
            lazy[n<<1|1] += diff;
        }
        return;
    }
    ll mid = (s+e)>>1;
    lazyUpdate(n<<1, s, mid, l, r, diff);
    lazyUpdate(n<<1|1, mid+1, e, l, r, diff);
    tree[n] = tree[n<<1] + tree[n<<1|1];
}


ll query(ll n, ll s, ll e, ll l, ll r){
    propagate(n, s, e);
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[n];
    ll mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) + query(n<<1|1, mid+1, e, l, r);
}

ll num = 1;
void dfs(ll now){
    st[now] = num;
    // 입력시 i노드의 부모노드가 입력으로 주어졌으므로 next가 부모인지 체크x
    for(auto next : adj[now]){
        num++;
        dfs(next);
    }
    ed[now] = num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ll t;
    cin>>t;
    parent[1] = 0;
    for(ll i=2; i<=N; i++){
        cin>>t;
        parent[i] = t;
        adj[t].push_back(i);
    }
    dfs(1);

    ll a,b,c;
    while(M--){
        cin>>a>>b;
        if(a==1) {
            cin>>c;
            lazyUpdate(1,1,N, st[b],ed[b] ,c);
        } else {
            cout<<query(1,1,N, st[b], st[b])<<'\n';
        }
    }
}