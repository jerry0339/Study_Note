// JOI 국가의 행사 - BOJ_5542
// PBS , dijkstra(다중 시작점 이용), Union-Find

#include<bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;

struct Edge{
    int d,x,y;
    bool operator < (const Edge &t) const {
        return d > t.d;
    }
    Edge(int d=0, int x=0, int y=0) :d(d), x(x), y(y){}
};

struct Query{
    int x,y;
    Query(int x=0, int y=0) :x(x), y(y){}
};

int N,M,K,Q;
vector<pii> adj[100001]{};
vector<pii> adj2[100001]{};
int dist[100001]{}; // 축제도시까지의 거리
vector<Edge> edge;
vector<Query> query;
int st[200001]{};
int ed[200001]{};
vector<int> qm[200001]{};
int parent[100001]{};

int find(int k){
    if(parent[k]<0) return k;
    return parent[k] = find(parent[k]);
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(parent[x] < parent[y]) swap(x,y);
    parent[y] += parent[x];
    parent[x] = y;
}

priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijk(){
    while(!pq.empty()){
        int cd = pq.top().xx;
        int cn = pq.top().yy;
        pq.pop();

        if(dist[cn] < cd) continue;
        for(auto val : adj[cn]){
            int nd = cd + val.yy;
            int next = val.xx;
            if(dist[next] > nd){
                dist[next] = nd;
                pq.push({nd,next});
            }
        }
    }

}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M>>K>>Q;
    int a,b,c;
    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        adj2[a].push_back({b,c});
    }

    memset(dist,0x3f,sizeof(dist));
    for(int i=0; i<K; i++){
        cin>>a;
        dist[a] = 0;
        pq.push({0,a});
    }
    dijk();

    for(int i=1; i<=N; i++){
        for(auto val : adj2[i]){
            int nd = min(dist[i], dist[val.xx]);
            edge.emplace_back(Edge(nd, i, val.xx));
        }
    }
    sort(all(edge));
    for(int i=0; i<Q; i++){
        cin>>a>>b;
        query.emplace_back(Query(a,b));
    }

    for(int i=0; i<Q; i++) ed[i] = M-1;
    while(true){
        for(int i=0; i<M; i++) qm[i].clear();
        bool chk = 0;
        for(int i=0; i<Q; i++){
            if(st[i]<=ed[i]){
                int mid = (st[i] + ed[i])>>1;
                qm[mid].push_back(i);
                chk = true;
            }
        }
        if(!chk) break;

        memset(parent,-1,sizeof(parent));
        for(int i=0; i<M; i++){
            merge(edge[i].x, edge[i].y);
            for(auto idx : qm[i]){
                if(find(query[idx].x)==find(query[idx].y)){
                    ed[idx] = i - 1;
                } else {
                    st[idx] = i + 1;
                }
            }
        }
    }

    for(int i=0; i<Q; i++){
        cout<<edge[st[i]].d<<'\n';
    }
}
