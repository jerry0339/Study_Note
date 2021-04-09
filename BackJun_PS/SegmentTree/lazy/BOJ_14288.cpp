// 회사문화4

#include<bits/stdc++.h>
#define MAX_N 100000
#define MAX 100000
using namespace std;
typedef long long ll;

ll N,M;
vector<ll> adj[MAX_N+1]{};
ll st[MAX_N+1]{}, ed[MAX_N+1]{};
ll downtree[MAX+1]{};
ll uptree[MAX+1]{};

ll query(ll arr[], ll idx){
	ll ret = 0;
	while(idx > 0){
		ret += arr[idx];
		idx -= (idx & -idx);	
	}
	return ret;
}
void update(ll arr[], ll idx, ll diff){
	while(idx < MAX+1){
		arr[idx] += diff;
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
    bool dir = true;
    while(M--){
        cin>>a;
        if(a==1) {
            cin>>b>>c;
            if(dir){ // 부하 칭찬
                update(downtree, st[b], c);
                update(downtree, ed[b]+1, -c);
            } else { // 상사칭찬 -> 상사b의 총 칭찬은 b의 부하들이 받은 칭찬의 총 합과 같으므로
                update(uptree, st[b], c);
            }
        } else if(a==2){
            cin>>b;
            ll x = query(downtree, st[b]);
            ll y = query(uptree, ed[b])-query(uptree, st[b]-1); // b와 부하직원 칭찬의 모든 합
            cout<<x+y<<'\n';
        } else {
            dir = !dir;
        }
    }
}