#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int N;
int arr[MAX]{};
int num[MAX]{};
int tree[MAX<<2]{};

void modify(int n, int s, int e, int idx, int diff){
    if(idx<s || idx>e) return;
    tree[n] += diff;
    if(s==e) return;
    int mid = (s+e)>>1;
    modify(n<<1, s, mid, idx, diff);
    modify(n<<1|1, mid+1, e, idx, diff);
}

int query(int n, int s, int e, int val){
    if(s==e) return s;
    int mid = (s+e)>>1;
    int next = mid-s+1 - tree[n<<1];
    if(val <= next) return query(n<<1, s, mid, val);
    return query(n<<1|1, mid+1, e, val-next);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++) cin>>arr[i];
    for(int i=1; i<=N; i++) cin>>num[i];
    sort(arr+1, arr+1+N);

    for(int i=N; i>=0; i--) {
        num[i] = query(1,1,N, num[i]+1);
        modify(1,1,N, num[i],1);
    }

    for(int i=1; i<=N; i++){
        cout<<arr[num[i]]<<'\n';
    }

    return 0;
}