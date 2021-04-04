// BOJ_2042
// BIT (fenwick) 풀이
// 유효 인덱스 : [1,N]

#include<bits/stdc++.h>
#define MAX_N 1000001
#define MAX 1000001
using namespace std;
typedef long long ll;

ll N,M,K;
ll arr[MAX_N]{};
ll tree[MAX]{};

ll query(ll idx){
	ll ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

void update(ll idx, ll diff){
	while(idx < N){
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(ll i=1; i<=N; i++){
        cin>>arr[i];
        update(i,arr[i]);
    }

    ll Q,a,b,c;
    Q = M+K;
    while(Q--){
        cin>>a>>b>>c;
        if(a==1) {
            update(b, c - arr[b]);
            arr[b] = c;
        } else {
            cout<<query(c)-query(b-1)<<'\n';
        }
    }

}