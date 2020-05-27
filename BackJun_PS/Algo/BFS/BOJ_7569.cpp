// <도마도> - BOJ_7569
// BFS - 3차원 탐색

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define aa first
#define bb second
#define all(v) (v).begin(), (v).end()

int M,N,H;
int m[100][100][100];
bool vi[100][100][100]={0,};
queue<pair<pii,pii>> q;
int dh[6] = {-1,1,0,0,0,0};
int dn[6] = {0,0,-1,1,0,0};
int dm[6] = {0,0,0,0,-1,1};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N>>H;
    for(int h=0; h<H; h++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>m[h][i][j];
                if(m[h][i][j]==1) {
                    q.push({{0,h},{i,j}});
                    vi[h][i][j] = true;
                }
            }
        }
    }

    while(!q.empty()){
        int cdis = q.front().aa.aa;
        int ch = q.front().aa.bb;
        int cn = q.front().bb.aa;
        int cm = q.front().bb.bb;
        q.pop();

        for(int i=0; i<6; i++){
            int nh = ch+dh[i];
            int nn = cn+dn[i];
            int nm = cm+dm[i];
            if(nh<0 || nn<0 || nm<0 || nh>=H || nn>=N || nm>=M) continue;
            if(!m[nh][nn][nm] && !vi[nh][nn][nm]){
                q.push({{cdis+1,nh},{nn,nm}});
                m[nh][nn][nm] = cdis+2;
                vi[nh][nn][nm]=true;
            }
        }
    }

    int ans=0;
    for(int h=0; h<H; h++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(!m[h][i][j]) {
                    cout<<"-1";
                    return 0;
                }
                ans = max(ans,m[h][i][j]);
            }
        }
    }
    cout<<ans-1;
}