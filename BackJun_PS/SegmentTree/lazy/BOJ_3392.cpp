// 화성지도 BOJ_3392
// sweeping, lazy segment tree (without propagation)

#include<bits/stdc++.h>
#define MAX 30001
using namespace std;

struct Edge{
    int x,a,b,c;
    Edge(int x, int a, int b, int c):x(x), a(a), b(b), c(c){}
    bool operator<(const Edge &t){
        return x < t.x;
    }
};

vector<Edge> v;
int tree[MAX<<2]{};
int lazy[MAX<<2]{};
int N;

void lazyUpdate(int n, int x, int y, int lo, int hi, int val) {
    if (y < lo || hi < x)
        return;
    if (lo <= x&&y <= hi)
        lazy[n] += val;
    else {
        int mid = (x + y) >> 1;
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
    cin>>N;
    int x1,y1,x2,y2;
    for(int i=0; i<N; i++){
        cin>>x1>>y1>>x2>>y2;
        v.push_back(Edge(x1, y1, y2-1, 1));
        v.push_back(Edge(x2, y1, y2-1, -1));
    }
    sort(v.begin(), v.end());
    
    int sum = 0, pre=v[0].x;
    for(auto edge : v){
        int tmp = tree[1];
        if(edge.x>0) sum += tmp*(edge.x-pre);
        pre = edge.x;
        lazyUpdate(1,0,MAX, edge.a, edge.b, edge.c);
    }

    cout<<sum;
}