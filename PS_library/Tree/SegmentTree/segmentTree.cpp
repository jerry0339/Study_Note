// <커피숍 2> - BOJ_1275
// 세그먼트 트리 (재귀)

// [Classic Segment Tree](http://codeforces.com/blog/entry/15890)
// [Efficient Segment Tree](http://codeforces.com/blog/entry/18051)
// [Data Structures](http://codeforces.com/blog/entry/15729)

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
	int N, Q;
	cin>>N>>Q;
    vector<long long> arr(N);
	int h = (int)ceil(log2(N));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    for(int i=0; i<N; i++) cin>>arr[i];
    init(arr, tree, 1, 0, N-1);
    while(Q--) {
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        if(x>y) {
            long long t = x;
            x = y;
            y = t;
        }
        cout<<sum(tree, 1, 0, N-1, x-1, y-1)<<'\n';
        a--;
        long long diff = b-arr[a];
        arr[a] = b;
        update(tree, 1, 0, N-1, a, diff);
    }
    
}