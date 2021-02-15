// <서강그라운드> - BOJ_14938
// 플로이드와샬 풀이

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;

int N,R,M;
int adj[101][101];
int it[101]{};
int d[101]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>R>>M;
    memset(adj,0x3f,sizeof(adj));
    for(int i=1; i<=N; i++) cin>>it[i];
    for(int i=1; i<=M; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(adj[i][k]+adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
        }
    }

    int max_=0;
    for(int i=1; i<=N; i++){
        d[i]+=it[i];
        for(int j=1; j<=N; j++){
            if(i==j) continue;
            if(adj[i][j]<=R) d[i]+=it[j];
        }
        max_=max(max_,d[i]);
    }
    cout<<max_;
}