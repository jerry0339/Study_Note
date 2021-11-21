// propagation이 없이, 구간노드(n)에 val값 update하는 세그먼트 트리
// [x,y]구간에 특정 val이 더해질때 반드시 [x,y]구간에 -val의 data가 주어지기 때문에 가능한 풀이

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

// lazy val값을 전파하지 않음
// 해당 구간노드(n)의 lazy값을 축적함
// 구간노드(n)의 lazy값이 1 이상이면 구간범위수(y-x+1)를 tree[n]에 저장함
// 풀이에서 (lo,hi,val)->(x,y,1) 의 구간업데이트가 들어오면 반드시 (x,y,-1)이 업데이트되기 때문에 가능한 풀이
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