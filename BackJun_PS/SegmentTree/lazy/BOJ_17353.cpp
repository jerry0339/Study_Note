#include<bits/stdc++.h>
#define MAX_N 100000
#define MAX 100000
using namespace std;
typedef long long ll;

int N,Q;
ll arr[MAX_N+1]{};
ll tree[MAX+1]{};
ll cnt[MAX+1]{};

ll query(ll t[], int idx){
	ll ret = 0;
	while(idx > 0){
		ret += t[idx];
		idx -= (idx & -idx);	
	}
	return ret;
}
void update(ll t[], int idx, ll diff){
	while(idx < MAX+1){
		t[idx] += diff;
		idx += (idx & -idx);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
    ll last = 0;
	for(int i=1; i<=N; ++i) cin>>arr[i];
	
	cin>>Q;
	while(Q--){
		int a,b,c;
		cin >> a;
		if(a == 1){
			cin>>b>>c;
			update(tree, b, b);
			update(tree, c+1, -b);
			update(cnt, b, 1);
			update(cnt, c+1, -1);
		} else {
			cin>>b;
			ll x = (b+1) * query(cnt, b);
			ll y = query(tree, b);
			cout<<x-y+arr[b]<<'\n';
		}
	}
}