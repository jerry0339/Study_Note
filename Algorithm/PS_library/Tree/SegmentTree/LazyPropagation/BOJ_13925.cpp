// 13925 수열과 쿼리 13
// lazy prop
// *, + 가 같이 주워지는 구간쿼리 -> ax + b: lazy => (a,b) 이용

#include<bits/stdc++.h>
#define xx first
#define yy second
#define MAX 100001
#define MAX_N 100001
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll arr[MAX_N]{};
ll tree[MAX<<2]{};
pair<ll,ll> lazy[MAX<<2]{};
ll N,Q;

ll init(ll n, ll s, ll e){
    if(s==e) return tree[n] = arr[s];
    ll mid = (s+e)>>1;
    return tree[n] = (init(n<<1, s, mid) + init(n<<1|1, mid+1, e))%MOD;
}

void propagate(ll n, ll s, ll e) { 
    if(lazy[n].xx!=1 || lazy[n].yy!=0){
        tree[n] = (tree[n]*lazy[n].xx + (e-s+1)*lazy[n].yy)%MOD;
        if(s!=e){
            lazy[n<<1].xx = (lazy[n<<1].xx * lazy[n].xx)%MOD;
            lazy[n<<1].yy = (lazy[n<<1].yy * lazy[n].xx + lazy[n].yy)%MOD;
            lazy[n<<1|1].xx = (lazy[n<<1|1].xx * lazy[n].xx)%MOD;
            lazy[n<<1|1].yy = (lazy[n<<1|1].yy * lazy[n].xx + lazy[n].yy)%MOD;
        }
        lazy[n].xx = 1LL;
        lazy[n].yy = 0;
    }
}

// add(+)의 경우
// ax+b 에서 lazy = (a,b)인데 mul=c, add=d 쿼리가 온다면 ?
// (ax+b)c + d = acx + cb+d 이므로 lazy = (ac, cb+d) 로 업데이트 되어야 함
void lazyUpdate(ll n, ll s, ll e, ll l, ll r, ll mul, ll add) {
    propagate(n, s, e);
    if(r<s || e<l) return;
    if(l<=s && e<=r){
        tree[n] = (tree[n]*mul + (e-s+1)*add)%MOD;
        if(s!=e) {
            lazy[n<<1].xx = (lazy[n<<1].xx * mul)%MOD;
            lazy[n<<1].yy = (lazy[n<<1].yy * mul + add)%MOD; 
            lazy[n<<1|1].xx = (lazy[n<<1|1].xx * mul)%MOD;
            lazy[n<<1|1].yy = (lazy[n<<1|1].yy * mul + add)%MOD;
        }
        return;
    }
    ll mid = (s+e)>>1;
    lazyUpdate(n<<1, s, mid, l, r, mul, add);
    lazyUpdate(n<<1|1, mid+1, e, l, r, mul, add);
    tree[n] = (tree[n<<1] + tree[n<<1|1])%MOD;
}


ll query(ll n, ll s, ll e, ll l, ll r){
    propagate(n, s, e);
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return (tree[n])%MOD;
    ll mid = (s+e)>>1;
    return (query(n<<1, s, mid, l, r) + query(n<<1|1, mid+1, e, l, r))%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(ll i=1; i<=N; i++){
        cin>>arr[i];
    }
    init(1,1,N);
    fill(lazy, lazy+(MAX<<2), make_pair(1LL,0));

    cin>>Q;
    ll a,x,y,k;
    while(Q--){
        cin>>a>>x>>y;
        if(x>y) swap(x,y);
        
        if(a==1) { // 1*arr + k
            cin>>k;
            lazyUpdate(1, 1, N, x, y, 1LL, k);
        } else if(a==2){ // k*arr + 0
            cin>>k;
            lazyUpdate(1, 1, N, x, y, k, 0);
        } else if(a==3){ // 0*arr + k
            cin>>k;
            lazyUpdate(1, 1, N, x, y, 0, k);
        } else // arr[x] + ~ + arr[y]
            cout<<query(1, 1, N, x, y)<<'\n';
    }

    return 0;
}