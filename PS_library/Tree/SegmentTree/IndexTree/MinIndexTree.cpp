#include<bits/stdc++.h>
#define MAX_N 100001
using namespace std;
const int INF = 0x3f3f3f3f;

int arr[MAX_N]{};
int tree[MAX_N<<2]{};
int N,Q;

int initMin(int n, int s, int e){
    if(s==e) return tree[n] = s;
    int mid = (s+e)>>1;
    int x = initMin(n<<1, s, mid);
    int y = initMin(n<<1|1, mid+1, e);
    if(x>y) swap(x,y);
    if(arr[x] <= arr[y]) return tree[n] = x;
    else return tree[n] = y;
}

int minModify(int n, int s, int e, int idx){
    if(idx<s || idx>e) return tree[n];
    if(s==e) return tree[n] = idx;
    int mid = (s+e)>>1;
    int x = minModify(n<<1, s, mid, idx);
    int y = minModify(n<<1|1, mid+1, e, idx);
    if(x>y) swap(x,y);
    if(arr[x] <= arr[y]) return tree[n] = x;
    else return tree[n] = y;
}

int minQuery(int n, int s, int e, int l, int r){
    if(l>e || r<s) return 0; // arr[0] = INF
    if(l<=s && e<=r) return tree[n];
    int mid = (s+e)>>1;
    int x = minQuery(n<<1, s, mid, l, r);
    int y = minQuery(n<<1|1, mid+1, e, l, r);
    if(x>y) swap(x,y);
    if(arr[x] <= arr[y]) return x;
    else return y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++) cin>>arr[i];
    arr[0] = INF;
    initMin(1,1,N);

    cin>>Q;
    int k,a,b;
    while(Q--){
        cin>>k>>a>>b;
        if(k==1){
            arr[a] = b;
            minModify(1,1,N, a);
        } else {
            cout<<minQuery(1,1,N, a, b)<<'\n';
        }
    }
    
}