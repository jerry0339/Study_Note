// BOJ_11657 - 타임머신

#include<bits/stdc++.h>
#define MAX 501
#define xx first
#define yy second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int T,N,M,W;
vector<pii> adj[MAX]{};
ll dist[MAX]{};
bool ex[MAX]{}; // exists in Q
int vi[MAX]{}; // vi count

// Shortest Path Faster Algorithm
bool SPFA(int st){
    memset(dist,0x3f,sizeof(dist));
    // memset(ex,0,sizeof(ex));
    // memset(vi,0,sizeof(vi));

    queue<int> q;
    q.push(st);
    dist[st] = 0;
    ex[st] = true;
    vi[st]++;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ex[cur] = false;

        for(auto e : adj[cur]){
            int next = e.xx;
            int w = e.yy;
            if(dist[next] > dist[cur] + w){
                dist[next] = dist[cur] + w;
                if(!ex[next]) {
                    q.push(next);
                    ex[next] = true;
                    if(++vi[next]>=N) return false; // 사이클 존재
                }
            }
        }
    }
    return true; // 사이클 없음
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    int a,b,c;
    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    if(!SPFA(1)) {
        cout<<-1;
        return 0;
    }

    for(int i=2; i<=N; i++){
        if(dist[i]==INF) cout<<-1<<'\n';
        else cout<<dist[i]<<'\n';
    }

}