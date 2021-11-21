#include<bits/stdc++.h>
#define MAX 100001 // MAX값 확인 (segTree)
#define MAX_N 100001 // MAX_N값 확인 (N개수)
using namespace std;

int arr[MAX_N]{};
int tree[MAX<<2]{};
int N,Q;

/*
int init(int n, int s, int e){
    if(s==e) return tree[n] = arr[s];
    int mid = (s+e)>>1;
    return tree[n] = min(init(n<<1, s, mid), init(n<<1|1, mid+1, e));
}
*/

int init(int n, int s, int e){
    if(s==e) return tree[n] = s;
    int mid = (s+e)>>1;
    int x = init(n<<1, s, mid);
    int y = init(n<<1|1, mid+1, e);
    if(x>y) swap(x,y);
    if(arr[x] <= arr[y]) return tree[n] = x;
    else return tree[n] = y;
}

int modify(int n, int s, int e, int idx){
    if(idx<s || idx>e) return tree[n];
    if(s==e) return tree[n] = idx;
    int mid = (s+e)>>1;
    int x = modify(n<<1, s, mid, idx);
    int y = modify(n<<1|1, mid+1, e, idx);
    if(x>y) swap(x,y);
    if(arr[x] <= arr[y]) return tree[n] = x;
    else return tree[n] = y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    // memset(tree, 0x3f, sizeof(tree));
    init(1,1,N);

    cin>>Q;
    int a,b,k;
    while(Q--){
        cin>>k;
        if(k==1){
            cin>>a>>b;
            arr[a] = b;
            modify(1, 1, N, a);
        } else if(k==2){
            cout<<tree[1]<<'\n';
        }
    }
    
}