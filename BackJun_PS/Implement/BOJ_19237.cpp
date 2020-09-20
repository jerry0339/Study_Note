// <어른 상어> - BOJ_19237
// 시뮬레이션, 구현

#include<bits/stdc++.h>
using namespace std;

int N,M,K;
int shk[401][5][5]{}; // shark direction info
int m[21][21][3]{}; // [0]:shk_num, [1]:gas, [2]:flag
// flag : K+1로 업데이트시 이전에 빈칸인지 자기영역으로 되돌아온것인지 확인하기 위함
int info[401][3]{}; // [0]:dir, [1]:y, [2]:x
bool vi[401]{}; // isdead
int cnt=0, tcnt=0;

int dy[5] = {0,-1,1,0,0};
int dx[5] = {0,0,0,-1,1};

void killshk(int i){
    vi[i] = true;
    cnt--;
}

void updatem(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            m[i][j][2] = 0;
            if(m[i][j][1]) m[i][j][1]--;
            if(m[i][j][1]==0) m[i][j][0] = 0;
        }
    }
}

void moveshk(int i, int ndir, int ny, int nx){
    info[i][0] = ndir;
    info[i][1] = ny;
    info[i][2] = nx;
    m[ny][nx][0] = i;
    m[ny][nx][1] = K+1;
}

void chkArea(int i){
    int cdir = info[i][0];
    int cy = info[i][1];
    int cx = info[i][2];
    for(int k=1; k<=4; k++){
        int ndir = shk[i][cdir][k];
        int ny = cy + dy[ndir];
        int nx = cx + dx[ndir];
        if(ny<1 || nx<1 || ny>N || nx>N || m[ny][nx][2]) continue;
        if(m[ny][nx][1]==K+1) {
            int p = m[ny][nx][0];
            if(p < i){
                killshk(i);
            } else {
                killshk(p);
                moveshk(i, ndir, ny, nx);
            }
            return;
        }
        if(m[ny][nx][0]) continue;
        moveshk(i, ndir, ny, nx);
        return;
    }

    for(int k=1; k<=4; k++){
        int ndir = shk[i][cdir][k];
        int ny = cy + dy[ndir];
        int nx = cx + dx[ndir];
        if(ny<1 || nx<1 || ny>N || nx>N || m[ny][nx][0]!=i) continue;
        moveshk(i, ndir, ny, nx);
        m[ny][nx][2] = 1;
        return;
    }
}

void move(){
    for(int i=1; i<=M; i++){
        if(vi[i]) continue;
        chkArea(i);
    }
    
    updatem();
    tcnt++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    cnt = M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin>>m[i][j][0];
            if(m[i][j][0]) {
                m[i][j][1] = K;
                info[m[i][j][0]][1] = i;
                info[m[i][j][0]][2] = j;
            }
        }
    }
    for(int i=1; i<=M; i++) cin>>info[i][0];
    for(int s=1; s<=M; s++){
        for(int i=1; i<=4; i++){
            for(int j=1; j<=4; j++){
                cin>>shk[s][i][j];
            }
        }
    }

    while(tcnt<=1000){
        if(cnt==1) break;
        move();
    }
    if(tcnt<=1000) cout<<tcnt;
    else cout<<-1;
}