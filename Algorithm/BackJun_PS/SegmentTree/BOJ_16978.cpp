#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
using ll = long long;
using pil = pair<int,ll>;
using tpi = tuple<int,int,int>;

int N,Q;
ll arr[MAX+1]{};
ll tree[MAX+1]{};
vector<pil> qu1;
vector<tpi> qu2[MAX+1];
ll sum[MAX+1]{};

ll query(int idx){
	ll ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= (idx & -idx);	
	}
	return ret;
}
void update(int idx, ll diff){
	while(idx < MAX+1){
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for(int i=1; i<=N; i++){
        cin>>arr[i];
        update(i, arr[i]);
    }
	
	cin>>Q;
	int t,k,i,j, idx=0;
	ll v;
	while(Q--){
		cin>>t;
		if(t==1){
			cin>>i;
			cin>>v;
			qu1.push_back({i,v});
		} else {
			cin>>k>>i>>j;
			qu2[k].push_back({i,j,idx++});
		}
	}
	
	k=0;
	while(1){
		for(auto val : qu2[k]){
			tie(i,j,t) = val;
			sum[t] = query(j) - query(i-1);
		}
		if(k==qu1.size()) break;
		int nexti = qu1[k].first;
		ll nextv = qu1[k].second;
		update(nexti, nextv - arr[nexti]);
		arr[nexti] = nextv;
		k++;
	}

	for(i=0; i<idx; i++) cout<<sum[i]<<'\n';
}