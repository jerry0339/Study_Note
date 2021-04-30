#include<bits/stdc++.h>
using namespace std;

int N,M,cnt=0, score=0;
int m[50][50]{};
vector<int> tmp;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int td[4] = {2,1,3,0};

void updateMap(){
    memset(m,0,sizeof(m));
    int cy,cx,d=0,t=1;
    cy = cx = N/2;
    int idx = 0;
    while(idx!=tmp.size()){
        for(int k=0; k<2; k++){
            for(int i=0; i<t; i++){
                int ny = cy + dy[td[d]];
                int nx = cx + dx[td[d]];
                m[ny][nx] = tmp[idx++];
                cy = ny;
                cx = nx;
                if(idx==tmp.size()) return;
            }
            d = (d+1)%4;
        }
        t++;
    }
}

void change(){
    vector<int> ttmp;
    int tt;
    for(int i=0; i<tmp.size(); i++){
        if(ttmp.size()>=N*N) break;
        tt = i;
        while(tmp[tt]==tmp[i] && tt<tmp.size()) tt++;
        int A=(tt-i), B=tmp[i];
        ttmp.push_back(A);
        ttmp.push_back(B);
        i = tt-1;
    }
    if(ttmp.size()>=N*N)
        while(ttmp.size()>=N*N) ttmp.pop_back();
    tmp = ttmp;
    cnt = tmp.size();
}

void explode(){
    bool chk = true;
    while(chk){
        vector<int> ttmp;
        int tt;
        chk = false;
        for(int i=0; i<tmp.size(); i++){
            tt = i;
            while(tmp[tt]==tmp[i] && tt<tmp.size()) tt++;
            if(tt-i<4) {
                for(int j=i; j<tt; j++){
                    ttmp.push_back(tmp[i]);
                }
            } else {
                score += tmp[i]*(tt-i);
                chk = true;
            }
            i = tt-1;
        }
        tmp = ttmp;
    }
}

void saveBall(){
    tmp.clear();
    int cy,cx,d=0,t=1;
    cy = cx = N/2;

    int idx = 0;
    while(idx!=cnt){
        for(int k=0; k<2; k++){
            for(int i=0; i<t; i++){
                int ny = cy + dy[td[d]];
                int nx = cx + dx[td[d]];
                if(m[ny][nx]) {
                    tmp.push_back(m[ny][nx]);
                    idx++;
                }
                cy = ny;
                cx = nx;
                if(idx==cnt) return;
            }
            d = (d+1)%4;
        }
        t++;
    }
}

void magic(int d, int s){
    for(int i=1; i<=s; i++){
        int ny = N/2 + i*dy[d];
        int nx = N/2 + i*dx[d];
        if(m[ny][nx]==0) continue;
        m[ny][nx] = 0;
        cnt--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>m[i][j];
            if(m[i][j]) cnt++;
        }
    }

    int d, s;
    for(int i=0; i<M; i++){
        cin>>d>>s; d--;
        magic(d,s);
        saveBall();
        explode();
        change();
        updateMap();
    }
    
    cout<<score;
}