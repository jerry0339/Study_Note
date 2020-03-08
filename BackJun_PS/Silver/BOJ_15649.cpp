// <N과 M> - 15649
// 백트래킹(DFS이용)

#include<bits/stdc++.h>
using namespace std;

int n,m;
bool vi[9];
char res[22];
// int res[9]로 하나하나 넣어서 출력하니까 시간이 더 오래걸려서 
// 정답코드보고 char형으로 문자열 한번에 출력하는것으로 시간 줄임

void dfs(int depth) {
    if(depth == m){ // depth가 0부터 이므로
        cout<<res<<'\n';
        return;
    }
    for(int i=1; i<=n; i++){
        if(vi[i]) continue; // 유망성 점검
        vi[i] = true;
        res[depth*2] = i+'0';
        res[depth*2 + 1] = ' ';
        dfs(depth+1);
        vi[i] = false; // 바로윗줄에서 다음depth를 다 확인했으니 현재 depth다시 확인하기 위해 현재 depth로 백트래킹
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    dfs(0);
}