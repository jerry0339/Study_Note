// <친구> - BOJ_1058
// adj로부터 거리가 2인 노드들 그래프에서 모두 탐색

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define xx first
#define yy second
#define all(v) (v).begin(), (v).end()

int N;
vector<vector<int>> adj;
vector<set<int>> fr;
bool vi[51]={0,};

void bfs(int start){
    queue<pii> q;
    q.push(make_pair(0,start));
    vi[start] = true;

    while(!q.empty()){
        int cdis = q.front().xx;
        int cpos = q.front().yy;
        q.pop();
        if(cdis==2) continue;

        for(auto val : adj[cpos]){
            if(vi[val]) continue;
            q.push({cdis+1,val});
            fr[start].insert(val); // 거리가 2보다 작으면 저장
            vi[val] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    adj.resize(N+1);
    fr.resize(N+1);
    char ch;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++){
            cin>>ch;
            if(ch=='Y') {
                adj[i].push_back(j);
            }
        }
    }

    for(int i=1; i<=N; i++) {
        memset(vi,0,sizeof(vi));
        bfs(i);
    }

    int max_=0;
    for(int i=1; i<=N; i++){
        int sz = fr[i].size();
        max_ = max(max_,sz);
    }
    cout<<max_;
}