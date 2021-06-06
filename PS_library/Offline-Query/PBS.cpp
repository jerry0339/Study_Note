// 크루스칼의 공 - BOJ_1396
// PBS : 병렬 이분 탐색, Union_find
// <시간복잡도> : 자세한건 코드의 반복문 주석 참고
// O{MlogM + logM*(Q + (Q+M))} = 'O(MlogM + QlogM)'

#include<bits/stdc++.h>
#define xx first
#define yy second
#define MAX 100000
using namespace std;
typedef pair<int,int> pii;

struct Edge{
    int c,a,b;
    bool operator < (const Edge &t) const {
        return c < t.c;
    }
    Edge(int c_=0, int a_=0, int b_=0) :c(c_), a(a_), b(b_){}
};

int N,M,Q;
int parent[MAX+1]{};
vector<Edge> eg; // edge정보
vector<pii> qu; // offline query
int st[MAX+1]{}; // pbs start range
int ed[MAX+1]{}; // pbs edn range
int vtSize[MAX+1]{}; // [Q]의 간선 최소일때 집합크기
vector<int> qm[MAX+1]{}; // query map

int find(int a){
	if(parent[a]<0) return a;
	return parent[a] = find(parent[a]);
}
int merge(int a, int b){
	a = find(a);
    b = find(b);
	if(a==b) return -parent[b];
	if(parent[a] < parent[b]) swap(a,b);
	parent[b] += parent[a];
	parent[a] = b;
    return -parent[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b,c;
    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        eg.emplace_back(Edge(c,a,b));
    }
    sort(eg.begin(), eg.end()); // O(MlogM)
    cin>>Q;
    for(int i=0; i<Q; i++){
        cin>>a>>b;
        qu.push_back({a,b});
    }
    for(int i=0; i<Q; i++) ed[i] = M-1; // pbs 위한 ed초기화

    while(1){ // O(logM)
        for(int i=0; i<M; i++) qm[i].clear();
        bool chk = false;
        for(int i=0; i<Q; i++){ // O(Q)
            if(st[i]<=ed[i]){
                int mid = (st[i] + ed[i])/2;
                qm[mid].push_back(i);
                chk = true;
            }
        }
        if(!chk) break;

        memset(parent, -1, sizeof(parent));

        // mst 활용 -> 집합크기를 구해야 하기 때문에 mst로 만들진 않음 -> 그래프가 만들어짐
        // 아래의 이중for문은 O(MQ)처럼 보이지만 2번째 for문에서 qm[i]는 M에 상관없이 Q개의 데이터가 들어가 있고 그만큼 실행되기 때문에
        // 시간복잡도는 O(M+Q)가 됨
        for(int i=0; i<M; i++){ // O(M)
            int sz = merge(eg[i].a, eg[i].b);
            for(auto idx : qm[i]){ // O(Q)-> M마다 Q번 도는것이 아니라 M에 상관없이 Q만큼만 돌아감
                if(find(qu[idx].xx)==find(qu[idx].yy)) {
                    ed[idx] = i - 1;
                    vtSize[idx] = sz;
                }
                else st[idx] = i + 1;
            }
        }
    }

    for(int i=0; i<Q; i++){
        if(st[i] == M) cout<<-1<<'\n';
        else cout<<eg[st[i]].c<<' '<<vtSize[i]<<'\n';
    }
}