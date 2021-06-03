#include<bits/stdc++.h>
#define MAX 500000
using namespace std;
using pii = pair<int,int>;

int N;
vector<pii> arr;
vector<pii> arr2;
vector<pii> ans;
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
    for(int i=1; i<=N; i++) {
        cin>>t;
        arr.push_back({t,i});
    }
    sort(arr.begin(), arr.end(), greater<pii>());
    
    for(int i=1; i<=N; i++){
        arr2.push_back({arr[i-1].second, i});
    }
    sort(arr2.begin(), arr2.end());

    for(int i=1; i<=N; i++){
        int next = arr2[i-1].second;
        update(next, 1);
        cout<<query(next-1) + 1<<' ';
    }

}