// <두 로봇> - BOJ_15971
// BFS

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

int N,st,ed;
vector<pii> adj[100001];
bool vi[100001]{};

int solve(){
    queue<pair<int,pii>> q;
    q.push({0,{st,0}}); // dis, pos, maxd
    vi[st] = true;

    while(!q.empty()) {
        int cd = q.front().xx;
        int cp = q.front().yy.xx;
        int cmd = q.front().yy.yy;
        q.pop();

        if(cp==ed) return cd-cmd;

        for(int i=0; i<adj[cp].size(); i++){
            int np = adj[cp][i].xx;
            if(vi[np]) continue;
            int nd = cd + adj[cp][i].yy;
            int nmd = max(cmd, adj[cp][i].yy);
            q.push({nd,{np,nmd}});
            vi[np] = true;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>st>>ed;
    int a,b,c;
    for(int i=0; i<N-1; i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    cout<<solve();
}