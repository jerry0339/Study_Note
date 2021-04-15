#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> dpii;
const int INF = 1e9;

int N;
int m[101][101]{};
int miny[101]{};
int minx[101]{};
int dist[101][101][4]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void solve(){
    priority_queue<dpii, vector<dpii>, greater<dpii>> pq;
    pq.push({{0,-1},{1,1}}); // dist, dir, y, x
    for(int i=0; i<4; i++) dist[1][1][i] = 0;

    while(!pq.empty()){
        int cdist = pq.top().xx.xx;
        int cdir = pq.top().xx.yy;
        int cy = pq.top().yy.xx;
        int cx = pq.top().yy.yy;
        pq.pop();

        if(cdist > dist[cy][cx][cdir]) continue;

        for(int i=0; i<4; i++){
            if(i==cdir) continue;
            int idx = 1, pre = 1;
            for(int k=1; k<100; k+=(++idx)){
                int ndist = cdist + idx;
                int ny = cy + k*dy[i];
                int nx = cx + k*dx[i];
                if(ny<1 || nx<1 || ny>N || nx>N) break;
                if(m[ny][nx] > 0 && m[ny][nx]<=ndist) break;
                bool chk = true;
                for(int j=pre; j<k; j++){
                    int ty = cy + j*dy[i];
                    int tx = cx + j*dx[i];
                    if(m[ty][tx] > 0 && m[ty][tx] < ndist) {
                        chk = false;
                        break;
                    }
                }
                if(!chk) break;
                pre = k;
                if(dist[ny][nx][i] > ndist) {
                    dist[ny][nx][i] = ndist;
                    pq.push({{ndist, i},{ny,nx}});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dist,0x3f,sizeof(dist));
    cin>>N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin>>m[i][j];

    solve();
    int res = INF;
    for(int i=0; i<4; i++) res = min(res, dist[N][N][i]);
    if(res==INF) cout<<"Fired"<<'\n';
    else cout<<res<<'\n';
}