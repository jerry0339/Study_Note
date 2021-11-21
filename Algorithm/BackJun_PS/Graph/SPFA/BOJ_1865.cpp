#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int INF = 0x3f3f3f3f3f3f3f3f;

int T,N,M,W;
vector<pii> adj[501]{};
ll dist[501]{};
bool ex[501]{};
int vi[501]{};

bool BellmanFord(int st){
    memset(dist,0x3f,sizeof(dist));
    memset(ex,0,sizeof(ex));
    memset(vi,0,sizeof(vi));

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
                    if(++vi[next]==N) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin>>T;
    while(T--){
        cin>>N>>M>>W;
        for(int i=1; i<=N; i++) adj[i].clear();
        for(int i=0; i<M; i++){
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        for(int i=0; i<W; i++){
            cin>>a>>b>>c;
            adj[a].push_back({b,-c});
        }
        
        bool res = false;
        for(int i=1; i<=N; i++){
            if(!BellmanFord(i)) {
                res = true;
                break;
            }
        }

        if(!res) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }

}