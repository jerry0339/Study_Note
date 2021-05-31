#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using pii = pair<int,int>;
using dpi = pair<pii,pii>;

int N,M;
int m[20][20]{};
bool vi[20][20][1<<10]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int bfs(int sty, int stx, int K){
    memset(vi,0,sizeof(vi));
    queue<dpi> q;
    q.push({{0,0}, {sty,stx}});
    vi[sty][stx][0] = false;

    while(!q.empty()){
        int cd = q.front().xx.xx;
        int ck = q.front().xx.yy;
        int cy = q.front().yy.xx;
        int cx = q.front().yy.yy;
        q.pop();

        if(ck == (1<<K)-1) return cd;
        for(int i=0; i<4; i++){
            int nd = cd + 1;
            int nk = ck;
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M || m[ny][nx]==-1) continue;
            if(m[ny][nx] > 0) nk |= (1<<(m[ny][nx]-1));
            if(vi[ny][nx][nk]) continue;
            q.push({{nd,nk}, {ny,nx}});
            vi[ny][nx][nk] = true;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin>>M>>N;
        if(!N) break;
        memset(m,-1,sizeof(m));
        int sty, stx, K=0;
        string str;
        for(int i=0; i<N; i++){
            cin>>str;
            for(int j=0; j<M; j++){
                if(str[j] == 'o') sty = i, stx = j, m[i][j] = 0;
                else if(str[j] == '*') m[i][j] = ++K;
                else if(str[j] == 'x') m[i][j] = -1;
                else m[i][j] = 0;
            }
        }

        cout<<bfs(sty, stx, K)<<'\n';
    }
}