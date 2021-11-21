#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tpi = tuple<int,int,int>;
using tpl = tuple<ll,ll,ll>;
using dpi = pair<pii,pii>;
using dpl = pair<pll,pll>;
const int INF = 0x3f3f3f3f;

int N;
int dp[2001][2001]{};

void bfs(){
    memset(dp,0x3f,sizeof(dp));
    priority_queue<tpi, vector<tpi>, greater<tpi>> pq;
    pq.push({0,1,0});
    dp[1][0] = 0;

    while(!pq.empty()){
        int d,n,c;
        tie(d,n,c) = pq.top();
        pq.pop();
        
        if(dp[n][c] < d) continue;
        if(dp[n][n] > d+1){ 
            pq.push({d+1,n,n});
            dp[n][n] = d+1;
        }
        
        if(n+c < N+2 && dp[n+c][c] > d+1){
            pq.push({d+1,n+c,c});
            dp[n+c][c] = d+1;
        }

        if(n-1 > 0 && dp[n-1][c] > d+1){
            pq.push({d+1,n-1,c});
            dp[n-1][c] = d+1;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    bfs();

    int res = INF;
    for(int i=0; i<2002; i++){
        res = min(res, dp[N][i]);
    }
    cout<<res;
}