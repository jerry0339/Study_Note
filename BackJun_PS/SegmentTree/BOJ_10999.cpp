// BOJ_10999
// segment tree lazy propagation

#include<bits/stdc++.h>
#define MAX 1000001
#define MAX_N 1000001
using namespace std;
typedef long long ll;

ll arr[MAX_N]{};
ll tree[MAX<<2]{};
ll lazy[MAX_N<<2]{};
ll N,M,K,T;

ll init(ll n, ll s, ll e){
    if(s==e) return tree[n] = arr[s];
    ll mid = (s+e)>>1;
    return tree[n] = init(n<<1, s, mid) + init(n<<1|1, mid+1, e);
}

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

void lazyUpdate(ll n, ll s, ll e, ll l, ll r, ll add) {
    propagate(n,s,e);
    if(r<s || l>e) return;
    if(l<=s && e<=r){
        tree[n] += (e-s+1)*add;
        if(s!=e){
            lazy[n<<1] += add;
            lazy[n<<1|1] += add;
        }
        return;
    }
    ll mid = (s+e)>>1;
    lazyUpdate(n<<1, s, mid, l, r, add);
    lazyUpdate(n<<1|1, mid+1, e, l, r,add);
    tree[n] = tree[n<<1]+tree[n<<1|1];
}

ll query(ll n, ll s, ll e, ll l, ll r){
    propagate(n, s, e);
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[n];
    ll mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) + query(n<<1|1, mid+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(ll i=1; i<=N; i++){
        cin>>arr[i];
    }
    init(1,1,N);

    ll a,x,y,diff;
    T = M+K;
    while(T--){
        cin>>a>>x>>y;
        if(x>y) swap(x,y);
        if(a==1) {
            cin>>diff;
            lazyUpdate(1, 1, N, x, y, diff);
        }
        else cout<<query(1, 1, N, x, y)<<'\n';
    }

    return 0;
}