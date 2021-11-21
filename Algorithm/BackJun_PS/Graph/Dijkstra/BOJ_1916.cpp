// <최소비용 구하기> - BOJ_1916
// 다익스트라

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define xx first
#define yy second
const int INF = 0x3f3f3f3f;

int N,M;
vector<pii> adj[1001];
int d[1001]{};

void solve(int st, int ed){
    memset(d,0x3f,sizeof(d));
    priority_queue<pii> pq;
    pq.push({0,st});
    d[st] = 0;

    while(!pq.empty()){
        int cd = -pq.top().xx;
        int cp = pq.top().yy;
        pq.pop();
        
        if(cp==ed) {cout<<d[cp]; exit(0);}
        if(cd > d[cp]) continue;

        for(int i=0; i<adj[cp].size(); i++){
            int np = adj[cp][i].xx;
            int nd = adj[cp][i].yy + cd;

            if(nd < d[np]){
                d[np] = nd;
                pq.push({-nd,np});
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
    }

    int st, ed;
    cin>>st>>ed;
    solve(st-1,ed-1);
}