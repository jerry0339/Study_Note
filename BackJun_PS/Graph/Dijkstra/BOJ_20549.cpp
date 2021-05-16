// 6:45

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using pii = pair<int,int>;
using tpi = tuple<int,int,int>;
const int INF = 0x3f3f3f3f;

int N,M;
int cost[3]{};
int sty, stx;
vector<pii> cord;
int dist[5][50][50]{};
int ndy[8] = {-1,-2,-2,-1,1,2,2,1}; // night
int ndx[8] = {-2,-1,1,2,2,1,-1,-2};
int bdy[4] = {-1,-1,1,1}; // bishop
int bdx[4] = {-1,1,1,-1};
int rdy[4] = {-1,0,1,0}; // rook
int rdx[4] = {0,1,0,-1};

void dijk(int y, int x, int idx){
    priority_queue<tpi, vector<tpi>, greater<tpi>> pq;
    pq.push({0,y,x});
    dist[idx][y][x] = 0;

    while(!pq.empty()){
        int cd,cy,cx;
        tie(cd,cy,cx) = pq.top();
        pq.pop();

        if(cd > dist[idx][cy][cx]) continue;

        for(int i=0; i<8; i++){
            int nd = cd + cost[0];
            int ny = cy + ndy[i];
            int nx = cx + ndx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
            if(nd < dist[idx][ny][nx]) {
                pq.push({nd,ny,nx});
                dist[idx][ny][nx] = nd;
            }
        }

        for(int i=0; i<4; i++){
            for(int j=1; ; j++){
                int nd = cd + cost[1];
                int ny = cy + j*bdy[i];
                int nx = cx + j*bdx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=N) break;
                if(nd < dist[idx][ny][nx]) {
                    pq.push({nd,ny,nx});
                    dist[idx][ny][nx] = nd;
                }
            }
        }

        for(int i=0; i<4; i++){
            for(int j=1; ; j++){
                int nd = cd + cost[2];
                int ny = cy + j*rdy[i];
                int nx = cx + j*rdx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=N) break;
                if(nd < dist[idx][ny][nx]) {
                    pq.push({nd,ny,nx});
                    dist[idx][ny][nx] = nd;
                }
            }
        }
    }
}

int mind = INF;
bool vi[5]{};
void dfs(int dpt, int sum, int cidx){
    if(dpt == M) {
        mind = min(mind, sum);
        return;
    }

    for(int i=1; i<=M; i++){
        if(vi[i]) continue;
        vi[i] = true;
        dfs(dpt+1, sum + dist[cidx][cord[i].xx][cord[i].yy], i);
        vi[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dist,0x3f,sizeof(dist));
    cin>>N;
    for(int i=0; i<3; i++) cin>>cost[i];
    cin>>sty>>stx;
    cord.push_back({sty,stx});
    dijk(sty,stx,0);
    cin>>M;
    int y,x;
    for(int i=1; i<=M; i++){
        cin>>y>>x;
        cord.push_back({y,x});
        dijk(y,x,i);
    }

    dfs(0,0,0);
    cout<<mind;
}