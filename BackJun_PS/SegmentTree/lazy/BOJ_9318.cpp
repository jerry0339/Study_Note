#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
typedef long long ll;

struct Edge{
    ll x,a,b,c;
    Edge(ll x, ll a, ll b, ll c):x(x), a(a), b(b), c(c){}
    bool operator<(const Edge &t){
        return x < t.x;
    }
};

vector<Edge> v;
ll tree[MAX<<2]{};
ll lazy[MAX<<2]{};
ll N,T;

void lazyUpdate(ll n, ll x, ll y, ll lo, ll hi, ll val) {
    if (y < lo || hi < x)
        return;
    if (lo <= x&&y <= hi)
        lazy[n] += val;
    else {
        ll mid = (x + y) >> 1;
        lazyUpdate(n<<1, x, mid, lo, hi, val);
        lazyUpdate(n<<1|1, mid + 1, y, lo, hi, val);
    }
    if (lazy[n]) tree[n] = y - x + 1;
    else {
        if (x == y)tree[n] = 0;
        else tree[n] = tree[n<<1] + tree[n<<1|1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        v.clear();
        cin>>N;
        ll x1,y1,x2,y2;
        for(ll i=0; i<N; i++){
            cin>>x1>>y1>>x2>>y2;
            v.push_back(Edge(x1, y1, y2-1, 1));
            v.push_back(Edge(x2, y1, y2-1, -1));
        }
        sort(v.begin(), v.end());
        
        ll sum = 0, pre=v[0].x;
        for(auto edge : v){
            if(edge.x>0) sum += tree[1]*(edge.x-pre);
            pre = edge.x;
            lazyUpdate(1,0,MAX, edge.a, edge.b, edge.c);
        }
        cout<<sum<<'\n';
    }
    
}