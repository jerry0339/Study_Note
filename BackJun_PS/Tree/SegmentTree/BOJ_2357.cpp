// <최솟값과 최댓값> - BOJ_2357
// 세그먼트 트리 - 최소,최댓값

#include<bits/stdc++.h>
#define MAX_N 100001
using namespace std;
typedef long long ll;
const long long INF = 1e9;

ll N,Q;
ll mint[MAX_N * 2]{};
ll maxt[MAX_N * 2]{};

void init() {
    for (ll i = N-1; i > 0; --i){
        mint[i] = min(mint[i << 1], mint[i << 1 | 1]);
    }

    for (ll i = N-1; i > 0; --i){
        maxt[i] = max(maxt[i << 1], maxt[i << 1 | 1]);
    }
}

ll minQuery(ll l, ll r) {
    ll ans = INF;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = min(ans, mint[l++]);
        if (r & 1) ans = min(ans, mint[--r]);
    }
    return ans;
}

ll maxQuery(ll l, ll r) {
    ll ans = 1;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, maxt[l++]);
        if (r & 1) ans = max(ans, maxt[--r]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for (ll i = 0; i < N; ++i) {
        cin>>mint[N+i];
        maxt[N+i] = mint[N+i];
    }
    init();

    ll a,b;
    while(Q--){
        cin>>a>>b;
        if(a>b) swap(a,b);
        cout<<minQuery(a-1,b)<<' ';
        cout<<maxQuery(a-1,b)<<'\n';        
    }
}