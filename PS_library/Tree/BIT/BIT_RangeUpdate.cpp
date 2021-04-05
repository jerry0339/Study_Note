// BOJ_16975
// 펜윅 range_update
// 구간 update, 점 query

#include<bits/stdc++.h>
#define MAX_N 100000
#define MAX 100000
using namespace std;
typedef long long ll;

int N,Q;
ll arr[MAX_N+1]{};
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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
    ll last = 0;
	for(int i=1; i<=N; ++i){
        cin >> arr[i];
        update(i, arr[i]-last);
        last = arr[i];
    }
	
	cin>>Q;
	while(Q--){
		int a,b,c,d;
		cin >> a;
		if(a == 1){
			cin >> b >> c >> d;
			// 구간 업데이트
			update(b, d);
			update(c+1, -d);
		} else {
			cin >> b;
			// 점 쿼리(구간 업데이트가 된)
			cout << query(b) << '\n';
		}
	}
}