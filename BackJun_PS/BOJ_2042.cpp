//<구간합 구하기> - 2042
// -backJun재귀코드-
// -세그먼트 트리 이용-
#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<n; i++)
using namespace std;


// 1. a: 배열 arr
// 2. tree: 세그먼트 트리
// 3. node: 세그먼트 트리 노드 번호
// 4. start/end : node가 담당하는 구간 -> leaf노드일 경우 start == end
// *node가 담당하는 합의 범위가 start ~ end
// *node 의 왼쪽 자식은 (node*2), 오른쪽 자식은 (node*2+1)
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    } 
}

// start~end : node가 담당하는 구간
// left~right : 구해야하는 합의 범위 
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) { // 1. start~end가 left~right범위밖 일때 (완전 불일치)
        return 0;
    }
    if (left <= start && end <= right) { // 2. start~end가 left~right범위안 일때 or 같을때 (재귀탈출)
        return tree[node];
    }
    // 3. 아래코드는 1,2 둘다 아닐경우 : start~end와 left~right가 부분적으로 겹침 -> 이진트리를 이용하여 반으로 나눔
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}


// index : 변경할 인덱스. 배열a의 인덱스. 즉 start~end와 비교해야함 (tree와 배열a의 index는 다른걸 숙지)
// diff : 변경시 변화량. 즉, diff = val - arr[index] (val은 a[index]가 변경될 수)
// *update함수 완료시 a[index]가 포함된 모든 노드에 diff(변화량)을 더해줌
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return; // 1. index가 start~end범위밖 일때
    tree[node] = tree[node] + diff; // 2. index가 start~end범위안 일때
    if (start != end) { // node가 리프노드가 아닐때
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
    // node가 리프노드면 재귀 빠져나옴
}


// n : 리프노드 개수 == 배열개수
// a == 1: b를 c로 update
// a == 2: b~c까지의 sum
// 트리의 높이(h) : Ceil(logN) -> N은 리프노드개수 (루트노드의 높이는 0임)
// 필요한 노드의 개수(tree_size) : 2*N - 1 -> N은 리프노드개수
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

//init함수로 생성되는 Segment Tree 이해하기
// node 의 왼쪽 자식은 (node*2), 오른쪽 자식은 (node*2+1)
/*
arr = {1,2,3,4,5} // n = (5) -> (3,2) -> {(2,1) , (1,1)}

       15
   6       9
 3   3   4   5
1 2 0 0 0 0 0 0

*/


/*
arr = {1,2,3,4,5,6} // n = (6) -> (3,3) -> {(2,1) , (2,1)}

       21
   6       15
 3   3   9   6
1 2 0 0 4 5 0 0

*/

/*
arr = {1,2,3,4,5,6,7} // n = (7) -> (4,3) -> {(2,2) , (2,1)} 

       28
   10      18
 3   7   11   7
1 2 3 4 5 6 0 0

*/