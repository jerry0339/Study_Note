// 로봇청소기
// DFS + BFS

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using pii = pair<int,int>;
using tpi = tuple<int,int,int>;
const int INF = 0x3f3f3f3f;

int N,M,K;
int m[20][20]{};
pii v[11]{};
int dist[11][11]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

bool bfs(int st){
    int vi[20][20]{};
    memset(vi,-1,sizeof(vi));
    queue<tpi> q;
    q.push({0, v[st].xx, v[st].yy});
    vi[v[st].xx][v[st].yy] = 0;

    while(!q.empty()){
        int cd, cy, cx;
        tie(cd, cy, cx) = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nd = cd + 1;
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M || vi[ny][nx]!=-1 || m[ny][nx]==-1) continue;
            q.push({nd, ny, nx});
            vi[ny][nx] = nd;
        }
    }

    for(int i=0; i<=K; i++){
        dist[st][i] = vi[v[i].xx][v[i].yy];
        if(dist[st][i] == -1) return false;
    }
    return true;
}

int ans;
bool vi[11]{};
void dfs(int now, int sum, int dpt){
    if(dpt==K){
        ans = min(ans, sum);
        return;
    }

    for(int i=1; i<=K; i++){
        if(vi[i]) continue;
        vi[i] = true;
        sum += dist[now][i];
        dfs(i, sum, dpt+1);
        sum -= dist[now][i];
        vi[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin>>M>>N;
        if(!N) break;
        memset(m,-1,sizeof(m));
        K=0;
        string str;
        for(int i=0; i<N; i++){
            cin>>str;
            for(int j=0; j<M; j++){
                if(str[j] == 'o') v[0].xx = i, v[0].yy = j, m[i][j] = 0;
                else if(str[j] == '*') m[i][j] = ++K, v[K].xx = i, v[K].yy = j;
                else if(str[j] == 'x') m[i][j] = -1;
                else m[i][j] = 0;
            }
        }

        bool chk = true;
        for(int i=0; i<=K; i++) {
            if(!bfs(i)) {
                chk = false;
                break;
            }
        }
        if(!chk) { 
            cout<<-1<<'\n';
            continue;
        }
        
        ans = INF;
        dfs(0,0,0);
        cout<<ans<<'\n';
    }
    
}