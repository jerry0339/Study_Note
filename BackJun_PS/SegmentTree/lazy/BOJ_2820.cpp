// 자동차 공장 - BOJ_2820
// BIT , euler_tour_technique : 오일러 경로 테크닉

#include<bits/stdc++.h>
#define MAX_N 500000
#define MAX 500000
using namespace std;
typedef long long ll;

ll N,M;
ll arr[MAX_N+1]{};
vector<ll> adj[MAX_N+1]{};
ll st[MAX_N+1]{}, ed[MAX_N+1]{};
ll tree[MAX+1]{};

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
ll num = 1, last = 0;
void dfs(ll now){
    st[now] = num;
    update(st[now], arr[now]-last);
    last = arr[now];
    for(auto next : adj[now]){
        num++;
        dfs(next);
    }
    ed[now] = num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ll par;
    cin>>arr[1];
    for(ll i=2; i<=N; i++){
        cin>>arr[i]>>par;
        adj[par].push_back(i);
    }
    dfs(1);

    char ch;
    ll a,x;
    while(M--){
        cin>>ch;
        if(ch=='p') {
            cin>>a>>x;
            update(st[a]+1, x);
            update(ed[a]+1, -x);
        } else {
            cin>>a;
            cout<<query(st[a])<<'\n';
        }
    }
}