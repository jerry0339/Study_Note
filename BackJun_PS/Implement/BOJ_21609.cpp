#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;

int N,M, maxn=0, maxzero=0;
int m[21][21]{};
bool vi[21][21]{};
bool colorVi[21][21]{};
bool maxvi[21][21]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void ccRotate(){
    int tm[N][N]{};
    for(int j=N-1, ii=0; j>=0; j--, ii++){
        for(int i=0, jj=0; i<N; i++, jj++){
            tm[ii][jj] = m[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            m[i][j] = tm[i][j];
        }
    }
}

void gravity(){
    for(int j=0; j<N; j++){
        int bottom = N-1;
        for(int i=N-1; i>=0; i--){
            if(m[i][j]==INF) continue;
            else if(m[i][j]==-1) bottom = i-1;
            else {
                int t = m[i][j];
                m[i][j] = INF;
                m[bottom--][j] = t;
            }
        }
    }
}

pii bfs(int sty, int stx){
    memset(vi,0,sizeof(vi));
    int sum=1, zerosum=0;
    queue<pii> q;
    q.push({sty,stx});
    vi[sty][stx] = true;
    colorVi[sty][stx] = true;

    while(!q.empty()){
        int cy = q.front().xx;
        int cx = q.front().yy;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=N || vi[ny][nx]) continue;
            if(m[ny][nx]==m[sty][stx] || m[ny][nx]==0) {
                q.push({ny,nx});
                vi[ny][nx] = true;
                if(m[ny][nx]==0) zerosum++;
                else colorVi[ny][nx] = true;
                sum++;
            }
        }
    }
    return pii(sum,zerosum);
}

int ans=0; // score
bool findGroup(){
    bool chk = false;
    maxn = 0, maxzero = 0;
    memset(maxvi,0,sizeof(maxvi));
    memset(colorVi,0,sizeof(colorVi));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(m[i][j]==INF || m[i][j]==-1 || m[i][j]==0 || colorVi[i][j]) continue;
            pii k = bfs(i,j);
            if(k.xx < 2) continue;
            if(maxn <= k.xx) {
                if(maxn==k.xx && maxzero > k.yy) continue;
                for(int i=0; i<N; i++)
                    for(int j=0; j<N; j++)
                        maxvi[i][j] = vi[i][j];
                maxn = k.xx;
                maxzero = k.yy;
                chk = true;
            }
        }
    }
    if(!chk) return false;
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(maxvi[i][j]) {
                cnt++;
                m[i][j] = INF;
            }
        }
    }
    ans += cnt*cnt;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>m[i][j];
    
    while(findGroup()){
        gravity();
        ccRotate();
        gravity();
    }

    cout<<ans;
}