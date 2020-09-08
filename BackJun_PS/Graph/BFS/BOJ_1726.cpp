// <로봇> - BOJ_1726
// BFS, DP

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;

int N,M;
int m[101][101]{};
int sty,stx,stw, edy,edx,edw;
int dy[5] = {0,0,0,1,-1}; // 동서남북
int dx[5] = {0,1,-1,0,0};
bool vi[101][101][5]{};

int solve(){
    queue<pair<pii,pii>> q; // dis, way(dir), y, x
    q.push({{0,stw},{sty,stx}});
    vi[sty][stx][stw] = true;

    while(!q.empty()){
        int cd = q.front().xx.xx;
        int cw = q.front().xx.yy;
        int cy = q.front().yy.xx;
        int cx = q.front().yy.yy;
        q.pop();

        if(cy==edy && cx==edx && cw==edw) return cd;

        int nrw, nlw;
        if(cw==1) {nrw=3; nlw=4;}
        else if(cw==2) {nrw=4; nlw=3;}
        else if(cw==3) {nrw=2; nlw=1;}
        else if(cw==4) {nrw=1; nlw=2;}
        
        if(!vi[cy][cx][nrw]) {
            q.push({{cd+1,nrw},{cy,cx}});
            vi[cy][cx][nrw] = true;
        }
        if(!vi[cy][cx][nlw]) {
            q.push({{cd+1,nlw},{cy,cx}});
            vi[cy][cx][nlw] = true;
        }

        for(int i=1; i<=3; i++){
            int ny = cy + dy[cw]*i;
            int nx = cx + dx[cw]*i;
            if(ny<1 || nx<1 || ny>N || nx>M || m[ny][nx]) break;
            if(vi[ny][nx][cw]) continue;
            q.push({{cd+1,cw},{ny,nx}});
            vi[ny][nx][cw] = true;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) cin>>m[i][j];
    cin>>sty>>stx>>stw;
    cin>>edy>>edx>>edw;
    cout<<solve();
}