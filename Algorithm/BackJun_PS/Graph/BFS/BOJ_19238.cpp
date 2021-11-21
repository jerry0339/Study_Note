// <스타트택시> - BOJ_19238
// 구현, BFS

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define xx first
#define yy second
const int INF = 1e9;

int N, M, R, sty, stx;
int m[21][21]{};
vector<pair<pii, pii>> v(401);
vector<int> des(401);
bool vi[21][21]{};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void solve1() {
    memset(vi, 0, sizeof(vi));
    queue<pair<int, pii>> q;
    q.push({ 0,{sty,stx} });
    vi[sty][stx] = true;

    int my=INF, mx=INF, md = INF;
    while (!q.empty()) {
        int cd = q.front().xx;
        int cy = q.front().yy.xx;
        int cx = q.front().yy.yy;
        q.pop();

        if (m[cy][cx] > 1) {
            if (cd < md) { my = cy; mx = cx; md=cd;}
            else if (cd == md) {
                if (my > cy) { my = cy; mx = cx; md=cd;}
                else if (my == cy) {
                    if (mx > cx) { my = cy; mx = cx; md=cd;}
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny <= 0 || nx <= 0 || ny > N || nx > N || vi[ny][nx] || m[ny][nx] == 1) continue;
            q.push({ cd + 1,{ny,nx} });
            vi[ny][nx] = true;
        }
    }

    if (md == INF) {cout<<-1; exit(0);}
    int disidx = m[my][mx]-1;
    R -= (des[disidx] + md);
    if(R<0) { cout << -1; exit(0); }
    else {
        R += des[disidx]*2;
        sty = v[disidx].yy.xx; 
        stx = v[disidx].yy.yy;
        m[my][mx] = 0;
    }
}

int solve2(int sty, int stx, int edy, int edx){
    memset(vi, 0, sizeof(vi));
    queue<pair<int, pii>> q;
    q.push({ 0,{sty,stx} });
    vi[sty][stx] = true;

    while (!q.empty()) {
        int cd = q.front().xx;
        int cy = q.front().yy.xx;
        int cx = q.front().yy.yy;
        q.pop();

        if (cy == edy && cx == edx) return cd;

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny <= 0 || nx <= 0 || ny > N || nx > N || vi[ny][nx] || m[ny][nx] == 1) continue;
            q.push({ cd + 1,{ny,nx} });
            vi[ny][nx] = true;
        }
    }
    cout<<-1;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> m[i][j];
        }
    }
    cin >> sty >> stx;
    for (int i = 1; i <= M; i++) {
        cin >> v[i].xx.xx >> v[i].xx.yy >> v[i].yy.xx >> v[i].yy.yy;
        m[v[i].xx.xx][v[i].xx.yy] = i + 1;
    }

    for(int i=1; i<=M; i++){
        des[i] = solve2(v[i].xx.xx, v[i].xx.yy, v[i].yy.xx, v[i].yy.yy);
    }
    
    for(int i=1; i<=M; i++) {
        solve1();
    }
    cout << R;
}