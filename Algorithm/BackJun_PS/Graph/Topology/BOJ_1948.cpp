// <임계경로> - BOJ_1948
// 위상정렬, 역추적, bfs
// 경로개수 역추적하는데 여러개의 경로? : 끝의 노드로부터 bfs 수행

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
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

int N,M,st,ed;
vector<pii> adj[10010]{};
int dg[10010]{};
int maxh[10010]{};
vector<int> pre[10010]{};

void topology(int st){
    queue<int> q;
    q.push(st);

    for(int i=1; i<=N; i++){
        int cp = q.front();
        q.pop();

        for(int j=0; j<adj[cp].size(); j++){
            int np = adj[cp][j].xx;
            int nd = adj[cp][j].yy + maxh[cp];
            if(maxh[np] == nd) pre[np].pb(cp);
            else if(maxh[np] < nd) {
                pre[np].clear();
                pre[np].pb(cp);
                maxh[np] = nd;
            }

            if(--dg[np]==0) {
                q.push(np);
            }

        }
    }
}

bool vi[10010]{};
int bfs(int st){
    int ans=0;
    queue<int> q;
    q.push(st);
    vi[st] = true;

    while(!q.empty()){
        int cp = q.front();
        q.pop();
        ans += pre[cp].size();

        for(int i=0; i<pre[cp].size(); i++){
            int np = pre[cp][i];
            if(vi[np]) continue;
            q.push(np);
            vi[np] = true;
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M;
    int a,b,c;
    while(M--){
        cin>>a>>b>>c;
        adj[a].pb({b,c});
        dg[b]++;
    }
	cin>>st>>ed;

    topology(st);
    cout<<maxh[ed]<<'\n'<<bfs(ed);
}