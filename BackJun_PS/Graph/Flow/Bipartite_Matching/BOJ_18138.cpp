#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int> adj[201]{};
int A[201]{};
int B[201]{};
bool vi[201]{};

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
    double t;
    for(int i=0; i<N; i++) {
        cin>>t;
        shirt.push_back(t);
    }
    for(int i=0; i<M; i++){
        cin>>t;
        kara.push_back(t);
    }
    sort(kara.begin(), kara.end());

    int a,b,c,d;
    for(int i=0; i<N; i++){
        double w = shirt[i];
        // 너비가 w/2 이상 w×3/4이하
        a = (int)ceil(w/2);
        b = (int)floor(w*3/4);
        a = lower_bound(kara.begin(), kara.end(), a) - kara.begin();
        b = upper_bound(kara.begin(), kara.end(), b) - kara.begin();
        for(int j=a; j<b; j++) adj[i].push_back(j);
        // 너비가 w 이상 w×5/4 이하
        c = (int)w;
        d = (int)floor(w*5/4);
        c = lower_bound(kara.begin(), kara.end(), c) - kara.begin();
        d = upper_bound(kara.begin(), kara.end(), d) - kara.begin();
        for(int j=c; j<d; j++) adj[i].push_back(j);
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    int ans = 0;
    for(int i=0; i<N; i++){
        if(A[i] == -1){
            memset(vi, 0, sizeof(vi));
            if(dfs(i)) ans++;
        }
    }
    cout<<ans;
}