// Mountaineers - BOJ_16074
// PBS, Union-Find

#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int d,x,y;
    bool operator < (const Edge &t) const {
        return d < t.d;
    }
    Edge(int d_=0, int x_=0, int y_=0) :d(d_), x(x_), y(y_){}
};

struct Query{
    int x,y,k;
    Query(int x=0, int y=0, int k=0) :x(x), y(y), k(k){}
};

int N,M,Q;
int m[510][510]{};
vector<Edge> edge;
vector<Query> query;
vector<int> qm[500010]{};
int st[250010]{};
int ed[250010]{};
int parent[250010]{};

int find(int k){
    if(parent[k]<0) return k;
    return parent[k] = find(parent[k]);
}

void merge(int a, int b){
	a = find(a);
    b = find(b);
	if(a==b) return;
	if(parent[a] < parent[b]) swap(a,b);
	parent[b] += parent[a];
	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M>>Q;
    
    for(int i=0; i<N; i++){
        for(int j=1; j<=M; j++){
            cin>>m[i][j];
            if(i!=0) {
                int d = max(m[i][j], m[i-1][j]);
                edge.emplace_back(Edge(d, i*M+j, (i-1)*M+j));
            }
            if(j>1) {
                int d = max(m[i][j], m[i][j-1]);
                edge.emplace_back(Edge(d, i*M+j, i*M+(j-1)));
            }
        }
    }
    sort(edge.begin(), edge.end());

    int a,b,c,d;
    for(int i=0; i<Q; i++){
        cin>>a>>b>>c>>d;
        query.emplace_back(Query((a-1)*M+b, (c-1)*M+d, m[a-1][b]));
    }
    
    int tmp = N*(M-1) + (N-1)*M;
    N = N*M;
    M = tmp;
    for(int i=0; i<Q; i++) ed[i] = M-1;
    while(true){
        for(int i=0; i<M; i++) qm[i].clear();
        bool chk = false;
        for(int i=0; i<Q; i++) {
            if(st[i]<=ed[i]){
                int mid = (st[i] + ed[i])/2;
                qm[mid].push_back(i);
                chk = true;
            }
        }
        if(!chk) break;

        memset(parent,-1,sizeof(parent));
        for(int i=0; i<M; i++) {
            merge(edge[i].x, edge[i].y);
            for(auto idx : qm[i]){
                int a = query[idx].x;
                int b = query[idx].y;
                if(find(a)==find(b)) {
                    ed[idx] = i - 1;
                } else {
                    st[idx] = i + 1;
                }
            }
        }
    }

    for(int i=0; i<Q; i++){
        if(query[i].x==query[i].y) cout<<query[i].k<<'\n';
        else cout<<edge[st[i]].d<<'\n';
    }
}
