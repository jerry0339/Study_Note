
// <순열> - BOJ_1849 코드
// 순서 구할때 쓰는 세그 query

// ex) 사탕의 맛 1~100까지 있을때, 
//     3번째로 맛있는 사탕 빼기, 20의맛의 사탕 5개 넣기
//      -> BOJ_2243 사탕상자 문제 참고

#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;

int N;
int arr[MAX]{}, m[MAX]{};
int tree[MAX<<2]{};

int init(int n, int s, int e){
    if(s==e) return tree[n] = arr[s];
    int mid = (s+e)>>1;
    return tree[n] = init(n<<1, s, mid) + init(n<<1|1, mid+1, e);
}

void modify(int n, int s, int e, int idx, int diff){
    if(idx<s || idx>e) return;
    tree[n] += diff;
    if(s==e) return;
    int mid = (s+e)>>1;
    modify(n<<1, s, mid, idx, diff);
    modify(n<<1|1, mid+1, e, idx, diff);
}

// 인덱스로 반환
int query(int n, int s, int e, int val){
    if(s==e) return s;
    int mid = (s+e)>>1;
    int next = tree[n<<1];
    if(val <= next) return query(n<<1, s, mid, val);
    return query(n<<1|1, mid+1, e, val-next);
}

// 인덱스로 반환
// query1 이랑 달리 modify(n,s,e,idx, -1) 까지 적용 -> 순서 찾으면서 -1까지 업뎃
int query2(int n, int s, int e, int val){
    tree[n]--;
    if(s==e) return s;
    int mid = (s+e)>>1;
    if(val<=tree[n<<1]) return query2(n<<1, s, mid, val);
    return query2(n<<1|1, mid+1, e, val-tree[n<<1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i=1; i<=N; i++) cin>>m[i];
    for(int i=1; i<=N; i++) arr[i] = 1;
    init(1,1,N);

    for(int i=1; i<=N; i++){
        int t = query(1,1,N, m[i]+1);
        modify(1,1,N, t, -1);
        arr[t] = i;
    }

    for(int i=1; i<=N; i++) cout<<arr[i]<<' ';
}