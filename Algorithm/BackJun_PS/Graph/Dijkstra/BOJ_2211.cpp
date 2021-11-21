#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tpi = tuple<int,int,int>;
using tpl = tuple<ll,ll,ll>;
using dpi = pair<pii,pii>;
using dpl = pair<pll,pll>;
using pis = pair<int,string>;
using psi = pair<string,int>;

const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;

int N,M;
vector<pii> adj[1001]{};
int dist[1001]{};
int trace[1001]{};
bool vi[1001]{};
vector<pii> ans;

void dijk(){
    memset(dist,0x3f,sizeof(dist));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,1});
    dist[1] = 0;
    trace[1] = 0;

    while(!pq.empty()){
        int cd = pq.top().xx;
        int cn = pq.top().yy;
        pq.pop();

        if(cd > dist[cn]) continue;

        for(auto next : adj[cn]){
            int nn = next.xx;
            int nd = next.yy + cd;
            if(nd < dist[nn]) {
                pq.push({nd, nn});
                dist[nn] = nd;
                trace[nn] = cn;
            }
        }
    }
}

void tracing(int k){
    int now = k;
    while(!vi[now]){
        int next = trace[now];
        ans.push_back({now, next});
        vi[now] = true;
        now = next;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b,c;
    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    dijk();
    vi[0] = true;
    vi[1] = true;
    for(int i=1; i<=N; i++){
        if(vi[i]) continue;
        tracing(i);
    }

    cout<<ans.size()<<'\n';
    for(auto val : ans){
        cout<<val.xx<<' '<<val.yy<<'\n';
    }

}
