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

ll num = 0;
void dfs(ll now){
    st[now] = ++num;
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
    bool dir = false;
    while(M--){
        cin>>a;
        if(a==1) {
            cin>>b>>c;
            update(st[b], c);
        } else {
            cin>>b;
            cout<<query(ed[b])-query(st[b]-1)<<'\n';
        }
    }
}