//<2042 - 구간합> 
// -비재귀코드-
#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<n; i++)
using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    } 
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, k;
	cin>>n>>m>>k;
    vector<long long> arr(n);
	int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    m += k;
    rep(i, 0, n) cin>>arr[i];
    init(arr, tree, 1, 0, n-1);
    
    while(m--) {
        int a;
        cin>>a;
        if(a==1) {
            int b; long long c;
            cin>>b>>c;
            b--;
            long long diff = c-arr[b];
            arr[b] = c;
            update(tree, 1, 0, n-1, b, diff);
        } else if(a==2) {
            int b,c;
            cin>>b>>c;
            cout<< sum(tree, 1, 0, n-1, b-1, c-1) <<endl;
        }
    }
    
}