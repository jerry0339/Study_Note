#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

struct Info {
    int y,x,l,r;
    Info(int y=0, int x=0, int l=0, int r=0)
    : y(y), x(x), l(l), r(r) {}
};

int N,M,K;
int m[51][51]{};
bool vi[51][51][151][151]{};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

bool solve(){
    queue<Info> q;
    q.push(Info(0,0,0,0));
    vi[0][0][0][0] = true;

    while(!q.empty()){
        int cy = q.front().y;
        int cx = q.front().x;
        int cl = q.front().l;
        int cr = q.front().r;
        q.pop();

        if(cy==N-1 && cx==M-1)
            if(max(cl,cr)<=K)
                return true;

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            int cd = m[cy][cx]+4;
            int nl1=cl,nr1=cr, nl2=cl,nr2=cr;
            bool chk = false;
            if(cd%4 == i) {
                nl1 = cl, nr1 = cr;
                chk = true;
            }
            else if((cd-1)%4 == i) {
                nl1 = cl+1, nr1 = cr;
                nl2 = cl,   nr2 = cr+3;
            }
            else if((cd+1)%4 == i) {
                nl1 = cl,   nr1 = cr+1;
                nl2 = cl+3, nr2 = cr;
            }
            else if((cd+2)%4 == i) {
                nl1 = cl + 2, nr1 = cr;
                nl2 = cl,     nr2 = cr+2;
            }
            if(max(nl1,nr1) <= K && !vi[ny][nx][nl1][nr1]) {
                q.push(Info(ny,nx,nl1,nr1));
                vi[ny][nx][nl1][nr1] = true;
            }
            if(chk) continue;
            if(max(nl2,nr2) <= K && !vi[ny][nx][nl2][nr2]) {
                q.push(Info(ny,nx,nl2,nr2));
                vi[ny][nx][nl2][nr2] = true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    string str;
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<M; j++){
            if(str[j]=='U') m[i][j] = 0;
            else if(str[j]=='R') m[i][j] = 1;
            else if(str[j]=='D') m[i][j] = 2;
            else if(str[j]=='L') m[i][j] = 3;
        }
    }
    if(solve()) cout<<"Yes";
    else cout<<"No";
}