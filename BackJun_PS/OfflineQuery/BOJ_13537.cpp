// 세그먼트트리, Offline query

#include<bits/stdc++.h>
#define xx first
#define yy second
#define MAX 100000
#define MAX_N 100000
using namespace std;
typedef pair<int,int> pii;

struct Info{
    int i,j,k,p;
    bool operator<(const Info &t) const{
        return k > t.k;
    }
    Info(int i, int j, int k, int p): i(i), j(j), k(k), p(p){}
};

vector<pii> arr;
vector<Info> qu;
int tree[(MAX+1)<<2]{};
int ans[MAX_N+1]{};
int N,Q;

void modify(int n, int s, int e, int idx, int diff){
    if(idx<s || idx>e) return;
    tree[n] += diff;
    if(s==e) return;
    int mid = (s+e)>>1;
    modify(n<<1, s, mid, idx, diff);
    modify(n<<1|1, mid+1, e, idx, diff);
}

int query(int n, int s, int e, int l, int r){
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[n];
    int mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) + query(n<<1|1, mid+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int t;
    for(int i=0; i<N; i++) {
        cin>>t;
        arr.push_back({t,i});
    }
    sort(arr.begin(), arr.end());
    
    cin>>Q;
    int i,j,k;
    for(int z=0; z<Q; z++){
        cin>>i>>j>>k;
        qu.push_back(Info(i,j,k,z));
    }
    sort(qu.begin(),qu.end());

    int pre = N;
    for(int x = 0; x<qu.size(); x++){
        int idx = upper_bound(arr.begin(), arr.end(), pii(qu[x].k, 1e6)) - arr.begin();
        for(int y = idx; y<pre; y++)
            modify(1,0,N-1, arr[y].yy, 1);
        pre = idx;
        ans[qu[x].p] = query(1,0,N-1, qu[x].i-1, qu[x].j-1);
    }

    for(int z=0; z<Q; z++) cout<<ans[z]<<'\n';
}