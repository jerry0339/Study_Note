#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
using pii = pair<int,int>;

int N;
int tree[MAX+1]{};

int query(int idx){
	int ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

void update(int idx, int diff){
	while(idx < MAX+1){
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int t;
    long long ans = 0;
    for(int i=1; i<=N; i++){
        cin>>t;
        update(t, 1);
        ans += i - query(t);
    }
    cout<<ans;
}