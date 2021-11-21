// <미네랄> - BOJ_2933
// Graph, Implement, Simulation

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int INF = 0x3f3f3f3f;

int R,C,N;
char m[110][110]{};
int h[110]{}; // input layer
vector<pii> g[10010]{}; // save group
int gRIdx[10010]{}; // group max Row idx
bool vi[110][110]{};
bool vi2[10010]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void chkGrp(int y, int x, int cnt) {
    queue<pii> q;
    q.push({y,x});
    vi[y][x] = true;
    g[cnt].push_back({y,x});
    gRIdx[cnt] = y;
    
    while(!q.empty()){
        int cy = q.front().xx;
        int cx = q.front().yy;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<1 || nx<1 || ny>R || nx>C || vi[ny][nx] || m[ny][nx]=='.') continue;
            q.push({ny,nx});
            vi[ny][nx] = true;
            g[cnt].push_back({ny,nx});
            gRIdx[cnt] = max(gRIdx[cnt], ny);
        }
    }
}

bool throwStick(int f, int l){
    l = R-l+1;
    if(f){
        for(int i=1; i<=C; i++){
            if(m[l][i]=='x'){ m[l][i] = '.'; return true;}
        }
    } else {
        for(int i=C; i>=1; i--){
            if(m[l][i]=='x'){ m[l][i] = '.'; return true;}
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;

    string str;
    for(int i=1; i<=R; i++){
        cin>>str;
        for(int j=1; j<=C; j++) {
            m[i][j] = str[j-1];
        }
    }
    cin>>N;
    for(int i=1; i<=N; i++) cin>>h[i];

    for(int k=1; k<=N; k++) {
        int cnt = 0 ; // num of group
        memset(gRIdx,0,sizeof(gRIdx));
        memset(vi,0,sizeof(vi));
        memset(vi2,0,sizeof(vi2));
        memset(g,0,sizeof(g));
        if(!throwStick(k%2, h[k])) continue;

        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(vi[i][j] || m[i][j]=='.') continue;
                chkGrp(i,j,cnt);
                cnt++;
            }
        }
        int cnt2=0;
        memset(m,'.',sizeof(m));
        for(int i=0; i<cnt; i++){
            if(gRIdx[i]!=R) continue;
            vi2[i] = true;
            cnt2++;
            for(auto val : g[i]) m[val.xx][val.yy] = 'x';
        }

        while(cnt!=cnt2){
            for(int i=0; i<cnt; i++){
                if(vi2[i]) continue;
                int flag = false;
                for(auto val : g[i]) {
                    if(val.xx+1>R || m[val.xx+1][val.yy]=='x') {
                        vi2[i] = true;
                        flag = true; 
                        cnt2++; 
                        break;
                    }
                }
                if(flag) for(auto val : g[i]) m[val.xx][val.yy] = 'x';
                else for(int j=0; j<g[i].size(); j++) g[i][j].xx+=1;
            }
        }
    }

    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) cout<<m[i][j];
        cout<<'\n';
    }
    
}