// BOJ_12895
// Bitmask , segtree lazy propagation

#include<bits/stdc++.h>
#define MAX 100001
#define MAX_N 100001
using namespace std;

int tree[MAX<<2]{};
int lazy[MAX<<2]{};
int N,T,Q;

void propagate(int n, int s, int e) { 
    if(lazy[n]>=0){
        tree[n] = (1<<lazy[n]);
        if(s!=e){
            lazy[n<<1] = lazy[n];
            lazy[n<<1|1] = lazy[n];
        }
        lazy[n] = -1;
    }
}

void lazyUpdate(int n, int s, int e, int l, int r, int k) {
    propagate(n, s, e);
    if(r<s || e<l) return;
    if(l<=s && e<=r){
        tree[n] = (1<<k);
        if(s!=e) {
            lazy[n<<1] = k;
            lazy[n<<1|1] = k;
        }
        return;
    }
    int mid = (s+e)>>1;
    lazyUpdate(n<<1, s, mid, l, r, k);
    lazyUpdate(n<<1|1, mid+1, e, l, r, k);
    tree[n] = tree[n<<1] | tree[n<<1|1];
}

int query(int n, int s, int e, int l, int r){
    propagate(n, s, e);
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[n];
    int mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) | query(n<<1|1, mid+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(tree,tree+(MAX<<2),1);
    cin>>N>>T>>Q;
    
    char a;
    int x,y,k;
    while(Q--){
        cin>>a;
        cin>>x>>y;
        if(x>y) swap(x,y);
        if(a=='C') {
            cin>>k;
            lazyUpdate(1,1,N,x,y,k-1);
        } else {
            int mask = query(1,1,N,x,y);
            int sum = 0;
            for(int i=0; i<T; i++){
                if(mask&(1<<i)) sum++;
            }
            cout<<sum<<'\n';
        }
        
    }

    return 0;
}