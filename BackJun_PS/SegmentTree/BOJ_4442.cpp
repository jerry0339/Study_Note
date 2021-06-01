#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int N;
map<string,int> m;
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
    while(cin>>N){
        if(!N) break;
        memset(tree,0,sizeof(tree));
        m.clear();
        string str;
        for(int i=1; i<=N; i++){
            cin>>str;
            m[str] = i;
        }

        ll res = 0;
        for(int i=1; i<=N; i++){
            cin>>str;
            int next = m[str];
            update(next, 1);
            res += (query(N) - query(next));
        }

        cout<<res<<'\n';
    }
}