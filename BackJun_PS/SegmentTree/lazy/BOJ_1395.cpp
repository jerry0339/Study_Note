// 스위치 - BOJ_1395
// segtree lazy propagation

#include<bits/stdc++.h>
#define MAX 100001
#define MAX_N 100001
using namespace std;

int tree[MAX<<2]{};
int lazy[MAX<<2]{};
int N,M;

void propagate(int n, int s, int e) { 
    if(lazy[n]){
        tree[n] = (e-s+1)-tree[n];
        if(s!=e){
            lazy[n<<1] ^= 1;
            lazy[n<<1|1] ^= 1;
        }
        lazy[n] = 0;
    }
}

void lazyUpdate(int n, int s, int e, int l, int r) {
    propagate(n, s, e);
    if(r<s || e<l) return;
    if(l<=s && e<=r){
        tree[n] = (e-s+1)-tree[n];
        if(s!=e) {
            lazy[n<<1] ^= 1;
            lazy[n<<1|1] ^= 1;
        }
        return;
    }
    int mid = (s+e)>>1;
    lazyUpdate(n<<1, s, mid, l, r);
    lazyUpdate(n<<1|1, mid+1, e, l, r);
    tree[n] = tree[n<<1] + tree[n<<1|1];
}


int query(int n, int s, int e, int l, int r){
    propagate(n, s, e);
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[n];
    int mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) + query(n<<1|1, mid+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b,c;
    while(M--){
        cin>>a>>b>>c;
        if(!a) lazyUpdate(1,1,N,b,c);
        else cout<<query(1,1,N,b,c)<<'\n';
    }
}