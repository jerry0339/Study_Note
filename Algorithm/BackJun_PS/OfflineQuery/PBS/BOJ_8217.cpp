// 8217 유성
// PBS, BIT

#include<bits/stdc++.h>
#define MAX 300000
using namespace std;
typedef long long ll;

struct Query{
	ll a,b,c;
	Query(ll a, ll b, ll c): a(a), b(b), c(c) {}
};

ll N,M,Q;
vector<ll> adj[MAX+1]{};
vector<ll> midStk[MAX+1]{};
vector<Query> qu;
ll needs[MAX+1]{};
ll tree[MAX+1]{};
ll st[MAX+1]{}, ed[MAX+1]{};

ll pointQuery(ll idx){
	ll ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= (idx & -idx);	
	}
	return ret;
}
void update(ll idx, ll diff){
	while(idx <= M){
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

void updateAll(ll a, ll b, ll c){
	if(a<=b){
		update(a,c);
		update(b+1LL,-c);
	} else {
		update(1,c);
		update(b+1LL,-c);
		update(a,c);
		update(M+1LL,-c);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	ll t;
	for(ll i=1; i<=M; ++i){
        cin >> t;
		adj[t].push_back(i);
    }
	for(ll i=1; i<=N; i++){
		cin>>needs[i];
	}
	
	cin>>Q;
	ll a,b,c;
	for(ll i=1; i<=N; i++) ed[i] = Q-1LL;
	for(ll i=0; i<Q; i++){
		cin>>a>>b>>c;
		qu.push_back(Query(a,b,c));
	}
	
	while(1){
		memset(tree,0,sizeof(tree));
		for(ll i=0; i<Q; i++) midStk[i].clear();
		ll cnt = 0;
		for(ll i=1; i<=N; i++) {
			if(st[i]<=ed[i]){
				ll mid = (st[i]+ed[i])>>1;
				midStk[mid].push_back(i);
				cnt=1;
			}
		}
		if(cnt==0) break;
		
		for(ll i=0; i<Q; i++){
			//if(cnt==0) break;
			updateAll(qu[i].a, qu[i].b, qu[i].c);
			for(auto num : midStk[i]){
				ll sum = 0;
				for(auto val : adj[num]){
					sum += pointQuery(val);
					if(sum >= needs[num]) break;
				}
				if(sum >= needs[num])
					ed[num] = i - 1LL;
				else 
					st[num] = i + 1LL;
				//cnt--;
			}
		}
	}

	for(ll i=1; i<=N; i++){
		if(st[i]==Q) cout<<"NIE"<<'\n';
		else cout<<st[i]+1LL<<'\n';
	}
}