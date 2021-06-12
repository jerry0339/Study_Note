#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using pii = pair<int,int>;
using tpi = tuple<int,int,int>;
const int INF = 0x3f3f3f3f;

int TC,N,M,W;
vector<tpi> edge;
int dist[501]{};

bool BellmanFord(int st){
    memset(dist,0x3f,sizeof(dist));
    dist[st] = 0;
    for(int k=1; k<=N; k++){
        bool chk = false;
        for(auto e : edge){
            int a,b,c;
            tie(a,b,c) = e;
            if(dist[a]==INF) continue;
            if(dist[b] > dist[a] + c){
                dist[b] = dist[a] + c;
                chk = true;
                if(k==N) return false; // 사이클 있음
            }
        }
        if(!chk) break;
    }
    return true; // 사이클 없음
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int S,E,T;
    cin>>TC;
    while(TC--){
        edge.clear();
        cin>>N>>M>>W;
        for(int i=0; i<M; i++){
            cin>>S>>E>>T;
            edge.push_back({S,E,T}); // 양방향 간선
            edge.push_back({E,S,T});
        }
        for(int i=0; i<W; i++){
            cin>>S>>E>>T;
            edge.push_back({S,E,-T}); // 웜홀은 방향 있음
        }
        
        bool res = false;
        for(int i=1; i<=N; i++){ // 모든 노드를 시작점으로 확인
            if(!BellmanFord(i)) {
                res = true;
                break;
            }
        }

        if(!res) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }

}