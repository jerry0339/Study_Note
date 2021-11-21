// <미로만들기> - BOJ_2665
// 다익스트라 풀이

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int INF = 1e9;

int N;
int m[51][51]{};
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int d[51][51]{};

int solve(){
    priority_queue<piii> pq;
    pq.push({0,{0,0}}); // dis, y, x
    d[0][0] = 0;

    while(!pq.empty()){
        int cd = -pq.top().xx;
        int cy = pq.top().yy.xx;
        int cx = pq.top().yy.yy;
        pq.pop();

        if(cd>d[cy][cx]) continue;
        if(cy==N-1 && cx==N-1) return cd/2500;

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
            int nd;
            if(!m[ny][nx]) nd = cd+2500;
            else nd = cd + 1;
            if(nd < d[ny][nx]){
                d[ny][nx] = nd;
                pq.push({-nd,{ny,nx}});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    string str;
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<N; j++) {
            m[i][j] = str[j]-'0';
            d[i][j] = INF;
        }
    }
    cout<<solve();
}
