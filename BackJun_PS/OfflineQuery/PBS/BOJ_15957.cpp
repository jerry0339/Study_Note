#include<bits/stdc++.h>
#define MAX_N 100000
#define MAX_Q 100000
using namespace std;
using tpi = tuple<int,int,int>;
using ll = long long;

int N,Q;
ll J;
vector<int> adj[MAX_N+1]{};
vector<int> songs[MAX_N+1]{};
vector<tpi> qu;
int singer[MAX_N+1]{};
ll tree[MAX_N+1]{};
int in[MAX_N+1]{}, out[MAX_N+1]{};
int st[MAX_Q+1]{}, ed[MAX_Q+1]{};
int vi[MAX_N+1]{};
ll sAvg[MAX_N+1]{};

ll query(int idx){
	ll ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}
void update(int idx, ll diff){
	while(idx < MAX_N+1){
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

int num = 0;
void dfs(int now){
	in[now] = ++num;
	for(auto next : adj[now])
		dfs(next);
	out[now] = num;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>Q;
	cin>>J;
	int t;
	for(int i=2; i<=N; i++){
		cin>>t;
		adj[t].push_back(i);
	}
	dfs(1);
	for(int i=1; i<=N; i++){
		cin>>t;
		songs[t].push_back(i);
		singer[i] = t;
	}

	int T,P,S;
	qu.push_back({-1,-1,-1});
	for(int i=1; i<=Q; i++){
		cin>>T>>P>>S;
		qu.push_back({T,P,S});
	}
	sort(qu.begin(), qu.end());
	fill(st, st+N+1, 1);
	fill(ed, ed+N+1, Q);
	
	while(1){
		vector<vector<int>> pbs(Q+1);
		int maxMid = 0;
		for(int i=1; i<=N; i++){ // song
			if(st[i] <= ed[i]){
				int mid = (st[i] + ed[i])>>1;
				pbs[mid].push_back(i);
				maxMid = max(maxMid, mid);
			}	
		}
		if(maxMid==0) break;

		memset(tree,0,sizeof(tree));
		memset(vi,0,sizeof(vi));
		for(int q=1; q<=maxMid; q++){
			tie(T,P,S) = qu[q];
			S /= (out[P] - in[P] + 1);
			update(in[P], S);
			update(out[P]+1, -S);
			for(auto nsong : pbs[q]){
				int nsinger = singer[nsong];
				ll &avg = sAvg[nsinger];
				if(vi[nsinger] != q){
					vi[nsinger] = q;
					ll sum = 0;
					for(auto nsong : songs[nsinger]){
						sum += query(in[nsong]);
					}
					avg = sum / songs[nsinger].size();
					if(sum%songs[nsinger].size()!=0) avg++;
				}
		
				if(avg > J) ed[nsong] = q - 1;
				else st[nsong] = q + 1;
			}
		}
	}

	for(int i=1; i<=N; i++){
		int idx = st[i];
		if(idx > Q) cout<<-1<<'\n';
		else cout<<get<0>(qu[idx])<<'\n';
	}

}