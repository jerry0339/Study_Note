#include<bits/stdc++.h>
#define MAX 400
using namespace std;
const int INF = 0x3f3f3f3f;

int N,K,D;
int flo[MAX][MAX]{}, cap[MAX][MAX]{}; 
vector<int> adj[MAX]{};

int networkFlow(int st, int ed){ 
    int totalFlow = 0;
    int prev[MAX];

    while(1){
        memset(prev, -1, sizeof(prev));
        queue<int> q;
        q.push(st);

        while(!q.empty() && prev[ed]==-1){
            int cn = q.front();
            q.pop();
            if(cn == ed) break; 

            for(int i=0; i<adj[cn].size(); i++){
                int next = adj[cn][i];
                if(prev[next]!=-1) continue;
                if(cap[cn][next] - flo[cn][next] > 0) {
                    q.push(next);
                    prev[next] = cn;
                    if(next==ed) break;
                }
            }
        }

        if(prev[ed]==-1) break;
        int flow = INF;
        for (int i=ed; i!=st; i=prev[i]){
            flow = min(flow, cap[prev[i]][i] - flo[prev[i]][i]);
        }

        for (int i=ed; i!=st; i=prev[i]) {
            flo[prev[i]][i] += flow;
            flo[i][prev[i]] -= flow;
        }

        totalFlow += flow;
    }

    return totalFlow;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K>>D;
    int t, S=0, E=350;
    for(int i=1; i<=D; i++){
        cin>>t;
        adj[N+i].push_back(E);
        adj[E].push_back(N+i);
        cap[N+i][E] = t;
    }

    int z;
    for(int i=1; i<=N; i++){
        adj[S].push_back(i);
        adj[i].push_back(S);
        cap[S][i] = K;

        cin>>z;
        while(z--){
            cin>>t;
            adj[i].push_back(N+t);
            adj[N+t].push_back(i);
            cap[i][N+t] = 1;
        }
    }
    
    cout<<networkFlow(S, E);
    return 0;
}