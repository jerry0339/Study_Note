#include<bits/stdc++.h>
#define MAX_N 100001 // MAX값 확인
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f+1LL;

ll N,D;
ll arr[MAX_N]{};
ll tree[MAX_N<<2]{};

ll modify(ll n, ll s, ll e, ll idx, ll val){
    if(idx<s || idx>e) return tree[n];
    if(s==e) return tree[n] = val;
    ll mid = (s+e)>>1;
    return tree[n] = max(modify(n<<1, s, mid, idx, val), modify(n<<1|1, mid+1, e, idx, val));
}

ll query(ll n, ll s, ll e, ll l, ll r){
    if(l>e || r<s) return -INF;
    if(l<=s && e<=r) return tree[n];
    ll mid = (s+e)>>1;
    return max(query(n<<1, s, mid, l, r) , query(n<<1|1, mid+1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>D;
    memset(tree, 0xc0, sizeof(tree));
    for(ll i=1; i<=N; i++){
        cin>>arr[i];
    }
    
    modify(1,1,N, 1, arr[1]);
    for(ll i=2; i<=N; i++){
        ll l = i-D;
        if(l<1) l = 1;
        ll pre = query(1,1,N, l,i-1);
        if(pre > 0) modify(1,1,N, i, pre+arr[i]);
        else modify(1,1,N, i, arr[i]);
    }

    cout<<query(1,1,N, 1,N);
}