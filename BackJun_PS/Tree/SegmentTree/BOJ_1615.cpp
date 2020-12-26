//<교차 개수 세기> - BOJ_1615
// 세그먼트트리

#include<bits/stdc++.h>
#define xx first
#define yy second
#define MAX 2000
#define MAX_N 2000001
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll N,M;
ll arr[MAX]{}, tree[MAX<<2]{};
pll t[MAX_N]{};

ll init(ll n, ll s, ll e){
    if(s==e) return tree[n] = arr[s];
    ll mid = (s+e)>>1;
    return tree[n] = init(n<<1, s, mid) + init(n<<1|1, mid+1, e);
}

void modify(ll n, ll s, ll e, ll idx, ll diff){
    if(idx<s || idx>e) return;
    tree[n] += diff;
    if(s==e) return;
    ll mid = (s+e)>>1;
    modify(n<<1, s, mid, idx, diff);
    modify(n<<1|1, mid+1, e, idx, diff);
}

ll query(ll n, ll s, ll e, ll l, ll r){
    if(s>r || e<l) return 0;
    if(l<=s && r>=e) return tree[n];
    ll mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) + query(n<<1|1, mid+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ll a,b;

    for(int i=0; i<M; i++) {
        cin>>t[i].xx>>t[i].yy;
        arr[t[i].yy]++;
    }
    sort(t,t+M);
    init(1LL, 1LL, N);

    ll ans = 0;
    for(int i=0; i<M; i++) {
        ll val = t[i].yy;
        modify(1LL, 1LL, N, t[i].yy, -1LL);
        if(val==1LL) continue;
        ans+=query(1LL, 1LL, N, 1LL, val-1LL);
    }
    cout<<ans;
}