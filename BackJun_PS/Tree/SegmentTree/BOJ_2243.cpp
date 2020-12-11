// <사탕상자> - BOJ_2243
// segment Tree

#include<bits/stdc++.h>
#define MAX_N 1000000
using namespace std;
typedef long long ll;

ll arr[MAX_N]{}, tree[MAX_N<<2]{};
ll N,Q;

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

ll query(ll n, ll s, ll e, ll val){
    if(val>tree[n]) return 0;
    if(s==e) return s;
    ll mid = (s+e)>>1;
    if(val <= tree[n<<1]) return query(n<<1, s, mid, val);
    return query(n<<1|1, mid+1, e, val-tree[n<<1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>Q;

    ll a,b,c;
    while(Q--){
        cin>>a;
        if(a==1){
            cin>>b;
            c = query(1,1,MAX_N,b);
            modify(1,1,MAX_N,c,-1);
            cout<<c<<'\n';
        } else {
            cin>>b>>c;
            modify(1,1,MAX_N,b,c);
        }

    }

    return 0;
}