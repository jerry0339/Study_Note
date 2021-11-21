// https://www.acmicpc.net/problem/2336
// min 세그트리, 정렬

#include<bits/stdc++.h>
#define MAX_N 500001
using namespace std;
const int INF = 0x3f3f3f3f;

struct Info{
    int a,b,c;
    bool operator < (const Info &t) const {
        if(a==t.a) {
            if(b==t.b) return c < t.c;
            return b < t.b;
        }
        return a < t.a;
    }
    Info(int a=0, int b=0, int c=0): a(a), b(b), c(c){}
};

int N;
Info v[MAX_N];
int mint[MAX_N<<2]{};

int minModify(int n, int s, int e, int idx, int val){
    if(idx<s || idx>e) return mint[n];
    if(s==e) return mint[n] = val;
    int mid = (s+e)>>1;
    return mint[n] = min(minModify(n<<1, s, mid, idx, val), minModify(n<<1|1, mid+1, e, idx, val));
}

int minQuery(int n, int s, int e, int l, int r){
    if(l>e || r<s) return INF;
    if(l<=s && e<=r) return mint[n];
    int mid = (s+e)>>1;
    return min(minQuery(n<<1, s, mid, l, r) , minQuery(n<<1|1, mid+1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int t;
    for(int i=1; i<=N; i++) {
        cin>>t;
        v[t].a = i;
    }
    for(int i=1; i<=N; i++) {
        cin>>t;
        v[t].b = i;
    }
    for(int i=1; i<=N; i++) {
        cin>>t;
        v[t].c = i;
    }
    sort(v+1, v+N+1);
    
    memset(mint, 0x3f, sizeof(mint));
    int sum = 0;
    for(int i=1; i<=N; i++){
        int a = v[i].b;
        int b = v[i].c;
        int minGrade = minQuery(1,1,N, 1,a-1);
        if(minGrade > b) sum++;
        minModify(1,1,N, a, b);
    }
    
    cout<<sum;
}