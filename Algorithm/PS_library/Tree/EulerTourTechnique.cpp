// 주식회사 승범이네 - BOJ_16404
// BIT , euler_tour_technique : 오일러 경로 테크닉

#include<bits/stdc++.h>
#define MAX_N 100000
#define MAX 100000
using namespace std;
typedef long long ll;

ll N,M;
vector<ll> adj[MAX_N+1]{};
ll st[MAX_N+1]{}, ed[MAX_N+1]{};
ll tree[MAX+1]{}; // 원소는 arr[i] - arr[i-1]이 됨

ll query(ll idx){
	ll ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= (idx & -idx);	
	}
	return ret;
}
void update(ll idx, ll diff){
	while(idx < MAX+1){
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

// 오일러 경로 테크닉 -> 트리에 번호를 붙여 BIT or SegTree에 사용
ll num = 0;
void dfs(ll now){
    st[now] = ++num;
    // 해당 문제는 입력시 i노드의 부모노드가 입력으로 주어졌으므로 next가 부모인지 체크x
    for(auto next : adj[now])
        dfs(next);
    
    ed[now] = num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ll t;
    cin>>t;
    for(ll i=2; i<=N; i++){
        cin>>t;
        adj[t].push_back(i);
    }
    dfs(1);

    ll a,b,c;
    while(M--){
        cin>>a>>b;
        if(a==1) {
            cin>>c;
            update(st[b], c);
            update(ed[b]+1, -c);
        } else {
            cout<<query(st[b])<<'\n';
        }
    }
}