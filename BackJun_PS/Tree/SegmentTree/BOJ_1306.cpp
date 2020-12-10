// <달려라 홍준> - BOJ_1306
// 세그먼트 트리 (max)

#include<bits/stdc++.h>
#define MAX_N 1000001
using namespace std;
typedef long long ll;

ll N,M;
ll t[MAX_N * 2]{};

void init() {
    for (ll i = N-1; i > 0; --i){
        t[i] = max(t[i<<1], t[i<<1|1]);
    }
}

ll query(ll l, ll r) {
    ll ans = 1;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, t[l++]);
        if (r & 1) ans = max(ans, t[--r]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for (ll i = 0; i < N; ++i) {
        cin>>t[N + i];
    }
    init();

    for(ll i=M-1; i<N-M+1; i++) {
        cout<<query(i-M+1, i+M)<<' ';
    }
}