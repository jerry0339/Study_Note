// 면접보는 승범이네 - BOJ_17835
// 다익스트라
// 1.역방향 간선, 2.시작점이 여러개인 다익스트라 알고리즘 이용
/*
1. 역방향 간선 그래프
단방향 간선 그래프에서 간선의 방향을 모두 역으로 저장한 후
한 노드 x에서 다른 노드까지의 최단거리를 구하면
모든 노드로부터 노드 x까지의 최단거리를 구할 수 있다.

2. 시작점이 여러개인 다익스트라 알고리즘
시작점 여러개를 pq에 저장하고 다익스트라를 통해 얻은 최단거리정보는
어떤 시작점에서 출발하여 얻은 최단거리인지 알 수는 없지만 
-> '모든 시작 노드들로부터 아닌 노드들까지의 최단거리' 를 구할 수 있다.
-> '모든 시작 노드들로부터 아닌 노드까지 각각 얼마나 떨어져 있는지' 를 구할 수 있다.
-> '시작점이 아닌 노드들 중 모든 시작점으로부터 가장 멀리 떨어져 있는 노드' 를 구할 수 있다.
*/
// 1. 과 2. 를 BOJ_17835에서 이용하여
// -> 역방향 그래프에서 모든 면접장을 시작노드들로 다익스트라를 사용하면
//     다른 노드들로부터 어떤 면접장까지의 최단거리를 구할 수 있고 그중 가장 먼곳을 답으로 출력가능


#include <bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long llINF = 1e18;

ll N,M,K;
vector<pll> adj[100001]{};
vector<ll> des;
ll dist[100001]{};

priority_queue<pll, vector<pll>, greater<pll>> pq;
void dijk(){
    while(!pq.empty()){
        ll cd = pq.top().xx;
        ll cn = pq.top().yy;
        pq.pop();

        if(cd > dist[cn]) continue;
        for(auto val : adj[cn]){
            ll nd = cd + val.yy;
            ll next = val.first;
            if(nd < dist[next]){
                dist[next] = nd;
                pq.push({nd, next});
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M>>K;
    ll a,b,c;
    for(ll i=0; i<M; i++){
        cin>>a>>b>>c;
        adj[b].push_back({a,c});
    }

    for(ll i=1; i<=N; i++) dist[i] = llINF;
    for(ll i=0; i<K; i++) {
        cin>>a;
        des.push_back(a);
        dist[a] = 0;
        pq.push({0, a});
    }

    dijk();
    ll maxNode = des[0];
    for(ll i=1; i<=N; i++){
        if(dist[i] > dist[maxNode]){
            maxNode = i;
        }
    }
    cout<<maxNode<<'\n'<<dist[maxNode];
}