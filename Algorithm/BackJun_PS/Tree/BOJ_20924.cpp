// tree, dfs

#include<bits/stdc++.h>
#define MAX_N 200000
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

int N, R, G=0, parG;
int pillar, maxdist=0;
vector<pii> adj[MAX_N+1]{};
int parent[MAX_N+1]{};
int numChild[MAX_N+1]{};

void makeTree(int now, int par){
    parent[now] = par;

    for(auto val : adj[now]){
        int next = val.xx;
        if(next==par) continue;
        numChild[now]++;
        makeTree(next,now);
    }
}

bool calPillar(int now, int par, int dist){
    if(!G && numChild[now]>1) {
        G = now;
        pillar = dist;
        return true;
    }

    for(auto val : adj[now]){
        int next = val.xx;
        int nd = val.yy;
        if(next==par) continue;
        if(calPillar(next, now, dist+nd)) return true;
    }
    
    if(numChild[now]==0) {
        G = now;
        pillar = dist;
    }
    return false;
}

void dfs(int now, int par, int dist){
    if(dist > maxdist)
        maxdist = dist;

    for(auto val : adj[now]){
        int next = val.xx;
        int nd = val.yy;
        if(next == par || next == parG) continue;
        dfs(next,now,dist+nd);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>R;
    int a,b,d;
    for(int i=0; i<N-1; i++){
        cin>>a>>b>>d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }
    makeTree(R,0);
    if(calPillar(R,0,0)){
        cout<<pillar<<' ';
    } else {
        cout<<pillar<<' '<<0;
        return 0;
    }

    parG = parent[G];
    dfs(G,0,0);
    cout<<maxdist;
}