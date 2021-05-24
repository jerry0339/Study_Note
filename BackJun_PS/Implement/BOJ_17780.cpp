// https://www.acmicpc.net/problem/3770

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using pii = pair<int,int>;
using dpi = pair<pii,pii>;

int N,K;
int m[12][12]{};
int km[12][12]{};
vector<dpi> kv[10];
bool kvi[10]{};
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};

bool makeK0(int cy, int cx, int ny, int nx){
    int ci = km[cy][cx];
    int ni = km[ny][nx];
    km[cy][cx] = -1;
    if(ni==-1) {
        km[ny][nx] = ci;
        kv[ci][0].xx.xx = ny;
        kv[ci][0].xx.yy = nx;
    } else {
        kv[ni].insert(kv[ni].end(), kv[ci].begin(),kv[ci].end());
        kv[ci].clear();
        if(kv[ni].size() >= 4) return true;
    }
    return false;
}

bool makeK1(int cy, int cx, int ny, int nx){
    int ci = km[cy][cx];
    int ni = km[ny][nx];
    km[cy][cx] = -1;
    if(ni==-1) {
        ni = kv[ci].back().yy.yy;
        kv[ni].assign(kv[ci].rbegin(), kv[ci].rend());
        if(ci!=ni) kv[ci].clear();
        km[ny][nx] = ni;
        kv[ni][0].xx.xx = ny;
        kv[ni][0].xx.yy = nx;
    } else {
        kv[ni].insert(kv[ni].end(), kv[ci].rbegin(),kv[ci].rend());
        kv[ci].clear();
        if(kv[ni].size() >= 4) return true;
    }
    return false;
}

bool makeK2(int idx, int cy, int cx, int cdir){
    int ndir = cdir;
    if(cdir==0) ndir = 1;
    else if(cdir==1) ndir = 0;
    else if(cdir==2) ndir = 3;
    else if(cdir==3) ndir = 2;
    kv[idx][0].yy.xx = ndir;
    int ny = cy + dy[ndir];
    int nx = cx + dx[ndir];
    if(ny<0 || nx<0 || ny>=N || nx>=N || m[ny][nx]==2) {
        return false;
    } else if(m[ny][nx]==1){
        return makeK1(cy,cx,ny,nx);
    } else {
        return makeK0(cy,cx,ny,nx);
    }
}

bool move(){
    for(int i=0; i<K; i++){
        if(kv[i].size()==0) continue;
        int cy = kv[i][0].xx.xx;
        int cx = kv[i][0].xx.yy;
        int cdir = kv[i][0].yy.xx;
        int ny = cy + dy[cdir];
        int nx = cx + dx[cdir];
        if(ny<0 || nx<0 || ny>=N || nx>=N || m[ny][nx]==2){
            if(makeK2(i,cy,cx,cdir)) return true;
        } else if(m[ny][nx] == 1){
            if(makeK1(cy,cx,ny,nx)) return true;
        } else { // m[ny][nx]==0
            if(makeK0(cy,cx,ny,nx)) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>m[i][j];
        }
    }

    memset(km,-1,sizeof(km));
    int a,b,c;
    for(int i=0; i<K; i++){
        cin>>a>>b>>c;
        a--; b--; c--;
        kv[i].push_back({{a,b},{c,i}});
        km[a][b] = i;
    }
    
    int ans = 1;
    while(!move()){
        ans++;
        if(ans>1000) break;
    }
    
    if(ans>1000) cout<<-1;
    else cout<<ans;
}

/*
void printkm(int idx){
    cout<<idx<<": "<<'\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<km[i][j]+1<<' ';
        }
        cout<<"   ";
        for(int j=0; j<N; j++){
            if(km[i][j]==-1) cout<<0<<' ';
            else cout<<kv[km[i][j]][0].yy.xx+1<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}
*/