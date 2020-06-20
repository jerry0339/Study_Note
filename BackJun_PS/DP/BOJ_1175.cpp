// <배달> - BOJ_1175
// 그래프탐색, DP
// 1. 방향까지는 생각하기 쉬웠는데 목적지가 2개라 헷갈린문제. 
//    단순히 cnt변수만들어서 count해주면 WA받음. cnt가 떨어져 있는경우 돌아가는길이 모두 visited될 수 있기때문
//    따라서 DP를 더 이용. -> vi[y][x][온방향][목적지1방문][목적지2방문]
// 2. bfs함수에 return을 박아봄 - > 오류
//    조건만족했을때만 return함 -> 모든경우에 return이 가능하다 하더라도 기본 return이 꼭 들어가야함.( 아래코드의 return -1)
//    따라서 함수를 만들지 않거나, 조건만족시 exit(0)을 이용해 탈출

#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) (int)(x).size()
#define ini(x, y) memset(x, y, sizeof(x))
#define xx first
#define yy second
typedef pair<int, int> pii;
typedef long long ll;

int N,M;
int m[51][51]{};
bool vi[51][51][4][2][2]{};
pii scc[3];
int dy[4] ={-1,1,0,0};
int dx[4] ={0,0,-1,1};

struct info{
    info(int dis_=0, int dir_=0, int y_=0, int x_=0, int c_=0)
     :dis(dis_), dir(dir_), y(y_), x(x_), c(c_){}
    int dis,dir,y,x,c;
};

int solve(){
    memset(vi,0,sizeof(vi));
    queue<info> q;    
    q.push(info(0,5,scc[0].xx,scc[0].yy,0));

    while(!q.empty()){
        info inf = q.front();
        int cdis = inf.dis;
        int cdir = inf.dir;
        int cy = inf.y;
        int cx = inf.x;
        q.pop();

        if(!inf.c){
            if(cy==scc[1].xx && cx==scc[1].yy) inf.c=1;
            if(cy==scc[2].xx && cx==scc[2].yy) inf.c=2;
        } else {
            if(cy==scc[1].xx && cx==scc[1].yy && inf.c==2) return cdis;
            if(cy==scc[2].xx && cx==scc[2].yy && inf.c==1) return cdis;
        }

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int c1=0, c2=0;
            if(inf.c==1) c1=1;
            if(inf.c==2) c2=1;
            if(cdir==i || ny<0 || ny>=N || nx<0 || nx>=M || vi[ny][nx][i][c1][c2]) continue;
            if(m[ny][nx]==1) continue;
            
            q.push(info(cdis+1,i,ny,nx,inf.c));
            vi[ny][nx][i][c1][c2] = true;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int cnt=1;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        for(int j=0; j<M; j++){
            if(str[j]=='.') continue;
            else if(str[j]=='#') m[i][j] = 1;
            else if(str[j]=='C') {
                scc[cnt].xx = i; scc[cnt].yy=j;
                cnt++;
            }
            else {scc[0].xx = i; scc[0].yy=j;}
        }
    }
    cout<<solve();
}