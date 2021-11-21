#include<bits/stdc++.h>
#define MAX 500001
#define MAX_N 500001
using namespace std;

int arr[MAX_N]{};
int tree[MAX<<2]{};
int N;

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

int a[MAX_N]{}, bb[1000002]{};
int res[MAX_N]{};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int t;
    for(int i=0; i<N; i++) cin>>a[i];
    for(int i=0; i<N; i++){
        cin>>t;
        bb[t] = i;
    }

    for(int i=0; i<N; i++){
        arr[i] = bb[a[i]];
    }

    for(int i=0; i<N; i++){
        modify(1, 0, N-1, arr[i], 1);
        res[i] = query(1, 0, N-1, arr[i]+1, N-1);
    }

    long long ans=0;
    for(int i=0; i<N; i++) ans += (long long)res[i];
    cout<<ans;
}