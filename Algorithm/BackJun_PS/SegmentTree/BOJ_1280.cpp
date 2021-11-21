#include<bits/stdc++.h>
#define MAX 200000
#define MAX_N 200000
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll tree[MAX+1]{};
ll cnt[MAX+1]{};
ll N,SZ=0;

ll query(ll arr[], ll idx){
	ll ret = 0;
	while(idx > 0){
		ret += arr[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

void update(ll arr[], ll idx, ll diff){
	while(idx <= MAX){
		arr[idx] += diff;
		idx += (idx & -idx);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll t, res=1;
    cin>>t; t++;
    SZ = t;
    update(tree,t,t);
    update(cnt,t,1);
    for(ll i=2; i<=N; i++){
        cin>>t; t++;
        SZ = max(SZ, t);
        ll lsum = 0, rsum = 0, lcnt = 0, rcnt = 0, total = 0;
        lsum = query(tree, t-1);
        lcnt = query(cnt, t-1);
        rsum = query(tree, MAX) - lsum;
        rcnt = query(cnt, MAX) - lcnt;
        total = ((lcnt*t) - (lsum))%MOD;
        total = ((total + rsum) - (rcnt*t))%MOD;
        res = (res * total)%MOD;
        update(tree,t,t);
        update(cnt,t,1);
    }
    cout<<(res)%MOD;
}