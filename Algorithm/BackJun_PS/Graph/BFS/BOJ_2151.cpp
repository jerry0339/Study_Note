// https://www.acmicpc.net/problem/2151
// https://www.acmicpc.net/problem/6087
// 

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

int N;
int sty=-1, stx, edy, edx;
char m[100][100]{};
int vi[100][100]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int bfs(){
    memset(vi,0x3f,sizeof(vi));
    queue<tpi> q;
    q.push({0,sty,stx});
    vi[sty][stx] = 0;
    m[edy][edx] = '!';

    while(!q.empty()){
        int cd,cy,cx;
        tie(cd,cy,cx) = q.front();
        q.pop();

        if(cy == edy && cx == edx) return cd;
        int nd = cd + 1;
        for(int i=0; i<4; i++){
            for(int j=1; ;j++){
                int ny = cy + j*dy[i];
                int nx = cx + j*dx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=N || m[ny][nx]=='*') break;
                if(m[ny][nx]!='!') continue;
                if(vi[ny][nx]==INF) {
                    q.push({nd,ny,nx});
                    vi[ny][nx] = nd;
                } else if(vi[ny][nx]==nd) continue;
                else break;
            }
        }
    }

    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    string str;
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<N; j++){
            m[i][j] = str[j];
            if(m[i][j] == '#'){
                if(sty==-1) sty = i, stx = j;
                else edy = i, edx = j;
            }
        }
    }

    cout<<bfs()-1<<'\n';
}