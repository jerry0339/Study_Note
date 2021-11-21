// BOJ_2042
// BIT (fenwick) 풀이
// 점 update, 점 query
// 유효 인덱스 : [1,N]
// BIT는 구간query가 tree의 노드에 계산되어 있는것이 아니라 일부 부분query를 이용하여
// query, update를 계산함
// ex1) query(7) = tree[7(111)] + tree[6(110)] + tree[4(100)];
// ex2) [1,16], update(9, 10)-> tree[9(1001)], tree[10(1010)], tree[12(1100)], tree[16(10000)]에 각각 diff 더함

#include<bits/stdc++.h>
#define MAX_N 1000000
#define MAX 1000000
using namespace std;
typedef long long ll;

ll N,M,K;
ll arr[MAX_N+1]{};
ll tree[MAX+1]{};

// 비트연산 (idx & -idx) -> 가장 오른쪽에 있는 1비트

// query(i) -> [1,i] 까지의 합
// idx의 가장 오른쪽 1비트를 지워가면서 tree[i]를 모두 더함
// ex) query(7) = tree[7] + tree[6] + tree[4];
ll query(ll idx){
	ll ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

// update(i, diff) -> arr[i]에 diff를 더함
// arr[i]이 더해진 모든 tree[i]노드에 diff를 더해야 함
// idx의 가장 오른쪽 1비트에 1씩 더하면서 tree[i]의 값에 diff를 더함
// ex) [1,16]의 범위에서, 
// update(9, 10)-> tree[9(1001)], tree[10(1010)], tree[12(1100)], tree[16(10000)]에 각각 diff 더함
void update(ll idx, ll diff){
	while(idx < MAX+1){
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