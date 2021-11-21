// <커피숍 2> - BOJ_1275
// 세그먼트 트리 easy버전 (비재귀)
// 비재귀 세그는 GCD트리의 갱신을 못한다? - 확인해봐야 함

#include<bits/stdc++.h>
#define MAX_N 100001 // need to update 'MAX_N'
using namespace std;
typedef long long ll;
const long long INF = 1e9;

ll N,Q;
ll t[MAX_N * 2]{};

void init() {
    for (ll i = N-1; i > 0; --i){
        t[i] = t[i << 1] + t[i << 1 | 1];
    }
}

// input pos는 0부터 인자값으로 받음
void modify(ll pos, ll val) {
    t[pos + N] = val;
    for (pos += N; pos > 1; pos >>= 1) {
        t[pos >> 1] = t[pos] + t[pos ^ 1];
    }
}

// input l은 0부터 인자값으로 받음
ll query(ll l, ll r) { // [l, r)
    ll ans = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans += t[l++];
        if (r & 1) ans += t[--r];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for (ll i = 0; i < N; ++i) {
        cin>>t[N + i]; // a[0] => a[n]
    }
    init();
    ll x,y,a,b;
    while(Q--){
        cin>>x>>y>>a>>b;
        // query(sum)함수 실행시에만 조건:x<y 고려
        if(x>y) {
            ll t = x;
            x = y;
            y = t;
        }
        cout<<query(x-1,y)<<'\n';
        modify(a-1,b);
    }
}