// <서강그라운드> - BOJ_14938
// 다익스트라
// vector를 이용한 인접리스트
// dis업데이트하는 코드

#include<bits/stdc++.h>
using namespace std;
#define aa first
#define bb second
typedef pair<int,int> pii;
const int INF = 1e9;

vector<vector<pii>> adj;
vector<int> d;
int item[101]{};
int N,disLimit,M;

void solve(int st){ // dijkstra
    priority_queue<pii> pq;
    pq.push({0,st});
    d[st] = 0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int dis = -1 * pq.top().first;
        pq.pop();
        
        if (dis > d[cur]) continue;

        for(int i = 0; i < adj[cur].size(); i++){
            int next = adj[cur][i].first;
		    int nextDis = dis + adj[cur][i].second;

			if (nextDis < d[next]) {
				d[next] = nextDis;
				pq.push(make_pair(-1*nextDis, next));
			}
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>disLimit>>M;
    adj.resize(N+1);
    for(int i=1; i<=N; i++) cin>>item[i];
    // adj[i] 의 원소{j,dis} : i->j로 가는 가중치 dis
    for(int i=1; i<=M; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int max_=0;
    for(int i=1; i<=N; i++){
        d.clear();
        d.resize(N+1,INF);
        solve(i);
        int t=0;
        for(int j=1; j<=N; j++){
            if(d[j]<=disLimit) t+=item[j];
        }
        max_=max(max_,t);
    }
    
    cout<<max_;
}