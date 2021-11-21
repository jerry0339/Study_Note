#include<bits/stdc++.h>
using namespace std;

int N,M;
int m[50][50]{};
int dist[50][50]{};
bool vi[50][50]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

bool dfs(int cd, int cy, int cx){
    if(vi[cy][cx]) return false;
    vi[cy][cx] = true;

    for(int i=0; i<4; i++){
        int nd = cd + 1;
        int ny = cy + m[cy][cx]*dy[i];
        int nx = cx + m[cy][cx]*dx[i];
        if(ny<0 || nx<0 || ny>=N || nx>=M || !m[ny][nx]) continue;
        if(vi[ny][nx]) return false;
        if(dist[ny][nx] >= nd) continue;
        dist[ny][nx] = nd;
        if(!dfs(nd, ny, nx)) return false;
        vi[ny][nx] = false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    string str;
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<M; j++){
            if(str[j]=='H') m[i][j] = 0;
            else m[i][j] = str[j] - '0';
        }
    }
    
    dist[0][0] = 1;
    if(dfs(1,0,0)) {
        int ans = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                ans = max(ans, dist[i][j]);
        cout<<ans;
    }
    else cout<<-1;
}