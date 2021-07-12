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
const int INF = 0x3f3f3f3f;

int N,M;
vector<int> adj[1001]{};
int deg[1001]{};
int order[1001]{};

void topology(){
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(deg[i]==0) {
            q.push(i);
            order[i] = 1;
        }
    }

    for(int k=1; k<=N; k++){
        int cn = q.front();
        q.pop();

        for(int i=0; i<adj[cn].size(); i++){
            int next = adj[cn][i];
            if(--deg[next] == 0){
                q.push(next);
                order[next] = order[cn] + 1;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }

    topology();
    
    for(int i=1; i<=N; i++){
        cout<<order[i]<<' ';
    }
}