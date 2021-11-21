#include<bits/stdc++.h>
using namespace std;

int N, maxdist = 0, root;
vector<pair<int,int>> adj[100001]{};
int parent[100001]{};

void dfs(int now, int par, int d){
    parent[now] = par;

    if(d > maxdist) {
        maxdist = d;
        root = now;
    }

    for(int i=0; i<adj[now].size(); i++){
        int next = adj[now][i].first;
        if(next == par) continue;
        int nd = adj[now][i].second;
        dfs(next,now,d+nd);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int n,a,b;
    for(int i=0; i<N; i++){
        cin>>n;
        while(1){
            cin>>a;
            if(a==-1) break;
            cin>>b;
            adj[n].push_back({a,b});
        }
    }

    dfs(1,0,0);
    memset(parent,0,sizeof(parent));
    dfs(root,0,0);
    cout<<maxdist;
}