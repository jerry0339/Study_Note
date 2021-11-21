// 달리기
// 거울에 레이저 쏘는 문제랑 비슷함(대신 레이저 길이제한 존재)
// BFS + 가지치기

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using pii = pair<int,int>;
using tpi = tuple<int,int,int>;
using dpi = pair<pii,pii>;
const int INF = 0x3f3f3f3f;

int N,M,K;
int sty,stx, edy,edx;
char m[1000][1000]{};
int vi[1000][1000]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

// (x,y) -> (y,x) -> 행,열
int bfs(){
    sty--,stx--, edy--,edx--;
    memset(vi,0x3f,sizeof(vi));
    queue<tpi> q;
    q.push({0,sty,stx});
    vi[sty][stx] = 0;

    while(!q.empty()){
        int cd, cy, cx;
        tie(cd, cy, cx) = q.front();
        q.pop();

        if(cy == edy && cx == edx) return cd;

        int nd = cd + 1;
        for(int i=0; i<4; i++){
            for(int j=1; j<=K; j++){
                int ny = cy + j*dy[i];
                int nx = cx + j*dx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=M || m[ny][nx]=='#') break;
                if(vi[ny][nx] == INF) {
                    q.push({nd, ny, nx});
                    vi[ny][nx] = nd;
                    continue;
                }
                if(nd == vi[ny][nx]) continue;
                else break;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    string str;
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<M; j++){
            m[i][j] = str[j];
        }
    }
    cin>>sty>>stx>>edy>>edx;
    cout<<bfs();
}