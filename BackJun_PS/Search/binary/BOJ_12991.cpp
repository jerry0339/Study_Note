// <홍준이의 행렬> - BOJ_12991
// 이분탐색

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
ll A[30010]{}, B[30010]{};
ll isP(ll chk){
    ll cnt=0;
    for(ll i=0; i<N; i++){
        ll s=0,e=N-1,mid;
        while(s<=e){
            mid = (s+e)/2;
            if(A[i]*B[mid]<=chk) s = mid + 1;
            else                 e = mid - 1;
        }
        cnt += s;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=0; i<N; i++) cin>>A[i];
    for(int i=0; i<N; i++) cin>>B[i];
    sort(A,A+N);
    sort(B,B+N);

    ll s=A[0]*B[0], e=A[N-1]*B[N-1], mid;
    while(s<=e) {
        mid = (s+e)/2;
        if(isP(mid)<K) s = mid + 1;
        else           e = mid - 1;
    }
    cout<<s;
}