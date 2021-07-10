#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tpi = tuple<int,int,int>;
using tpl = tuple<ll,ll,ll>;
using dpi = pair<pii,pii>;
using dpl = pair<pll,pll>;
const int INF = 0x3f3f3f3f;

int N,M;
int m[1001][1001]{};
int mIdx[1001][1001]{};
int idxCount[1000000]{};
bool vi[1001][1001]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int bfs(int sty, int stx, int idx){
    int res = 1;
    queue<pii> q;
    q.push({sty, stx});
    vi[sty][stx] = true;
    mIdx[sty][stx] = idx;

    while(!q.empty()){
        int cy = q.front().xx;
        int cx = q.front().yy;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            if(vi[ny][nx] || !m[ny][nx]) continue;
            q.push({ny,nx});
            vi[ny][nx] = true;
            mIdx[ny][nx] = idx;
            res++;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>m[i][j];
        }
    }
    
    int idx = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(m[i][j] && !vi[i][j]) {
                idxCount[idx] = bfs(i,j, idx);
                idx++;
            }
        }
    }

    int ans = 0;
    set<int> s;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            s.clear();

            if(m[i][j]==0) {
                for(int k=0; k<4; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny<0 || nx<0 || ny>=N || nx>=M || !m[ny][nx]) continue;
                    s.insert(mIdx[ny][nx]);
                }
            }

            int sum = 1;
            for(auto v : s){
                sum += idxCount[v];
            }
            ans = max(ans, sum);
        }
    }

    cout<<ans;
}