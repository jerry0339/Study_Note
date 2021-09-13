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
vector<int> adj[501];
bool vi[501]{};

bool bfs(int st){
    bool ret = true;
    queue<pii> q;
    q.push({st,0});
    vi[st] = true;
    
    while(!q.empty()){
        int cn = q.front().xx;
        int pre = q.front().yy;
        q.pop();

        for(auto next : adj[cn]){
            if(vi[next]) {
                if(pre!=next) ret = false;
                continue;
            }
            q.push({next,cn});
            vi[next] = true;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a,b;
    for(int k=1; ; k++){
        cin>>N>>M;
        if(!N && !M) return 0;

        for(int i=0; i<=N; i++) adj[i].clear();
        memset(vi,0,sizeof(vi));
        for(int i=0; i<M; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int res = 0;
        for(int i=1; i<=N; i++){
            if(vi[i]) continue;
            if(bfs(i)) res++;
        }

        cout<<"Case "<<k<<": ";
        if(res==0){
            cout<<"No trees."<<'\n';
        } else if(res==1){
            cout<<"There is one tree."<<'\n';
        } else {
            cout<<"A forest of "<<res<<" trees."<<'\n';
        }

    }

}
