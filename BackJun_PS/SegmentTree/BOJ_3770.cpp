#include<bits/stdc++.h>
#define MAX_N 1000
#define MAX 1000
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int T,N,M,K;
vector<pii> qu;
ll tree[MAX+1]{};

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int i=1; i<=T; i++){
        cin>>N>>M>>K;
        qu.clear();
        memset(tree,0,sizeof(tree));
        int a,b;
        for(int i=0; i<K; i++){
            cin>>a>>b;
            qu.push_back({a,b});
        }
        sort(qu.begin(), qu.end());
        ll res = 0;
        for(auto v : qu){
            int next = v.second;
            update(next, 1);
            res += (query(M) - query(next));
        }

        cout<<"Test case "<<i<<": "<<res<<'\n';
    }
}