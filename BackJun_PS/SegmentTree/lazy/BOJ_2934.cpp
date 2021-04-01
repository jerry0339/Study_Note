// LRH식물 - BOJ_2934
// lazy prop

#include<bits/stdc++.h>
#define MAX 100001
#define MAX_N 100001
using namespace std;
typedef long long ll;

ll cost[MAX_N]{};
ll tree[MAX<<2]{};
ll lazy[MAX<<2]{};
ll N;

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll a,b;
    for(ll i=1; i<=N; i++){
        cin>>a>>b;
        ll x = query(1, 1, MAX, a, a);
        ll y = query(1, 1, MAX, b, b);
        cout<<(x-cost[a]) + (y-cost[b])<<'\n';
        cost[a] += (x-cost[a]);
        cost[b] += (y-cost[b]);
        lazyUpdate(1, 1, MAX, a+1, b-1, 1);
    }
}