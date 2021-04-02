#include<bits/stdc++.h>
#define MAX 200001
#define MAX_N 200001
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll tree[MAX<<2]{};
ll cnt[MAX<<2]{};
ll N;

void modify(ll n, ll s, ll e, ll idx, ll diff){
    if(idx<s || idx>e) return;
    tree[n] = tree[n] + diff;
    if(s==e) return;
    ll mid = (s+e)>>1;
    modify(n<<1, s, mid, idx, diff);
    modify(n<<1|1, mid+1, e, idx, diff);
}

ll query(ll n, ll s, ll e, ll l, ll r){
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[n];
    ll mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) + query(n<<1|1, mid+1, e, l, r);
}

ll query2(ll n, ll s, ll e, ll l, ll r){
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return cnt[n];
    ll mid = (s+e)>>1;
    return query2(n<<1, s, mid, l, r) + query2(n<<1|1, mid+1, e, l, r);
}

void modify2(ll n, ll s, ll e, ll idx, ll diff){
    if(idx<s || idx>e) return;
    cnt[n] = cnt[n] + diff;
    if(s==e) return;
    ll mid = (s+e)>>1;
    modify2(n<<1, s, mid, idx, diff);
    modify2(n<<1|1, mid+1, e, idx, diff);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll t, res=1;
    cin>>t; t++;
    modify(1,1,MAX,t,t);
    modify2(1,1,MAX,t,1);
    for(ll i=2; i<=N; i++){
        cin>>t; t++;
        ll lsum = 0, rsum = 0, lcnt = 0, rcnt = 0;
        ll ltotal = 0, rtotal = 0, total = 0;
        lsum = query(1,1,MAX,1,t-1);
        lcnt = query2(1,1,MAX,1,t-1);
        rsum = query(1,1,MAX,t,MAX);
        rcnt = query2(1,1,MAX,t,MAX);
        ltotal = ((lcnt*t) - lsum)%MOD;
        rtotal = (rsum - (rcnt*t))%MOD;
        total = (ltotal + rtotal)%MOD;
        res = (res * total)%MOD;
        modify(1,1,MAX,t,t);
        modify2(1,1,MAX,t,1);
    }
    cout<<(res)%MOD;
}