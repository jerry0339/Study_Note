// <서강그라운드> - BOJ_14938
#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9;

int N,R,M;
vector<pii> adj[110];
int it[110]{};
int d[110]{};

void solve(int start) {
    priority_queue<pii> pq;
    pq.push({0,start});
    d[start] = 0;

    while(!pq.empty()){
        int cdis = -pq.top().xx;
        int cpos = pq.top().yy;
        pq.pop();

        if(cdis>d[cpos]) continue;
        for(int i=0; i<adj[cpos].size(); i++){
            int npos = adj[cpos][i].xx;
            int ndis = adj[cpos][i].yy + cdis;

            if(ndis < d[npos]){
                d[npos] = ndis;
                pq.push({-d[npos],npos});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>R>>M;
    for(int i=0; i<N; i++) cin>>it[i];
    for(int i=0; i<M; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
        adj[b-1].push_back({a-1,c});
    }
    int max_ =0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) d[j] = INF;
        solve(i);
        int cnt=0;
        for(int j=0; j<N; j++){
            if(d[j]<=R){
                cnt+=it[j];
            }
        }
        max_ = max(max_,cnt);
    }
    cout<<max_;
}