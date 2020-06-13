// <맥주 마시면서 걸어가기> - BOJ_9205
// 플로이드 와샬 

#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) (int)(x).size()
#define aa first
#define bb second
#define abs(x) ((x) < 0 ? (-(x)) : (x))
typedef pair<int, int> pii;
typedef long long ll;

int T,N;
vector<pii> pos;
int m[102][102]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    int sty, stx, mky, mkx, endy, endx;
    while(T--){
        cin>>N;
        pos.clear();
        memset(m,0,sizeof(m));
        cin>>sty>>stx;
        pos.push_back({sty,stx});
        for(int i=0; i<N; i++){
            cin>>mky>>mkx;
            pos.push_back({mky,mkx});
        }
        cin>>endy>>endx;
        pos.push_back({endy,endx});
        
        for(int i=0; i<N+2; i++){
            for(int j=0; j<N+2; j++){
                if(m[i][j]) continue;
                int dis = abs(pos[i].aa-pos[j].aa) + abs(pos[i].bb-pos[j].bb);
                dis = (dis+49)/50;
                if(dis<=20){
                    m[i][j] = 1;
                    m[j][i] = 1;
                } else {
                    m[i][j] = -1;
                    m[j][i] = -1;
                }
            }
        }
        
        for(int k=0; k<N+2; k++){
            for(int i=0; i<N+2; i++){
                for(int j=0; j<N+2; j++){
                    if(m[i][k]==1 && m[k][j]==1) {
                        m[i][j] = 1;
                    }
                }
            }
        }

        if(m[0][N+1]==1) cout<<"happy\n";
        else cout<<"sad\n";
    }
}