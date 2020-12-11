// <커피숍 2> - BOJ_1275
// 세그먼트 트리 (재귀 - 직관적임)

#include<bits/stdc++.h>
#define MAX_N 100000 // MAX값 확인
using namespace std;
typedef long long ll;

ll arr[MAX_N]{}, tree[MAX_N<<2]{};
ll N,Q;

ll init(ll n, ll s, ll e){
    if(s==e) return tree[n] = arr[s];
    ll mid = (s+e)>>1;
    // 재귀적으로 두 부분으로 나눈 뒤에 그 합을 자기 자신으로 함.
    return tree[n] = init(n<<1, s, mid) + init(n<<1|1, mid+1, e);
}

// s: 시작 인덱스, e: 끝 인덱스
// idx: 구간 합을 수정하고자 하는 노드
// diff: 수정할 값
void modify(ll n, ll s, ll e, ll idx, ll diff){
    // 범위 밖에 있는 경우
    if(idx<s || idx>e) return;
    // 범위 안에 있으면 내려가며 다른 원소도 갱신
    tree[n] += diff;
    if(s==e) return;
    ll mid = (s+e)>>1;
    modify(n<<1, s, mid, idx, diff);
    modify(n<<1|1, mid+1, e, idx, diff);
}

// s: 시작 인덱스, e: 끝 인덱스
// l, r: 구간 합을 구하고자 하는 범위
ll query(ll n, ll s, ll e, ll l, ll r){
    // 범위 밖에 있는 경우
    if(l>e || r<s) return 0;
    // 범위 안에 있는 경우
    if(l<=s && e<=r) return tree[n];
    // 그렇지 않다면 두 부분으로 나누어 합을 구하기
    ll mid = (s+e)>>1;
    return query(n<<1, s, mid, l, r) + query(n<<1|1, mid+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    // 인덱싱은 0부터 안해도 됨.
    // [1, N] 과 같이 인덱싱이 가능
    for(ll i=0; i<N; i++){
        cin>>arr[i];
    }
    init(1,0,N-1);

    ll x,y,a;
    ll b;
    while(Q--){
        cin>>x>>y>>a;
        cin>>b;
        if(x>y) swap(x,y);
        ll diff = b - arr[a-1];
        arr[a-1] = b;
        cout<<query(1, 0, N-1, x-1, y-1)<<'\n';
        modify(1, 0, N-1, a-1, diff);
    }

    return 0;
}