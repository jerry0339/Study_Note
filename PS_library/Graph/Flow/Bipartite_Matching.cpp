// DFS 이용한 간단한 이분매칭
// O(V*E) 풀이

#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int> adj[101]{};
int A[101]{};
int B[5001]{};
bool vi[101]{};

bool dfs(int cur){
    if(vi[cur]) return false;
    vi[cur] = true;
    for(auto next : adj[cur]){
        if(B[next]==-1 || dfs(B[next])){
            A[cur] = next;
            B[next] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int a,b;
    for(int i=1; i<=M; i++) {
        cin>>a>>b;
        adj[a].push_back(b);
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(A[i] == -1){
            memset(vi, 0, sizeof(vi));
            if(dfs(i)) ans++;
        }
    }
    cout<<ans;
}