#include<bits/stdc++.h>
#define MAX_N 100000 // MAX값 확인
using namespace std;
const int INF = 0x3f3f3f3f; // MAX INF 확인. (long long 일경우)

// Modify함수는 정의되어 있지 않음!!

int arr[MAX_N]{};
int mint[MAX_N<<2]{}, maxt[MAX_N<<2]{};
int N,Q;

int initMin(int n, int s, int e){
    if(s==e) return mint[n] = arr[s];
    int mid = (s+e)>>1;
    return mint[n] = min(initMin(n<<1, s, mid) , initMin(n<<1|1, mid+1, e));
}

int initMax(int n, int s, int e){
    if(s==e) return maxt[n] = arr[s];
    int mid = (s+e)>>1;
    return maxt[n] = max(initMax(n<<1, s, mid) , initMax(n<<1|1, mid+1, e));
}

int minQuery(int n, int s, int e, int l, int r){
    if(l>e || r<s) return INF;
    if(l<=s && e<=r) return mint[n];
    int mid = (s+e)>>1;
    return min(minQuery(n<<1, s, mid, l, r) , minQuery(n<<1|1, mid+1, e, l, r));
}

int maxQuery(int n, int s, int e, int l, int r){
    if(l>e || r<s) return -INF;
    if(l<=s && e<=r) return maxt[n];
    int mid = (s+e)>>1;
    return max(maxQuery(n<<1, s, mid, l, r) , maxQuery(n<<1|1, mid+1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    memset(mint, 0x3f, sizeof(mint));
    memset(maxt, 0xc0, sizeof(maxt));
    initMin(1,0,N-1);
    initMax(1,0,N-1);

    int a,b;

    while(Q--){
        cin>>a>>b;
        if(a>b) swap(a,b);
        cout<<minQuery(1, 0, N-1, a-1, b-1)<<' ';
        cout<<maxQuery(1, 0, N-1, a-1, b-1)<<'\n';
    }
    
    return 0;
}