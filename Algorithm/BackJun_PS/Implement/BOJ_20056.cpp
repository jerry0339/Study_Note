#include<bits/stdc++.h>
using namespace std;

struct FireBall{
    int r,c,m,s,d;
    FireBall(int r=0, int c=0, int m=0, int s=0, int d=0):
    r(r), c(c), m(m), s(s), d(d){}
};

struct Info{
    int n,m,s,d;
    Info(int n=0, int m=0, int s=0, int d=0):
    n(n), m(m), s(s), d(d){}
};

int N,M,K;
Info m[51][51]{};
vector<FireBall> fb;
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};

void update(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(m[i][j].n==1) {
                fb.emplace_back(FireBall(i,j, m[i][j].m, m[i][j].s, m[i][j].d));
            } 
            else if(m[i][j].n > 1){
                int nm = m[i][j].m / 5;
                if(nm==0) continue;
                int ns = m[i][j].s / m[i][j].n;
                vector<int> nd(4);
                if(m[i][j].d == -1) nd = {1,3,5,7};
                else nd = {0,2,4,6};
                for(int k=0; k<4; k++){
                    fb.emplace_back(FireBall(i,j, nm, ns, nd[k]));
                }
            }
        }
    }
}

void move(){
    memset(m,0,sizeof(m));
    for(auto val : fb){
        int ny = (N*1000 + val.r + val.s * dy[val.d])%N;
        int nx = (N*1000 + val.c + val.s * dx[val.d])%N;
        m[ny][nx].m += val.m;
        m[ny][nx].s += val.s;
        if(m[ny][nx].n == 0) m[ny][nx].d = val.d;
        else {
            if(m[ny][nx].d%2 != val.d%2) m[ny][nx].d = -1;
        }
        m[ny][nx].n++;
    }
    fb.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    memset(m,0,sizeof(m));
    int r,c,m,s,d;
    for(int i=0; i<M; i++) {
        cin>>r>>c>>m>>s>>d;
        fb.emplace_back(FireBall(r,c,m,s,d));
    }
    
    while(K--){
        move();
        update();
    }

    int sum = 0;
    for(auto val : fb) sum += val.m;
    cout<<sum;
}