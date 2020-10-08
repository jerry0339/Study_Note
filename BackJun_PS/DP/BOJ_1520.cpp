// <내리막 길> - BOJ_1520
// DP 바텀업 풀이

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int INF = 0x3f3f3f3f;

int N,M;
int m[505][505]{};
vector<piii> h;
int dp[505][505]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

bool comp(piii &a, piii &b){
    return a.xx> b.xx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int max_=1;
    int min_=10000;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>m[i][j];
            h.push_back({m[i][j],{i,j}});
        }
    }
    sort(h.begin(), h.end(), greater<piii>());

    dp[1][1] = 1;
    for(auto val : h){
        int ht = val.xx;
        int y = val.yy.xx;
        int x = val.yy.yy;
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<1 || nx<1 || ny>N || nx>M) continue;
            if(ht < m[ny][nx]) dp[y][x] += dp[ny][nx];
        }
    }

    cout<<dp[N][M];
}