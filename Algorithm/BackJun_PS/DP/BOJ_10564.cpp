#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
using tpi = tuple<int,int,int>;

int T,N,M;
int m[11]{};
bool dp[1111][5555]{};

int solve() {
    memset(dp, 0, sizeof(dp));
    queue<tpi> q;
    for(int i=0; i<M; i++) {
        int now = m[i];
        q.push({now, now, now});
        dp[now][now] = true;
    }

    while(!q.empty()){
        int csc, cas, cps;
        tie(csc, cas, cps) = q.front();
        q.pop();

        for(int i=0; i<M; i++){
            int nsc = csc + m[i];
            int nas = cas + m[i];
            int nps = cps + nas;
            if(nps > 5000 || dp[nsc][nps]) continue;
            q.push({nsc, nas, nps});
            dp[nsc][nps] = true;
        }
    }

    for(int i=1111; i>=1; i--) {
        if(dp[i][N]) return i;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i=0; i<M; i++) cin>>m[i];
        cout<<solve()<<'\n';
    }
}