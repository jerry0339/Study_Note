#include<bits/stdc++.h>
#define MAX 200
using namespace std;

int N,M;
vector<int> adj[MAX+1]{};
int A[MAX+1]{};
bool B[MAX+1]{};


bool dfs(int cur){
    for(auto next : adj[cur]){
        if(B[next]) continue;
        B[next] = true;
        if(A[next]==0 || dfs(A[next])) {
            A[next] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int C, t;
    for(int i=1; i<=N; i++) {
        cin>>C;
        while(C--) {
            cin>>t;
            adj[i].push_back(t);
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++){
        memset(B,0,sizeof(B));
        if(dfs(i)) ans++;
    }
    cout<<ans;
}