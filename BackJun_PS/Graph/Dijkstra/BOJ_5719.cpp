#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x))
#define rall(v) (v).rbegin(), (v).rend()
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;
const int INF = 0x3f3f3f3f;

int N,M,S,E;
vector<vector<pii>> adj;
vector<vector<int>> trace;
int dis[501]{};
bool vi[501][501]{};

void nearlyDijk(int st, int ed){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});
    dis[st] = 0;

    while(!pq.empty()){
        int cd = pq.top().xx;
        int cn = pq.top().yy;
        pq.pop();

        if(dis[cn] < cd) continue;

        for(int i=0; i<adj[cn].size(); i++){
            int nn = adj[cn][i].xx;
            int nd = adj[cn][i].yy + dis[cn];
            if(vi[cn][nn]) continue;

            if(nd == dis[nn]) trace[nn].push_back(cn);
            else if(nd < dis[nn]) {
                pq.push({nd, nn});
                dis[nn] = nd;
                trace[nn].clear();
                trace[nn].push_back(cn);
            }
        }
    }
}

void traceDfs(int now){
    for(int i=0; i<trace[now].size(); i++){
        int next = trace[now][i];
        if(vi[next][now]) continue;
        vi[next][now] = true;
        traceDfs(next);
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int a,b,c;
    while(1){
        cin>>N>>M;
        if(N==0 && M==0) break;
        cin>>S>>E;

        memset(dis,0x3f,sizeof(dis));
        memset(vi,0,sizeof(vi));
        adj.clear();
        adj.resize(N);
        trace.clear();
        trace.resize(N);

        for(int i=0; i<M; i++) {
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
        }

        nearlyDijk(S,E);
        traceDfs(E);
        memset(dis,0x3f,sizeof(dis));
        nearlyDijk(S,E);
        if(dis[E]!=INF) cout<<dis[E]<<'\n';
        else cout<<-1<<'\n';
    }

}