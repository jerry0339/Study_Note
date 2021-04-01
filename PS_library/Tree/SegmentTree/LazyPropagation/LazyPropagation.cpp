// BOJ_10999
// segment tree lazy propagation

#include<bits/stdc++.h>
#define MAX 1000001
#define MAX_N 1000001
using namespace std;
typedef long long ll;

ll arr[MAX_N]{};
ll tree[MAX<<2]{};
ll lazy[MAX<<2]{};
ll N,M,K,T;

// 바뀐것 없음
ll init(ll n, ll s, ll e){
    if(s==e) return tree[n] = arr[s];
    ll mid = (s+e)>>1;
    return tree[n] = init(n<<1, s, mid) + init(n<<1|1, mid+1, e);
}

// lazy[n]을 tree[n]에 업데이트, lazy[n<<1], lazy[n<<1|1]에 전파
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

// [l,r]구간에 diff를 더하는 업데이트 요청
// 호출이 끝나면 현재 노드(n)는 valid여야 한다.
void lazyUpdate(ll n, ll s, ll e, ll l, ll r, ll diff) {
    propagate(n, s, e); // 전파 : 현재 노드를 유효하게 만듬
    if(r<s || e<l) return; // 범위 밖
    if(l<=s && e<=r){ // 현재구간[s,e]이 포함되어 있으면
        tree[n] += (e-s+1)*diff; // 현재 구간 갱신
        if(s!=e) { // 현재노드가 리프노드가 아닐경우 자식 update
            lazy[n<<1] += diff;
            lazy[n<<1|1] += diff;
        }
        return;
    }
    ll mid = (s+e)>>1;
    lazyUpdate(n<<1, s, mid, l, r, diff);
    lazyUpdate(n<<1|1, mid+1, e, l, r, diff);
    // (l<=s && e<=r) 조건에 포함되지 못한 범위의 tree[n]이 업데이트 됨
    // tree[n<<1], tree[n<<1|1] 은 모두 위의 재귀로 인해 valid 하므로
    tree[n] = tree[n<<1] + tree[n<<1|1];
}


ll query(ll n, ll s, ll e, ll l, ll r){
    propagate(n, s, e); // 현재노드의 lazy값 전파 -> valid
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