// <LCA2> - BOJ_11438
// LCA : 최소공통조상 -> O(logN)

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define MAX_N 100000 // 노드 최대 개수
using namespace std;

int N, M, maxPower = (int)floor(log2(MAX_N));
int ac[MAX_N+1][21]{}; // sparse table
int dpt[MAX_N+1]{}; // depth
vector<int> adj[MAX_N+1]{}; //graph

void dfs(int now, int parent) {
    dpt[now] = dpt[parent] + 1;
    ac[now][0] = parent;

    for (int i = 1; i <= maxPower; i++) // 루트노드를 넘어가면 ac는 0으로 처리됨
        ac[now][i] = ac[ac[now][i-1]][i-1];

    for (int next : adj[now]) {
        if (next == parent) continue; // vi 필요없음 : tree라서 parent일때만 가지쳐주면 됨
        dfs(next, now);
    }
}

int lca(int x, int y) { // O(logN)
    if (dpt[x] > dpt[y]) swap(x, y);
    // dpt[x]==dpt[y]가 되도록 계속 y를 update해줌
    // ex) dpt[x]=2, dpt[y]=5 일때
    //     i가 1일때 dpt[y]=3으로 바꿔주고
    //     i가 0이되면 dpt[y]=2로 바꾸어 dpt[x]==dpt[y]==2가 됨
    for (int i = maxPower; i >= 0; i--) { 
        if (dpt[y] - dpt[x] >= (1 << i)) 
            y = ac[y][i];
    }
    if (x == y)return x; // x,y가 처음부터 같거나 위의 for문의 결과로 y가x와 같게 되었을때
    
    // 위의 for문 결과로 dpt[x]==dpt[y] 이고
    // ac[][i]가 루트노드를 넘어갈땐 0이므로 계산에 영향x
    // ac[x][i] 와 ac[y][i]가 달라지면 depth가 높은 ac부터 lca바로 전까지 아래부터 위로가면서 x와 y를 업데이트 함
    for (int i = maxPower; i >= 0; i--) {
        if (ac[x][i] != ac[y][i]) {
            x = ac[x][i];
            y = ac[y][i];
        }
    }
    return ac[x][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    int x,y;
    for (int i = 0; i < N-1; i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //dpt[0] = -1; // 루트노드의 depth를 0으로 설정하고 싶을때 사용하는 코드
    dfs(1, 0);

    cin>>M;
    while (M--) {
        cin>>x>>y;
        cout<<lca(x, y)<<'\n';
    }

}