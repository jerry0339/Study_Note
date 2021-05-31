#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using pii = pair<int,int>;
using tpi = tuple<int,int,int>;
const int INF = 0x3f3f3f3f;

int N,M, ans = INF;
int m[50][50]{};
bool vi[50][50]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
vector<pii> vpos;
vector<pii> virus;

int bfs(){
    memset(vi,0,sizeof(vi));
    queue<tpi> q;
    for(auto v : virus) {
        q.push({0, v.xx, v.yy});
        vi[v.xx][v.yy] = true;
    }
    
    int res = 0;
    while(!q.empty()){
        int cd,cy,cx;
        tie(cd,cy,cx) = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nd = cd + 1;
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=N || vi[ny][nx] || m[ny][nx]==1) continue;
            if(m[ny][nx]!=2) res = max(res, nd);
            q.push({nd,ny,nx});
            vi[ny][nx] = true;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(m[i][j]==2 || m[i][j]==1) continue;
            if(!vi[i][j]) return INF;
        }
    }

    return res;
}

void dfs(int now, int cnt){
    if(cnt==M) {
        ans = min(ans, bfs());
        return;
    }

    for(int i=now; i<vpos.size(); i++){
        virus.push_back(vpos[i]);
        dfs(i+1, cnt+1);
        virus.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>m[i][j];
            if(m[i][j]==2) vpos.push_back({i,j});
        }
    }

    dfs(0,0);
    if(ans==INF) cout<<-1;
    else cout<<ans;
}