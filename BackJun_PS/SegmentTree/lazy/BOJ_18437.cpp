#include<bits/stdc++.h>
#define MAX 100001
#define MAX_N 100001
using namespace std;

vector<int> adj[MAX_N]{};
int st[MAX_N]{}, ed[MAX_N]{};
int tree[MAX<<2]{};
int lazy[MAX<<2]{};
int N,M;

int init(int n, int s, int e){
    if(s==e) return tree[n] = 1;
    int mid = (s+e)>>1;
    return tree[n] = init(n<<1, s, mid) + init(n<<1|1, mid+1, e);
}

void propagate(int n, int s, int e) { 
    if(lazy[n]!=-1){
        tree[n] = (e-s+1)*lazy[n];
        if(s!=e){
            lazy[n<<1] = lazy[n];
            lazy[n<<1|1] = lazy[n];
        }
        lazy[n] = -1;
    }
}

void lazyUpdate(int n, int s, int e, int l, int r, int diff) {
    propagate(n, s, e);
    if(r<s || e<l) return;
    if(l<=s && e<=r){
        tree[n] = (e-s+1)*diff;
        if(s!=e) {
            lazy[n<<1] = diff;
            lazy[n<<1|1] = diff;
        }
        return;
    }
    int mid = (s+e)>>1;
    lazyUpdate(n<<1, s, mid, l, r, diff);
    lazyUpdate(n<<1|1, mid+1, e, l, r, diff);
    tree[n] = tree[n<<1] + tree[n<<1|1];
}


int query(int n, int s, int e, int l, int r){
    propagate(n, s, e);
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[n];
    int mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) + query(n<<1|1, mid+1, e, l, r);
}

int num = 0;
void dfs(int now){
    st[now] = ++num;
    for(auto next : adj[now])
        dfs(next);
    
    ed[now] = num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int t;
    for(int i=1; i<=N; i++){
        cin>>t;
        adj[t].push_back(i);
    }

    init(1,1,N);
    memset(lazy,-1,sizeof(lazy));
    dfs(1);

    int a,x;
    cin>>M;
    while(M--){
        cin>>a>>x;
        if(a==1) {
            lazyUpdate(1,1,N,st[x]+1,ed[x],1);
        } else if(a==2){
            lazyUpdate(1,1,N,st[x]+1,ed[x],0);
        } else {
            cout<<query(1,1,N,st[x]+1,ed[x])<<'\n';
        }
    }
}