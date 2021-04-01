// <XOR> - BOJ_12844
// seg lazy

#include<bits/stdc++.h>
#define MAX 1000001
#define MAX_N 1000001
using namespace std;
typedef long long ll;

ll arr[MAX_N]{};
ll tree[MAX<<2]{};
ll lazy[MAX<<2]{};
ll N,Q;

ll init(ll n, ll s, ll e){
    if(s==e) return tree[n] = arr[s];
    ll mid = (s+e)>>1;
    return tree[n] = init(n<<1, s, mid) ^ init(n<<1|1, mid+1, e);
}

// k를 xor연산할때 짝수번하면 그대로, 홀수번하면 k를 ^하는것과 같으므로 짝 홀 계산 해야함
// ex1) a^a = 0,   a^0 = a
// ex2) a^b^b = a, a^b = a^b
void propagate(ll n, ll s, ll e) { 
    if(lazy[n]){
        tree[n] ^= lazy[n]*((e-s+1)%2); // xor연산을 짝수 or 홀수 인지 계산해 주어야 함
        if(s!=e){
            lazy[n<<1] ^= lazy[n];
            lazy[n<<1|1] ^= lazy[n];
        }
        lazy[n] = 0;
    }
}

void lazyUpdate(ll n, ll s, ll e, ll l, ll r, ll diff) {
    propagate(n, s, e);
    if(r<s || e<l) return;
    if(l<=s && e<=r){
        tree[n] ^= diff*((e-s+1)%2); // xor연산을 짝수 or 홀수 인지 계산해 주어야 함
        if(s!=e) {
            lazy[n<<1] ^= diff;
            lazy[n<<1|1] ^= diff;
        }
        return;
    }
    ll mid = (s+e)>>1;
    lazyUpdate(n<<1, s, mid, l, r, diff);
    lazyUpdate(n<<1|1, mid+1, e, l, r, diff);
    tree[n] = tree[n<<1] ^ tree[n<<1|1];
}


ll query(ll n, ll s, ll e, ll l, ll r){
    propagate(n, s, e);
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[n];
    ll mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) ^ query(n<<1|1, mid+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(ll i=0; i<N; i++){
        cin>>arr[i];
    }
    init(1,0,N-1);
    
    cin>>Q;
    ll a,x,y,k;
    while(Q--){
        cin>>a>>x>>y;
        if(x>y) swap(x,y);
        if(a==1) {
            cin>>k;
            lazyUpdate(1, 0, N-1, x, y, k);
        }
        else cout<<query(1, 0, N-1, x, y)<<'\n';
    }

    return 0;
}