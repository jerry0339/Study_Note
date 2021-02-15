// <줄 세우기> - BOJ_2252
// 위상정렬(topology sort) + bfs

#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int> adj[32010]{};
vector<int> adj2[32010]{};
int deg[32010]{};
int vi[32010]{};
vector<int> grp[32010]{};
vector<int> ans[32010]{};

void bfs(int st, int g){
    queue<int> q;
    q.push(st);
    vi[st] = g;

    while(!q.empty()){
        int cn = q.front();
        q.pop();
        for(auto nn : adj2[cn]){
            if(vi[nn]) continue;
            q.push(nn);
            vi[nn] = g;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b;
    while(M--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj2[a].push_back(b);
        adj2[b].push_back(a);
        deg[b]++;
    }
    
    int g=1;
    for(int i=1; i<=N; i++) {
        if(vi[i]==0) {
            bfs(i,g);
            g++;
        }
    }

    for(int i=1; i<=N; i++){
        int gidx = vi[i];
        grp[gidx].push_back(i);
    }

    for(int i=1; i<g; i++){
        queue<int> q;
        for(auto n : grp[i]){
            if(deg[n]==0) {
                q.push(n);
                ans[i].push_back(n);
            }
        }

        for(int j=0; j<grp[i].size(); j++) {
            int cn = q.front();
            q.pop();
            
            for(auto nn : adj[cn]){
                if(--deg[nn]==0){
                    q.push(nn);
                    ans[i].push_back(nn);
                }
            }
        }
    }

    for(int i=1; i<g; i++){
        for(auto val : ans[i]){
            cout<<val<<' ';
        }
    }

}