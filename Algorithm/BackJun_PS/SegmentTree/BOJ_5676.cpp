// <음주 코딩> - BOJ_5676
// 세그트리 - 곱

#include<bits/stdc++.h>
#define MAX 100000
#define MAX_N 100000
using namespace std;

int arr[MAX_N]{};
int tree[MAX<<2]{};
int N,K;

int init(int n, int s, int e){
    if(s==e) return tree[n] = arr[s];
    int mid = (s+e)>>1;
    return tree[n] = init(n<<1, s, mid) * init(n<<1|1, mid+1, e);
}

int modify(int n, int s, int e, int idx, int val){
    if(idx<s || idx>e) return tree[n];
    if(s==e) return tree[n] = val;
    int mid = (s+e)>>1;
    return tree[n] = modify(n<<1, s, mid, idx, val) * modify(n<<1|1, mid+1, e, idx, val);
}

int query(int n, int s, int e, int l, int r){
    if(l>e || r<s) return 1;
    if(l<=s && e<=r) return tree[n];
    int mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) * query(n<<1|1, mid+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>N>>K){
        int tmp;
        for(int i=0; i<N; i++){
            cin>>tmp;
            if(tmp>0) tmp=1;
            else if(tmp<0) tmp=-1;
            arr[i] = tmp;
        }
        for(int i=0; i<MAX*4; i++) tree[i] = 1;
        init(1,0,N-1);

        char ch;
        int a,b;
        while(K--){
            cin>>ch;
            cin>>a>>b;
            if(ch=='C'){
                if(b>0) b=1;
                else if(b<0) b=-1;
                arr[a-1] = b;
                modify(1,0,N-1,a-1,b);
            } else {
                if(a>b) swap(a,b);
                tmp = query(1, 0, N-1, a-1, b-1)<<'\n';
                if(tmp>0) cout<<'+';
                else if(tmp<0) cout<<'-';
                else cout<<'0';
            }
        }
        cout<<'\n';
    }

    return 0;
}